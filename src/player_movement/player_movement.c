/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 17:03:53 by nsabia            #+#    #+#             */
/*   Updated: 2024/10/08 13:45:39 by nsabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	esc_key(mlx_key_data_t keydata)
{
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		ft_free_all();
		exit (0);
	}
}

void	are_keys_released(mlx_key_data_t keydata, t_mlx *mlx)
{
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_RELEASE)
		mlx->ply->pressing_w = false;
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE)
		mlx->ply->pressing_s = false;
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE)
		mlx->ply->pressing_a = false;
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_RELEASE)
		mlx->ply->pressing_d = false;
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_RELEASE)
		mlx->ply->looking_left = false;
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_RELEASE)
		mlx->ply->looking_right = false;
}

void	update_player_view(t_mlx *mlx)
{
	if (mlx->ply->looking_left)
	{
		mlx->ply->most_left_angle -= ROTATION_SPEED;
		mlx->ply->center_angle -= ROTATION_SPEED;
		mlx->ply->most_right_angle -= ROTATION_SPEED;
		if (mlx->ply->center_angle < 0)
			mlx->ply->center_angle += 2 * M_PI;
		if (mlx->ply->most_left_angle < 0)
			mlx->ply->most_left_angle += 2 * M_PI;
		if (mlx->ply->most_right_angle < 0)
			mlx->ply->most_right_angle += 2 * M_PI;
	}
	if (mlx->ply->looking_right)
	{
		mlx->ply->most_left_angle += ROTATION_SPEED;
		mlx->ply->center_angle += ROTATION_SPEED;
		mlx->ply->most_right_angle += ROTATION_SPEED;
		if (mlx->ply->center_angle > 2 * M_PI)
			mlx->ply->center_angle -= 2 * M_PI;
		if (mlx->ply->most_left_angle > 2 * M_PI)
			mlx->ply->most_left_angle -= 2 * M_PI;
		if (mlx->ply->most_right_angle > 2 * M_PI)
			mlx->ply->most_right_angle -= 2 * M_PI;
	}
}

void	set_plyr_to_new_coords(t_mlx *mlx, double new_x_pos, double new_y_pos)
{
	int		map_grid_y;
	int		map_grid_x;
	int		new_x;
	int		new_y;

	new_x = round(mlx->ply->ply_x_coord + new_x_pos);
	new_y = round(mlx->ply->ply_y_coord + new_y_pos);
	map_grid_x = (new_x / TILE_SIZE);
	map_grid_y = (new_y / TILE_SIZE);
	if (mlx->parse->map[map_grid_y][map_grid_x] != '1' &&
	(mlx->parse->map[map_grid_y][mlx->ply->ply_x_coord / TILE_SIZE] != '1' &&
	mlx->parse->map[mlx->ply->ply_y_coord / TILE_SIZE][map_grid_x] != '1'))
	{
		mlx->ply->ply_x_coord = new_x;
		mlx->ply->ply_y_coord = new_y;
	}
}

void	update_player_position(t_mlx *mlx)
{
	double	new_x_pos;
	double	new_y_pos;

	new_x_pos = 0;
	new_y_pos = 0;
	if (mlx->ply->pressing_w)
		new_x_pos = cos(mlx->ply->center_angle) * MOVEMENT_SPEED;
	if (mlx->ply->pressing_w)
		new_y_pos = sin(mlx->ply->center_angle) * MOVEMENT_SPEED;
	if (mlx->ply->pressing_d)
	{
		new_x_pos = -sin(mlx->ply->center_angle) * MOVEMENT_SPEED;
		new_y_pos = cos(mlx->ply->center_angle) * MOVEMENT_SPEED;
	}
	if (mlx->ply->pressing_s)
	{
		new_x_pos = -cos(mlx->ply->center_angle) * MOVEMENT_SPEED;
		new_y_pos = -sin(mlx->ply->center_angle) * MOVEMENT_SPEED;
	}
	if (mlx->ply->pressing_a)
	{
		new_x_pos = sin(mlx->ply->center_angle) * MOVEMENT_SPEED;
		new_y_pos = -cos(mlx->ply->center_angle) * MOVEMENT_SPEED;
	}
	set_plyr_to_new_coords(mlx, new_x_pos, new_y_pos);
}

void	walk_around(mlx_key_data_t keydata, t_mlx *mlx)
{
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		mlx->ply->pressing_w = true;
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		mlx->ply->pressing_s = true;
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		mlx->ply->pressing_a = true;
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		mlx->ply->pressing_d = true;
	update_player_position(mlx);
	are_keys_released(keydata, mlx);
}

void	look_left(mlx_key_data_t keydata, t_mlx *mlx)
{
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		mlx->ply->looking_left = true;
	update_player_view(mlx);
	are_keys_released(keydata, mlx);
}

void	look_right(mlx_key_data_t keydata, t_mlx *mlx)
{
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		mlx->ply->looking_right = true;
	update_player_view(mlx);
	are_keys_released(keydata, mlx);
}

void	keyhook_organizer(mlx_key_data_t keydata, void *mlx_copy)
{
	t_mlx	*mlx;

	mlx = mlx_copy;
	esc_key(keydata);
	walk_around(keydata, mlx);
	look_left(keydata, mlx);
	look_right(keydata, mlx);
}
