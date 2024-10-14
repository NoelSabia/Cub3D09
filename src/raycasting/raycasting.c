/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 11:57:45 by nsabia            #+#    #+#             */
/*   Updated: 2024/10/11 20:57:58 by nsabia           ###   ########.fr       */
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

int	unit_circle(float angle, bool horizontal)
{
	if (horizontal)
	{
		if (angle > 0 && angle < M_PI)
			return (1);
	}
	else if (!horizontal)
	{
		if (angle > (M_PI / 2) && angle < (3 * M_PI) / 2)
			return (1);
	}
	return (0);
}

int	wall_hit(float player_x, float player_y, t_mlx *mlx)
{
	int	map_x;
	int	map_y;

	if (player_x < 0 || player_y < 0)
		return (0);
	map_x = floor(player_x / TILE_SIZE);
	map_y = floor(player_y / TILE_SIZE);
	if (((map_y >= mlx->parse->cols || map_x >= mlx->parse->rows) || 
		(mlx->parse->map[map_y] && map_x <= (int)strlen(mlx->parse->map[map_y]) && 
		mlx->parse->map[map_y][map_x] == '1')))
			return (0);
	return (1);
}


void	raycasting(t_mlx *mlx)
{
	double	x_inter;
	double	y_inter;

	mlx->ray->ray_counter = 0;
	mlx->ray->main_ray = mlx->ply->most_left_angle;
	mlx->ply->fov_rd = (FOV * M_PI / 180);
	mlx->ray->no_or_so_wallhit_flag = false;
	while (mlx->ray->ray_counter < RAY_LIMIT)
	{
		x_inter = get_y_inter(mlx, num_check(mlx->ray->main_ray));
		y_inter = get_x_inter(mlx, num_check(mlx->ray->main_ray));
		if (y_inter <= x_inter)
			mlx->ray->distance_to_w = y_inter;
		else
		{
			mlx->ray->distance_to_w = x_inter;
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
