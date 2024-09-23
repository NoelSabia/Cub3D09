/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 11:57:41 by nsabia            #+#    #+#             */
/*   Updated: 2024/09/23 17:39:43 by nsabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
int	ft_abs(int num);

int	minimap_dynamic_scale(t_mlx *mlx)
{
	int	dynamic_minimap_size;

	dynamic_minimap_size = (SCREEN_WIDTH / 100) * 25 / mlx->parse->rows;
	if (dynamic_minimap_size > 50)
		return (50);
	return (dynamic_minimap_size);
}

void put_block(t_mlx *mlx, int i, int j)
{
	int		i_end;
	int		j_end;
	int		j_zero;

	j_zero = j;
	i_end = i + minimap_dynamic_scale(mlx);
	j_end = j + minimap_dynamic_scale(mlx);
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
	int	len_for_draw;

    i = 0;
	len_for_draw = minimap_dynamic_scale(mlx);
    while (i < mlx->parse->cols)
    {
        j = 0;
        while (j < mlx->parse->rows)
        {
            if (mlx->parse->map[i][j] == '1')
            {
                put_block(mlx, j * len_for_draw, i * len_for_draw);
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
		while (i < minimap_dynamic_scale(mlx) * (mlx->parse->cols))
		{
			mlx_put_pixel(mlx->ray->minimap, minimap_dynamic_scale(mlx)  * j, i, 0xFFFFFFFF);
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
		while (i < minimap_dynamic_scale(mlx) * (mlx->parse->rows))
		{
			mlx_put_pixel(mlx->ray->minimap, i, minimap_dynamic_scale(mlx) * j, 0xFFFFFFFF);
			i++;
		}
		i = 0;
		j++;
		k++;
	}
}

void	minimap_draw_line(t_mlx *mlx, float x_coord, float y_coord)
{
	int dx = ft_abs((int)x_coord - mlx->ply->ply_x_coord);
	int dy = ft_abs((int)y_coord - mlx->ply->ply_y_coord);
	int sx = (mlx->ply->ply_x_coord < (int)x_coord) ? 1 : -1;
	int sy = (mlx->ply->ply_y_coord < (int)y_coord) ? -1 : 1;
	int err = dx - dy;
	int	e2;
	int x_coord_tmp = mlx->ply->ply_x_coord;
	int y_coord_tmp = mlx->ply->ply_y_coord;
    while (1)
	{
		if ((x_coord_tmp > 0 && x_coord_tmp < TILE_SIZE*(mlx->parse->rows + 1)) && (y_coord_tmp > 0 && y_coord_tmp < TILE_SIZE*(mlx->parse->cols + 1)))
			mlx_put_pixel(mlx->ray->minimap, x_coord_tmp, y_coord_tmp, 0x00FF00FF);
		if (x_coord_tmp >= (int)x_coord
            && y_coord_tmp >= (int)y_coord)
			break;
        e2 = err * 2;
        if (e2 > -dy)
		{
            err -= dy;
            x_coord_tmp += sx;
        }
        if (e2 < dx)
		{
            err += dx;
            y_coord_tmp -= sy;
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
	// minimap_draw_line(mlx, 500, 500);

	//raycasting
	// raycasting(mlx);
}
