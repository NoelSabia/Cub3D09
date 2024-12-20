/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 17:03:53 by nsabia            #+#    #+#             */
/*   Updated: 2024/10/21 10:04:18 by nsabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	int		new_x;
	int		new_y;

	new_x = round(mlx->ply->ply_x_coord + new_x_pos);
	new_y = round(mlx->ply->ply_y_coord + new_y_pos);
	if (val_ply_pos(new_y - 10, new_x, mlx)
		&& val_ply_pos(new_y + 10, new_x, mlx)
		&& val_ply_pos(new_y, new_x + 10, mlx)
		&& val_ply_pos(new_y, new_x - 10, mlx)
		&& val_ply_pos(new_y, new_x, mlx))
	{
		mlx->ply->ply_x_coord = new_x;
		mlx->ply->ply_y_coord = new_y;
	}
	else if (y_move_check(new_y, mlx->ply->ply_x_coord, mlx))
		mlx->ply->ply_y_coord = new_y;
	else if (x_move_check(mlx->ply->ply_y_coord, new_x, mlx))
		mlx->ply->ply_x_coord = new_x;
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

void	look_left(mlx_key_data_t keydata, t_mlx *mlx)
{
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		mlx->ply->looking_left = true;
	are_keys_released(keydata, mlx);
}

void	look_right(mlx_key_data_t keydata, t_mlx *mlx)
{
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		mlx->ply->looking_right = true;
	are_keys_released(keydata, mlx);
}
