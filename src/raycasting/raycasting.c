/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 11:57:45 by nsabia            #+#    #+#             */
/*   Updated: 2024/10/20 19:33:37 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	num_check(float angle)
{
	if (angle < 0)
		angle += (2 * M_PI);
	if (angle > (2 * M_PI))
		angle -= (2 * M_PI);
	return (angle);
}

void    init_raycasting(t_mlx *mlx)
{
    double  half_fov;
    half_fov = (FOV * M_PI / 180) / 2;
    mlx->ply->ply_y_coord = (mlx->parse->ply_y_pos_in_map) * TILE_SIZE
        + TILE_SIZE / 2;
    mlx->ply->ply_x_coord = (mlx->parse->ply_x_pos_in_map) * TILE_SIZE
        + TILE_SIZE / 2;
    mlx->ply->most_left_angle = num_check(mlx->ply->center_angle
            - half_fov);
    mlx->ply->most_right_angle = num_check(mlx->ply->center_angle
            + half_fov);
}

int	unit_circle(float angle, char c)
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

int	wall_hit(float x, float y, t_mlx *mlx)
{
	int	x_m;
	int	y_m;

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

void	raycasting(t_mlx *mlx)
{
	double	h_inter;
	double	v_inter;

	mlx->ray->ray_counter = 0;
	mlx->ray->main_ray = mlx->ply->most_left_angle;
	mlx->ply->fov_rd = (FOV * M_PI / 180);
	mlx->ray->no_or_so_wallhit_flag = false;
	while (mlx->ray->ray_counter < RAY_LIMIT)
	{
		double ray_angle = num_check(mlx->ray->main_ray);
		h_inter = get_y_inter(mlx, ray_angle);
		v_inter = get_x_inter(mlx, ray_angle);
		if (v_inter <= h_inter)
			mlx->ray->distance_to_w = v_inter;
		else
		{
			mlx->ray->distance_to_w = h_inter;
			mlx->ray->no_or_so_wallhit_flag = true;
		}
		// Fish-eye correction
		double angle_diff = ray_angle - mlx->ply->center_angle;
		mlx->ray->distance_to_w *= cos(angle_diff);

		// Wall height calculation based on distance
		calculate_wall_hight(mlx);

		mlx->ray->no_or_so_wallhit_flag = false;
		mlx->ray->ray_counter++;
		mlx->ray->main_ray += (mlx->ply->fov_rd / RAY_LIMIT);
	}
}
