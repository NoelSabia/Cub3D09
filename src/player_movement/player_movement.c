/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 17:03:53 by nsabia            #+#    #+#             */
/*   Updated: 2024/08/23 17:04:49 by nsabia           ###   ########.fr       */
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

void	keyhook_organizer(mlx_key_data_t keydata, void *mlx_copy)
{
	t_mlx	*mlx;

	mlx = mlx_copy;
	esc_key(keydata);
	// walk_around(keydata, mlx);
	// look_left(keydata, mlx);
	// look_right(keydata, mlx);
}
