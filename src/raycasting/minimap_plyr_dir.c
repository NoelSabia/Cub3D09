/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_plyr_dir.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:05:59 by nsabia            #+#    #+#             */
/*   Updated: 2024/10/01 10:52:53 by nsabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	arrow_north(t_mlx *mlx)
{
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->ply_x_coord, mlx->ply->ply_y_coord - 2, 0x00FF00FF);
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->ply_x_coord, mlx->ply->ply_y_coord - 1, 0x00FF00FF);
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->ply_x_coord, mlx->ply->ply_y_coord, 0x00FF00FF);
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->ply_x_coord, mlx->ply->ply_y_coord + 1, 0x00FF00FF);
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->ply_x_coord, mlx->ply->ply_y_coord + 2, 0x00FF00FF);
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->ply_x_coord, mlx->ply->ply_y_coord + 3, 0x00FF00FF);
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->ply_x_coord, mlx->ply->ply_y_coord + 4, 0x00FF00FF);
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->ply_x_coord + 1, mlx->ply->ply_y_coord, 0x00FF00FF);
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->ply_x_coord - 1, mlx->ply->ply_y_coord, 0x00FF00FF);
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->ply_x_coord + 2, mlx->ply->ply_y_coord, 0x00FF00FF);
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->ply_x_coord - 2, mlx->ply->ply_y_coord, 0x00FF00FF);
}

void	arrow_east(t_mlx *mlx)
{
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->ply_x_coord, mlx->ply->ply_y_coord, 0x00FF00FF);
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->ply_x_coord - 1, mlx->ply->ply_y_coord, 0x00FF00FF);
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->ply_x_coord - 2, mlx->ply->ply_y_coord, 0x00FF00FF);
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->ply_x_coord - 3, mlx->ply->ply_y_coord, 0x00FF00FF);
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->ply_x_coord - 4, mlx->ply->ply_y_coord, 0x00FF00FF);
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->ply_x_coord + 1, mlx->ply->ply_y_coord, 0x00FF00FF);
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->ply_x_coord + 2, mlx->ply->ply_y_coord, 0x00FF00FF);
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->ply_x_coord, mlx->ply->ply_y_coord - 1, 0x00FF00FF);
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->ply_x_coord, mlx->ply->ply_y_coord - 2, 0x00FF00FF);
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->ply_x_coord, mlx->ply->ply_y_coord + 1, 0x00FF00FF);
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->ply_x_coord, mlx->ply->ply_y_coord + 2, 0x00FF00FF);
}

void	arrow_south(t_mlx *mlx)
{
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->ply_x_coord, mlx->ply->ply_y_coord - 1, 0x00FF00FF);
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->ply_x_coord, mlx->ply->ply_y_coord - 2, 0x00FF00FF);
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->ply_x_coord, mlx->ply->ply_y_coord - 3, 0x00FF00FF);
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->ply_x_coord, mlx->ply->ply_y_coord - 4, 0x00FF00FF);
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->ply_x_coord, mlx->ply->ply_y_coord + 1, 0x00FF00FF);
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->ply_x_coord, mlx->ply->ply_y_coord + 2, 0x00FF00FF);
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->ply_x_coord, mlx->ply->ply_y_coord, 0x00FF00FF);
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->ply_x_coord + 1, mlx->ply->ply_y_coord, 0x00FF00FF);
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->ply_x_coord + 2, mlx->ply->ply_y_coord, 0x00FF00FF);
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->ply_x_coord - 1, mlx->ply->ply_y_coord, 0x00FF00FF);
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->ply_x_coord - 2, mlx->ply->ply_y_coord, 0x00FF00FF);
}

void	arrow_west(t_mlx *mlx)
{
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->ply_x_coord, mlx->ply->ply_y_coord, 0x00FF00FF);
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->ply_x_coord - 1, mlx->ply->ply_y_coord, 0x00FF00FF);
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->ply_x_coord - 2, mlx->ply->ply_y_coord, 0x00FF00FF);
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->ply_x_coord + 1, mlx->ply->ply_y_coord, 0x00FF00FF);
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->ply_x_coord + 2, mlx->ply->ply_y_coord, 0x00FF00FF);
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->ply_x_coord + 3, mlx->ply->ply_y_coord, 0x00FF00FF);
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->ply_x_coord + 4, mlx->ply->ply_y_coord, 0x00FF00FF);
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->ply_x_coord, mlx->ply->ply_y_coord - 1, 0x00FF00FF);
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->ply_x_coord, mlx->ply->ply_y_coord - 2, 0x00FF00FF);
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->ply_x_coord, mlx->ply->ply_y_coord + 1, 0x00FF00FF);
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->ply_x_coord, mlx->ply->ply_y_coord + 2, 0x00FF00FF);
}
