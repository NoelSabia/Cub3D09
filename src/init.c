/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noel <noel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 16:48:34 by nsabia            #+#    #+#             */
/*   Updated: 2024/10/03 14:43:32 by noel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	init_values(t_mlx *mlx);
void	floor_and_ceiling_color(t_mlx *mlx);
void	keyhook_organizer(mlx_key_data_t keydata, void *mlx_copy);

void	displayFloorAndCeiling(t_mlx *mlx)
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

void	initWindow(t_mlx *mlx)
{
	mlx->mlx_p = mlx_init(SCREEN_WIDTH, SCREEN_HEIGHT, "Cub3D", 0);
	mlx->ray->minimap = mlx_new_image(mlx->mlx_p, TILE_SIZE*(mlx->parse->rows + 1), TILE_SIZE*(mlx->parse->cols + 1));
	mlx->img = mlx_new_image(mlx->mlx_p, SCREEN_WIDTH, SCREEN_HEIGHT);
	mlx_image_to_window(mlx->mlx_p, mlx->img, 0, 0);
	mlx_image_to_window(mlx->mlx_p, mlx->ray->minimap, 0, 0);
}

//this is just here for testing purposes! delete after testing passes
// float 	num_check(float angle);
// void    calculateWallHeight(t_mlx *mlx, double ray_pos);
// void	test_for_render_wall(t_mlx *mlx)
// {
// 	mlx->ray->distance_to_w = 20;
// 	for (int i = 0; i < RAY_LIMIT; i++)
// 	{
// 		mlx->ray->distance_to_w += i;
// 		calculateWallHeight(mlx, mlx->ray->main_ray);	
// 	}
// }
//until here u can delete everything.

void	game_loop(void *mlx_copy)
{
	t_mlx	*mlx;

	mlx = mlx_copy;
	// raycasting(mlx);
	ft_memset(mlx->ray->minimap->pixels, 0, mlx->ray->minimap->width * mlx->ray->minimap->height * 4);
    minimap_draw(mlx);
	// test_for_render_wall(mlx); //needs to be deleted because its just a test!
}

void	startGame(t_mlx *mlx)
{
	initWindow(mlx);
	initalizeRaycasting(mlx);
    displayFloorAndCeiling(mlx);
	mlx_loop_hook(mlx->mlx_p, &game_loop, mlx);
	mlx_key_hook(mlx->mlx_p, &keyhook_organizer, mlx);
	mlx_loop(mlx->mlx_p);
}
