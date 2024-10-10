/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 11:57:45 by nsabia            #+#    #+#             */
/*   Updated: 2024/10/10 02:10:10 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	minimap_draw_line(t_mlx *mlx, float x_coord, float y_coord);
int		minimap_dynamic_scale(t_mlx *mlx);
void     calculate_wall_hight(t_mlx *mlx);

float num_check(float angle)
{
    if (angle < 0)
        angle += (2 * M_PI);
    if (angle > (2 * M_PI))
        angle -= (2 * M_PI);
    return (angle);
}

void	init_raycasting(t_mlx *mlx)
{

	mlx->ply->ply_y_coord = (mlx->parse->ply_y_pos_in_map) * TILE_SIZE + TILE_SIZE / 2;
	mlx->ply->ply_x_coord = (mlx->parse->ply_x_pos_in_map) * TILE_SIZE + TILE_SIZE / 2;
	mlx->ply->most_left_angle = num_check(mlx->ply->center_angle - ((M_PI / 2) / 2));
    mlx->ply->most_right_angle = num_check(mlx->ply->center_angle + ((M_PI / 2) / 2));
}

int unit_circle(float angle, char c)
{
	if (c == 'x')
	{
		if (angle > 0 && angle < M_PI)
		return (1);
	}
	else if (c == 'y')
	{
		if (angle > (M_PI / 2) && angle < (3 * M_PI) / 2)
		return (1);
	}
	return (0);
}

int inter_check(float angle, float *inter, float *step, int is_horizon)
{
	if (is_horizon)
	{
		if (angle > 0 && angle < M_PI)
		{
			*inter += TILE_SIZE;
			return (-1);
		}
		*step *= -1;
	}
	else
	{
		if (!(angle > M_PI / 2 && angle < 3 * M_PI / 2)) 
		{
			*inter += TILE_SIZE;
			return (-1);
		}
		*step *= -1;
	}
	return (1);
}

int wall_hit(float x, float y, t_mlx *mlx)
{
	int  x_m;
	int  y_m;

	if (x < 0 || y < 0)
		return (0);
	x_m = floor (x / TILE_SIZE);
	y_m = floor (y / TILE_SIZE);
	if ((y_m >= mlx->parse->cols || x_m >= mlx->parse->rows))
		return (0);
	if (mlx->parse->map[y_m] && x_m <= (int)strlen(mlx->parse->map[y_m]))
		if (mlx->parse->map[y_m][x_m] == '1')
			return (0);
	return (1);
}

float get_y_inter(t_mlx *mlx, float angl)
{
	float h_x;
	float h_y;
	float x_step;
	float y_step;
	int  pixel;

	y_step = TILE_SIZE;
	x_step = TILE_SIZE / tan(angl);
	h_y = floor(mlx->ply->ply_y_coord / TILE_SIZE) * TILE_SIZE;
	pixel = inter_check(angl, &h_y, &y_step, 1);
	h_x = mlx->ply->ply_x_coord + (h_y - mlx->ply->ply_y_coord) / tan(angl);
	if ((unit_circle(angl, 'y') && x_step > 0) || (!unit_circle(angl, 'y') && x_step < 0))
		x_step *= -1;
	while (wall_hit(h_x, h_y - pixel, mlx))
	{
		h_x += x_step;
		h_y += y_step;
	}
	return (sqrt(pow(h_x - mlx->ply->ply_x_coord, 2) + pow(h_y - mlx->ply->ply_y_coord, 2)));
}

float get_x_inter(t_mlx *mlx, float angl)
{
	float v_x;
	float v_y;
	float x_step;
	float y_step;
	int  pixel;

	x_step = TILE_SIZE; 
	y_step = TILE_SIZE * tan(angl);
	v_x = floor(mlx->ply->ply_x_coord / TILE_SIZE) * TILE_SIZE;
	pixel = inter_check(angl, &v_x, &x_step, 0);
	v_y = mlx->ply->ply_y_coord + (v_x - mlx->ply->ply_x_coord) * tan(angl);
	if ((unit_circle(angl, 'x') && y_step < 0) || (!unit_circle(angl, 'x') && y_step > 0))
		y_step *= -1;
	while (wall_hit(v_x - pixel, v_y, mlx))
	{
		v_x += x_step;
		v_y += y_step;
	}
	return (sqrt(pow(v_x - mlx->ply->ply_x_coord, 2) + pow(v_y - mlx->ply->ply_y_coord, 2)));
}

void raycasting(t_mlx *mlx)
{
	double	h_inter;
	double	v_inter;
	int		ray;

	ray = 0;
	mlx->ray->main_ray = mlx->ply->most_left_angle;
	mlx->ply->fov_rd = (FOV * M_PI / 180);
	while (ray < RAY_LIMIT)
	{
		h_inter = get_y_inter(mlx, num_check(mlx->ray->main_ray));
		v_inter = get_x_inter(mlx, num_check(mlx->ray->main_ray));
		if (v_inter <= h_inter)
			mlx->ray->distance_to_w = v_inter;
		else
			mlx->ray->distance_to_w = h_inter;
		mlx->ray->distance_to_w *= cos(num_check(mlx->ray->main_ray - mlx->ply->center_angle));
	    calculate_wall_hight(mlx);
		ray++;
		mlx->ray->main_ray += (mlx->ply->fov_rd / RAY_LIMIT);
	}
}
