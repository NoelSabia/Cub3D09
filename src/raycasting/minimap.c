/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 11:57:41 by nsabia            #+#    #+#             */
/*   Updated: 2024/09/02 12:34:52 by nsabia           ###   ########.fr       */
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
	i_end = i + 64;
	j_end = j + 64;
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
                put_block(mlx, j * 64, i * 64);
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
		while (i < 64 * (mlx->parse->cols))
		{
			mlx_put_pixel(mlx->ray->minimap, 64*j, i, 0xFFFFFFFF);
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
		while (i < 64 * (mlx->parse->rows))
		{
			mlx_put_pixel(mlx->ray->minimap, i, 64 * j, 0xFFFFFFFF);
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
	int width;
	int height;

	width = 64*(mlx->parse->rows + 1);
	height = 64*(mlx->parse->cols + 1);
    dx = ft_abs((int)x_coord - mlx->ply->ply_x_coord);
    dy = ft_abs((int)y_coord - mlx->ply->ply_y_coord);
	sx = (mlx->ply->ply_x_coord < (int)x_coord) ? 1 : -1;
	sy = (mlx->ply->ply_y_coord < (int)y_coord) ? -1 : 1;
    err = dx - dy;
    while (1)
	{
		if (mlx->ply->ply_x_coord >= 0 && mlx->ply->ply_x_coord < width
            && mlx->ply->ply_y_coord >= 0 && mlx->ply->ply_y_coord < height) //corrected width and height
			mlx_put_pixel(mlx->ray->minimap, mlx->ply->ply_x_coord, mlx->ply->ply_y_coord, 0x00FF00FF); //corrected img of minimap
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
    //This part is to initalize the important values for the minimap
	mlx->ply->ply_x_coord = mlx->parse->ply_y_pos_in_map * 64 + 32;
	mlx->ply->ply_y_coord = mlx->parse->ply_x_pos_in_map * 64 + 32;

	//This just draws horizontal and vertical lines
	draw_vert(mlx);
	draw_horiz(mlx);
	
	//This draws the walls (so fills the squares from the lines) and draws the player
	draw_walls(mlx);
	draw_player(mlx);

	//This function can be useful for the raycasting
	//First param: mlx, Second param: x_coordinate, Third param: y_coordinate
	minimap_draw_line(mlx, 100, 100);

	//raycasting
	raycasting(mlx);
}
