/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 11:57:41 by nsabia            #+#    #+#             */
/*   Updated: 2024/09/05 15:59:18 by nsabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
int	ft_abs(int num);

void put_block(t_mlx *mlx, int i, int j)
{
	int		i_end;
	int		j_end;
	int		j_zero;

	j_zero = j;
	i_end = i + TILE_SIZE;
	j_end = j + TILE_SIZE;
	while (i < i_end)
	{
		while (j < j_end)
		{
			mlx_put_pixel(mlx->ray->minimap, i, j, 0xFFFFFFFF);
			j++;
		}
		j = j_zero;
		i++;
	}
}

void draw_walls(t_mlx *mlx)
{
    int i;
    int j;

    i = 0;
    while (i < mlx->parse->cols)
    {
        j = 0;
        while (j < mlx->parse->rows)
        {
            if (mlx->parse->map[i][j] == '1')
            {
                put_block(mlx, j * TILE_SIZE, i * TILE_SIZE);
            }
            j++;
        }
        i++;
    }
}

void draw_player (t_mlx *mlx)
{
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->ply_x_coord, mlx->ply->ply_y_coord, 0x00FF00FF);
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->ply_x_coord + 1, mlx->ply->ply_y_coord, 0x00FF00FF);
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->ply_x_coord + 2, mlx->ply->ply_y_coord, 0x00FF00FF);
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->ply_x_coord - 1, mlx->ply->ply_y_coord, 0x00FF00FF);
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->ply_x_coord - 2, mlx->ply->ply_y_coord, 0x00FF00FF);
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->ply_x_coord, mlx->ply->ply_y_coord + 1, 0x00FF00FF);
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->ply_x_coord, mlx->ply->ply_y_coord - 1, 0x00FF00FF);
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->ply_x_coord, mlx->ply->ply_y_coord + 2, 0x00FF00FF);
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->ply_x_coord, mlx->ply->ply_y_coord - 2, 0x00FF00FF);
}

void draw_vert (t_mlx *mlx)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	j = 1;
	while (k < (mlx->parse->rows))
	{
		while (i < TILE_SIZE * (mlx->parse->cols))
		{
			mlx_put_pixel(mlx->ray->minimap, TILE_SIZE*j, i, 0xFFFFFFFF);
			i++;
		}
		i = 0;
		j++;
		k++;
	}
}

void draw_horiz (t_mlx *mlx)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	j = 1;
	while (k < (mlx->parse->cols))
	{
		while (i < TILE_SIZE * (mlx->parse->rows))
		{
			mlx_put_pixel(mlx->ray->minimap, i, TILE_SIZE * j, 0xFFFFFFFF);
			i++;
		}
		i = 0;
		j++;
		k++;
	}
}

void	minimap_draw_line(t_mlx *mlx, float x_coord, float y_coord)
{
	int dx;
    int dy;
    int sx;
    int sy;
    int err;
    int e2;

    dx = ft_abs((int)x_coord - mlx->ply->ply_x_coord);
    dy = ft_abs((int)y_coord - mlx->ply->ply_y_coord);
	sx = (mlx->ply->ply_x_coord < (int)x_coord) ? 1 : -1;
	sy = (mlx->ply->ply_y_coord < (int)y_coord) ? -1 : 1;
    err = dx - dy;
    while (1)
	{
		if ((mlx->ply->ply_x_coord > 0 && mlx->ply->ply_x_coord < SCREEN_WIDTH) && (mlx->ply->ply_y_coord > 0 && mlx->ply->ply_y_coord < SCREEN_HEIGHT))
			mlx_put_pixel(mlx->ray->minimap, mlx->ply->ply_x_coord, mlx->ply->ply_y_coord, 0x00FF00FF);
		// printf("x: %d y: %d\n", mlx->ply->ply_x_coord, mlx->ply->ply_y_coord);
		if (mlx->ply->ply_x_coord == (int)x_coord
            && mlx->ply->ply_y_coord == (int)y_coord)
			break;
        e2 = err * 2;
        if (e2 > -dy)
		{
            err -= dy;
            mlx->ply->ply_x_coord += sx;
        }
        if (e2 < dx)
		{
            err += dx;
            mlx->ply->ply_y_coord -= sy;
        }
    }
}

void	minimap_draw(t_mlx *mlx)
{
	//This just draws horizontal and vertical lines
	draw_vert(mlx);
	draw_horiz(mlx);
	
	//This draws the walls (so fills the squares from the lines) and draws the player
	draw_walls(mlx);
	draw_player(mlx);

	//This function can be useful for the raycasting
	//First param: mlx, Second param: x_coordinate, Third param: y_coordinate
	// minimap_draw_line(mlx, 100, 100);

	//raycasting
	// raycasting(mlx);
}
