/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:37:23 by nsabia            #+#    #+#             */
/*   Updated: 2024/10/10 19:02:37 by tpaesch          ###   ########.fr       */
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

mlx_texture_t *get_texture(t_mlx *mlx)
{
	if (mlx->ray->no_or_so_wallhit_flag == true)
	{
		if (mlx->ray->main_ray > 0 && mlx->ray->main_ray < M_PI)
		{
			// printf("south\n");
			return (mlx->parse->south_tex);
		}
		else
		{
			// printf("north\n");
			return (mlx->parse->north_tex);
		}
	}
	else
	{
		if (mlx->ray->main_ray > M_PI / 2 && mlx->ray->main_ray < 3 * (M_PI / 2))
		{
			// printf("west\n");
			return (mlx->parse->west_tex);
		}
		else
		{
			// printf("east\n");
			return (mlx->parse->east_tex);
		}
	}
}

void	draw_textures(t_mlx *mlx)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	img = NULL;
	texture = get_texture(mlx);
	img = mlx_texture_to_image(mlx->mlx_p, texture);
	if (!img)
		clean_exit("MLX has problems to convert a textuer into an img, not our fault tho :)");
	if (mlx_image_to_window(mlx->mlx_p, img, 100, 100) < 0)
		clean_exit("Well...shit");
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
