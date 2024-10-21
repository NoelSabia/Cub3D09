/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 16:48:34 by nsabia            #+#    #+#             */
/*   Updated: 2024/10/21 16:08:57 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	floor_celing_display(t_mlx *mlx)
{
	int	x;
	int	y;

	y = 0;
	while (y < SCREEN_HEIGHT)
	{
		x = 0;
		while (x < SCREEN_WIDTH)
		{
			if (y <= SCREEN_HEIGHT / 2)
				mlx_put_pixel(mlx->img, x, y, mlx->parse->ceiling_color);
			else
				mlx_put_pixel(mlx->img, x, y, mlx->parse->floor_color);
			x++;
		}
		y++;
	}
}

void	init_window(t_mlx *mlx)
{
	mlx->mlx_p = mlx_init(SCREEN_WIDTH, SCREEN_HEIGHT, "Cub3D", 0);
	if (!mlx->mlx_p)
		clean_exit("MLX Instance failed to created\n");
	mlx->ray->minimap = mlx_new_image(mlx->mlx_p,
			TILE_SIZE * (mlx->parse->rows + 1),
			TILE_SIZE * (mlx->parse->cols + 1));
	if (!mlx->ray->minimap)
		clean_exit("Image for Minimap could not be created\n");
	mlx->img = mlx_new_image(mlx->mlx_p, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!mlx->img)
		clean_exit("Image for 3D Part could not be created\n");
	mlx_image_to_window(mlx->mlx_p, mlx->img, 0, 0);
	mlx_image_to_window(mlx->mlx_p, mlx->ray->minimap, 0, 0);
}

void	game_loop(void *mlx_copy)
{
	t_mlx	*mlx;

	mlx = mlx_copy;
	ft_memset(mlx->img->pixels, 0, mlx->img->width * mlx->img->height * 4);
	floor_celing_display(mlx);
	mlx->ray->ray_counter = 0;
	raycasting(mlx);
	ft_memset(mlx->ray->minimap->pixels, 0,
		mlx->ray->minimap->width * mlx->ray->minimap->height * 4);
	update_player_position(mlx);
	update_player_view(mlx);
	minimap_draw(mlx);
}

void	start_game(t_mlx *mlx)
{
	init_window(mlx);
	init_raycasting(mlx);
	floor_celing_display(mlx);
	mlx_loop_hook(mlx->mlx_p, &game_loop, mlx);
	mlx_key_hook(mlx->mlx_p, &keyhook_organizer, mlx);
	mlx_loop(mlx->mlx_p);
}
