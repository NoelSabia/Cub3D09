/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:37:23 by nsabia            #+#    #+#             */
/*   Updated: 2024/10/11 20:23:21 by nsabia           ###   ########.fr       */
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

int	reverse_bytes(int c)
{
	int	b;

	// printf("c: %d\n", c);
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
	double			x_tex;
	double			y_tex;
	mlx_texture_t	*texture;
	uint32_t		*arr;
	double			factor;

	x_start = i * WALL_SLICE_WIDTH;
	x_end = i * WALL_SLICE_WIDTH + WALL_SLICE_WIDTH;
	bottom_tmp = bottom_end_of_wall--;
	texture = get_texture(mlx);
	arr = (uint32_t *)texture->pixels;
	factor = (double)texture->height / wall_h;
	x_tex = mlx->ray->no_or_so_wallhit_flag ? (int)fmodf((mlx->ray->horiz_x * (texture->width / TILE_SIZE)), texture->width) : (int)fmodf((mlx->ray->vert_y * (texture->width / TILE_SIZE)), texture->width);
	y_tex = (bottom_end_of_wall - (SCREEN_HEIGHT / 2) + (wall_h / 2)) * factor;
	// printf("var1: %d\n", bottom_end_of_wall);
	// printf("w_h: %d\n", wall_h);
	// printf("factor: %f\n", factor);
	if (y_tex < 0)
		y_tex = 0;
	while (x_start <= x_end)
	{
		while (bottom_tmp <= top_end_of_wall)
		{
			bottom_tmp++;
			if (x_start < 0 || x_start > 1920 - 1)
				continue ;
			else if (y_tex < 0 || y_tex > 1080 - 1)
				continue ;
			// printf("here: %d\n", (int)y_tex);
			// printf("x_tex: %d\n", (int)x_tex);
			// printf("width: %d\n", texture->width);
			if ((int)y_tex * texture->width + (int)x_tex < texture->width * texture->height)
				mlx_put_pixel(mlx->img, x_start, bottom_tmp, reverse_bytes(arr[(int)y_tex * texture->width + (int)x_tex]));
			y_tex += factor; //factor is doing some weird bullshit!!!!!!
			// printf("y_tex: %f\n", y_tex);
		}
		bottom_tmp = bottom_end_of_wall;
		x_start++;
	}
	i++;
	if (i == RAY_LIMIT)
		i = 0;
	// exit(0);
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
