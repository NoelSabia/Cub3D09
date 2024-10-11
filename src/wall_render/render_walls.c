/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:37:23 by nsabia            #+#    #+#             */
/*   Updated: 2024/10/11 13:19:24 by nsabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

mlx_texture_t *get_texture(t_mlx *mlx)
{
    if (mlx->ray->no_or_so_wallhit_flag == true)
    {
        if (mlx->ray->main_ray > 0 && mlx->ray->main_ray < M_PI)
			return (mlx->parse->south_tex);
		else
			return (mlx->parse->north_tex);
    }
    else
    {
        if (mlx->ray->main_ray > M_PI / 2 && mlx->ray->main_ray < 3 * (M_PI / 2))
			return (mlx->parse->west_tex);
		else
			return (mlx->parse->east_tex);
    }
}

u_int8_t	reverse_bytes(u_int8_t c)
{
	u_int8_t	b;

	b = 0;
	b |= (c & 0xFF) << 24;
	b |= (c & 0xFF00) << 8;
	b |= (c & 0xFF0000) >> 8;
	b |= (c & 0xFF000000) >> 24;
	return (b);
}

void	draw_wall(t_mlx *mlx, int bottom_end_of_wall, int top_end_of_wall, int wall_h)
{
	static int		i;
	int				x_start;
	int				x_end;
	int				bottom_tmp;
	double			x_o;
	double			y_o;
	mlx_texture_t	*texture;
	uint32_t		*arr;
	double			factor;

	x_start = i * WALL_SLICE_WIDTH;
	x_end = i * WALL_SLICE_WIDTH + WALL_SLICE_WIDTH;
	bottom_tmp = bottom_end_of_wall--;
	texture = get_texture(mlx);
	arr = (uint32_t *)texture->pixels;
	factor = (double)texture->height / wall_h;
	x_o = mlx->ray->no_or_so_wallhit_flag ? (int)fmodf((mlx->ray->horiz_x * (texture->width / TILE_SIZE)), texture->width) : (int)fmodf((mlx->ray->vert_y * (texture->width / TILE_SIZE)), texture->width);
	y_o = (top_end_of_wall - (SCREEN_HEIGHT / 2) + (wall_h / 2)) * factor;
	if (y_o < 0)
		y_o = 0;
	while (x_start <= x_end)
	{
		while (bottom_tmp <= top_end_of_wall)
		{
			bottom_tmp++;
			if (x_start < 0 || x_start > 1920 - 1)
				continue ;
			else if (bottom_tmp < 0 || bottom_tmp > 1080 - 1)
				continue ;
			printf("y_o: %d\n", (int)y_o);
			printf("x_o: %d\n", (int)x_o);
			printf("width: %d\n", texture->width);
			mlx_put_pixel(mlx->img, x_start, bottom_tmp, reverse_bytes(arr[(int)y_o * texture->width + (int)x_o]));
			y_o += factor;
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
	draw_wall(mlx, bottom_end, top_end, wall_height);
}
