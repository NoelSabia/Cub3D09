/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noel <noel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 17:03:53 by nsabia            #+#    #+#             */
/*   Updated: 2024/09/29 12:49:12 by noel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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

void	walk_around(mlx_key_data_t keydata, t_mlx *mlx)
{
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
	{
		mlx->ply->pressing_w = true;	
	}
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
	{
		mlx->ply->pressing_s = true;		
	}	
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
	{
		mlx->ply->pressing_a = true;	
	}
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
	{
		mlx->ply->pressing_d = true;	
	}
	are_keys_released(keydata, mlx);
}

void	look_left(mlx_key_data_t keydata, t_mlx *mlx)
{
	while (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
	{
		mlx->ply->looking_left = true;
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
	are_keys_released(keydata, mlx);
}

void	look_right(mlx_key_data_t keydata, t_mlx *mlx)
{
	while (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
	{
		mlx->ply->looking_right = true;
		mlx->ply->center_angle += ROTATION_SPEED;
		mlx->ply->center_angle += ROTATION_SPEED;
		mlx->ply->most_right_angle += ROTATION_SPEED;
		if (mlx->ply->center_angle > 2 * M_PI)
			mlx->ply->center_angle += 2 * M_PI;
		if (mlx->ply->most_left_angle > 2 * M_PI)
			mlx->ply->most_left_angle += 2 * M_PI;
		if (mlx->ply->most_right_angle > 2 * M_PI)
			mlx->ply->most_right_angle += 2 * M_PI;
	}
	are_keys_released(keydata, mlx);	
}

void	keyhook_organizer(mlx_key_data_t keydata, void *mlx_copy)
{
	t_mlx	*mlx;

	mlx = mlx_copy;
	// printf("roation_speed: %f\n", ROTATION_SPEED);
	// printf("looking_left: %s\n", mlx->ply->looking_left ? "true" : "false");
	// printf("most_left_angle: %f\n", mlx->ply->most_left_angle);
	// printf("middle_angle: %f\n", mlx->ply->center_angle);
	// printf("most_right_angle: %f\n", mlx->ply->most_right_angle);
	// printf("\n");
	esc_key(keydata);
	walk_around(keydata, mlx);
	look_left(keydata, mlx);
	look_right(keydata, mlx);
}
