/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:37:23 by nsabia            #+#    #+#             */
/*   Updated: 2024/10/10 15:36:35 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_wall(t_mlx *mlx, int bottom_end_of_wall, int top_end_of_wall)
{
	static int	i;
	int			x_start;
	int			x_end;
	int			bottom_tmp;

	x_start = i * WALL_SLICE_WIDTH;
	x_end = i * WALL_SLICE_WIDTH + WALL_SLICE_WIDTH;
	bottom_tmp = bottom_end_of_wall--;
	while (x_start <= x_end)
	{
		while (bottom_tmp <= top_end_of_wall)
		{
			bottom_tmp++;
			if (x_start < 0 || x_start > 1920 - 1)
				continue ;
			else if (bottom_tmp < 0 || bottom_tmp > 1080 - 1)
				continue ;
			mlx_put_pixel(mlx->img, x_start, bottom_tmp, 0x0000ff);
		}
		bottom_tmp = bottom_end_of_wall;
		x_start++;
	}
	i++;
	if (i == 120)
		i = 0;
}

void	calculate_wall_hight(t_mlx *mlx)
{
	int	wall_height;
	int	bottom_end;
	int	top_end;

	wall_height = (TILE_SIZE / mlx->ray->distance_to_w)
		* ((SCREEN_HEIGHT / 2) / tan(1.047197551 / 2));
	bottom_end = SCREEN_HEIGHT / 2 - wall_height / 2;
	top_end = SCREEN_HEIGHT / 2 + wall_height / 2;
	if (bottom_end < 0)
		bottom_end = 0;
	else if (top_end >= SCREEN_HEIGHT)
		top_end = SCREEN_HEIGHT - 1;
	draw_wall(mlx, bottom_end, top_end);
}
