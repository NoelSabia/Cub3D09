/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 11:57:45 by nsabia            #+#    #+#             */
/*   Updated: 2024/10/17 13:34:38 by tpaesch          ###   ########.fr       */
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

void	init_raycasting(t_mlx *mlx)
{
	mlx->ply->ply_y_coord = (mlx->parse->ply_y_pos_in_map) * TILE_SIZE
		+ TILE_SIZE / 2;
	mlx->ply->ply_x_coord = (mlx->parse->ply_x_pos_in_map) * TILE_SIZE
		+ TILE_SIZE / 2;
	mlx->ply->most_left_angle = num_check(mlx->ply->center_angle
			- ((M_PI / 2) / 2));
	mlx->ply->most_right_angle = num_check(mlx->ply->center_angle
			+ ((M_PI / 2) / 2));
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
	mlx->ply->fov_rd = (M_PI / 2);
	mlx->ray->no_or_so_wallhit_flag = false;
	while (mlx->ray->ray_counter < RAY_LIMIT)
	{
		h_inter = get_y_inter(mlx, num_check(mlx->ray->main_ray));
		v_inter = get_x_inter(mlx, num_check(mlx->ray->main_ray));
		if (v_inter <= h_inter)
			mlx->ray->distance_to_w = v_inter;
		else
		{
			mlx->ray->distance_to_w = h_inter;
			mlx->ray->no_or_so_wallhit_flag = true;
		}
		mlx->ray->distance_to_w *= cos(num_check(mlx->ray->main_ray
					- mlx->ply->center_angle));
		calculate_wall_hight(mlx);
		mlx->ray->no_or_so_wallhit_flag = false;
		mlx->ray->ray_counter++;
		mlx->ray->main_ray += (mlx->ply->fov_rd / RAY_LIMIT);
	}
}
