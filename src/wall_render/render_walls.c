/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:37:23 by nsabia            #+#    #+#             */
/*   Updated: 2024/10/21 17:23:31 by nsabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	num_check(float angle);

mlx_texture_t	*get_texture(t_mlx *mlx)
{
	mlx->ray->main_ray = num_check(mlx->ray->main_ray);
	if (mlx->ray->no_or_so_wallhit_flag == true)
	{
		if (mlx->ray->main_ray > 0 && mlx->ray->main_ray < M_PI)
			return (mlx->parse->south_tex);
		else
			return (mlx->parse->north_tex);
	}
	else
	{
		if (mlx->ray->main_ray > M_PI / 2
			&& mlx->ray->main_ray < 3 * (M_PI / 2))
			return (mlx->parse->west_tex);
		else
			return (mlx->parse->east_tex);
	}
}

int	reverse_bytes(int c)
{
	int	b;

	b = 0;
	b |= (c & 0xFF) << 24;
	b |= (c & 0xFF00) << 8;
	b |= (c & 0xFF0000) >> 8;
	b |= (c & 0xFF000000) >> 24;
	return (b);
}

void	draw_wall(t_mlx *mlx, mlx_texture_t *texture,
	uint32_t *arr, int top_end_of_wall)
{
	while (mlx->ray->bottom_tmp <= top_end_of_wall)
	{
		mlx->ray->bottom_tmp++;
		if (mlx->ray->i < 0 || mlx->ray->i > SCREEN_WIDTH - 1)
			continue ;
		else if (mlx->ray->bottom_tmp < 0
			|| mlx->ray->bottom_tmp > SCREEN_HEIGHT - 1)
			continue ;
		if ((int)mlx->ray->y_tex * texture->width + (int)mlx->ray->x_tex
			< texture->width * texture->height)
			mlx_put_pixel(mlx->img, mlx->ray->i, mlx->ray->bottom_tmp,
				reverse_bytes(arr[(int)mlx->ray->y_tex
					* texture->width + (int)mlx->ray->x_tex]));
		mlx->ray->y_tex += mlx->ray->factor;
	}
}

void	prepare_drawing(t_mlx *mlx, int bottom_end_of_wall,
	int top_end_of_wall, int wall_h)
{
	mlx_texture_t	*texture;
	uint32_t		*arr;

	mlx->ray->bottom_tmp = bottom_end_of_wall--;
	texture = get_texture(mlx);
	arr = (uint32_t *)texture->pixels;
	mlx->ray->factor = (double)texture->height / wall_h;
	if (mlx->ray->no_or_so_wallhit_flag)
		mlx->ray->x_tex = (mlx->ray->horiz_x / TILE_SIZE)
			- floor(mlx->ray->horiz_x / TILE_SIZE);
	else
		mlx->ray->x_tex = (mlx->ray->vert_y / TILE_SIZE)
			- floor(mlx->ray->vert_y / TILE_SIZE);
	mlx->ray->x_tex *= texture->width;
	mlx->ray->y_tex = (bottom_end_of_wall - (SCREEN_HEIGHT / 2)
			+ (wall_h / 2)) * mlx->ray->factor;
	if (mlx->ray->y_tex < 0)
		mlx->ray->y_tex = 0;
	draw_wall(mlx, texture, arr, top_end_of_wall);
	mlx->ray->bottom_tmp = bottom_end_of_wall;
	mlx->ray->i++;
	if (mlx->ray->i == RAY_LIMIT)
		mlx->ray->i = 0;
}

void	calculate_wall_hight(t_mlx *mlx)
{
	int	wall_height;
	int	bottom_end;
	int	top_end;

	wall_height = (TILE_SIZE / mlx->ray->distance_to_w)
		* ((SCREEN_HEIGHT / 2) / tan(1.047197551 / 2));
	bottom_end = (SCREEN_HEIGHT / 2) - (wall_height / 2);
	top_end = (SCREEN_HEIGHT / 2) + (wall_height / 2);
	if (bottom_end < 0)
		bottom_end = 0;
	else if (top_end >= SCREEN_HEIGHT)
		top_end = SCREEN_HEIGHT - 1;
	prepare_drawing(mlx, bottom_end, top_end, wall_height);
}
