/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 11:57:45 by nsabia            #+#    #+#             */
/*   Updated: 2024/09/26 13:14:54 by nsabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	minimap_draw_line(t_mlx *mlx, float x_coord, float y_coord);
int		minimap_dynamic_scale(t_mlx *mlx);

float num_check(float angle)
{
    if (angle < 0)
        angle += (2 * M_PI);
    if (angle > (2 * M_PI))
        angle -= (2 * M_PI);
    return (angle);
}

void	raycasting_init(t_mlx *mlx)
{

	mlx->ply->ply_y_coord = (mlx->parse->ply_x_pos_in_map) * TILE_SIZE + TILE_SIZE / 2;
	mlx->ply->ply_x_coord = (mlx->parse->ply_y_pos_in_map) * TILE_SIZE + TILE_SIZE / 2;
	mlx->ply->most_left_angle = num_check(mlx->ply->player_angle - ((M_PI / 2) / 2));
    mlx->ply->most_right_angle = num_check(mlx->ply->player_angle + ((M_PI / 2) / 2));
}

bool	intersec_check(float main_ray_angle, float *intersec, float *step, bool is_horizontal)
{
	if (is_horizontal == true)
	{
		if (main_ray_angle > 0 && main_ray_angle < M_PI)
		{
			*intersec += TILE_SIZE;
			return (false);
		}
		*step *= -1;
	}
	if (is_horizontal == false)
	{
		if (!(main_ray_angle > (M_PI / 2) && main_ray_angle < (3 * M_PI) / 2))
		{
			*intersec += TILE_SIZE;
			return (false);
		}
		*step *= -1;
	}
	return (true);
}

bool	unit_circle(float main_ray_angle, bool horizontal)
{
	if (horizontal == true)
		if (main_ray_angle > 0 && main_ray_angle < M_PI)
			return (true);
	if (horizontal == false)
		if (main_ray_angle > (M_PI / 2) && main_ray_angle < (3 * M_PI) / 2)
			return (true);
	return (false);
}

bool	wall_hit(float x, float y, t_mlx *mlx)
{
	int  x_m;
	int  y_m;

	if (x < 0 || y < 0)
		return (false);
	x_m = floor (x / TILE_SIZE);
	y_m = floor (y / TILE_SIZE);
	if ((y_m >= mlx->parse->cols || x_m >= mlx->parse->rows))
		return (false);
	if (mlx->parse->map[y_m] && x_m <= (int)strlen(mlx->parse->map[y_m]))
		if (mlx->parse->map[y_m][x_m] == '1')
			return (false);
	return (true);
}

double	get_y_inter(t_mlx *mlx, double main_ray_angle)
{
	float	intersec_x;
	float	intersec_y;
	float	x_step;
	float	y_step;
	int		pixel;

	y_step = TILE_SIZE;
	x_step = TILE_SIZE / tan(main_ray_angle);
	intersec_y = floor(mlx->ply->ply_y_coord / TILE_SIZE) * TILE_SIZE; //does this even make sense?
	pixel = intersec_check(main_ray_angle, &intersec_y, &y_step, true);
	intersec_x = mlx->ply->ply_x_coord + (intersec_y - mlx->ply->ply_y_coord) / tan(main_ray_angle);
	if ((unit_circle(main_ray_angle, 'y') && x_step > 0) || (!unit_circle(main_ray_angle, 'y') && x_step < 0))
		x_step *= -1;
	while (wall_hit(intersec_x, intersec_y - pixel, mlx))
	{
		intersec_x += x_step;
		intersec_y += y_step;
	}
	return (sqrt(pow(intersec_x - mlx->ply->ply_x_coord, 2) + pow(intersec_y - mlx->ply->ply_y_coord, 2)));
}

double	get_x_inter(t_mlx *mlx, double main_ray_angle)
{
	float	intersec_x;
	float	intersec_y;
	float	x_step;
	float	y_step;
	int		pixel;

	x_step = TILE_SIZE;
	y_step = TILE_SIZE * tan(main_ray_angle);
	intersec_x = floor(mlx->ply->ply_x_coord / TILE_SIZE) * TILE_SIZE;
	pixel = intersec_check(main_ray_angle, &intersec_x, &x_step, false);
	intersec_y = mlx->ply->ply_y_coord + (intersec_x - mlx->ply->ply_x_coord) * tan(main_ray_angle);
	if ((unit_circle(main_ray_angle, 'x') && y_step < 0) || (!unit_circle(main_ray_angle, 'x') && y_step > 0))
    	y_step *= -1;
	while (wall_hit(intersec_x - pixel, intersec_y, mlx))
	{
		intersec_x += x_step;
		intersec_y += y_step;
	}
	return (sqrt(pow(intersec_x - mlx->ply->ply_x_coord, 2) + pow(intersec_y - mlx->ply->ply_y_coord, 2)));
}

void	raycasting(t_mlx *mlx)
{
	int		i;
	double	y_coord;
	double	x_coord;

	i = 0;
	mlx->ray->main_ray = mlx->ply->most_left_angle;
	//check if the iterations mess with the mainiterator (must fill out the fov of 90)
	while (i < RAY_LIMIT)
	{
		x_coord = get_x_inter(mlx, num_check(mlx->ray->main_ray));
		// y_coord = get_y_inter(mlx, num_check(mlx->ray->main_ray));
		// printf("x: %f y: %f main_ray: %f\n", x_coord, 0.0, mlx->ray->main_ray);
		i++;
		mlx->ray->main_ray = num_check(mlx->ray->main_ray + ((M_PI / 2) / RAY_LIMIT));
		minimap_draw_line(mlx, x_coord, y_coord);
	}
	exit(0);
}
