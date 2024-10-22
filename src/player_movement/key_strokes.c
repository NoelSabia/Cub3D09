/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_strokes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:28:24 by tpaesch           #+#    #+#             */
/*   Updated: 2024/10/22 17:58:11 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	esc_key(mlx_key_data_t keydata, t_mlx *mlx)
{
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		ft_free_all();
		if (mlx->parse->north_tex)
			mlx_delete_texture(mlx->parse->north_tex);
		if (mlx->parse->south_tex)
			mlx_delete_texture(mlx->parse->south_tex);
		if (mlx->parse->west_tex)
			mlx_delete_texture(mlx->parse->west_tex);
		if (mlx->parse->east_tex)
			mlx_delete_texture(mlx->parse->east_tex);
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
		mlx->ply->pressing_w = true;
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		mlx->ply->pressing_s = true;
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		mlx->ply->pressing_a = true;
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		mlx->ply->pressing_d = true;
	are_keys_released(keydata, mlx);
}

void	keyhook_organizer(mlx_key_data_t keydata, void *mlx_copy)
{
	t_mlx	*mlx;

	mlx = mlx_copy;
	esc_key(keydata, mlx);
	walk_around(keydata, mlx);
	look_left(keydata, mlx);
	look_right(keydata, mlx);
}
