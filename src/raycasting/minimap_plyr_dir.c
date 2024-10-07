/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_plyr_dir.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noel <noel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:05:59 by nsabia            #+#    #+#             */
/*   Updated: 2024/10/04 17:07:59 by noel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	arrow_north(t_mlx *mlx)
{
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->ply_x_coord, mlx->ply->ply_y_coord - 2, 0xFF0000FF);
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->ply_x_coord, mlx->ply->ply_y_coord - 1, 0xFF0000FF);
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->ply_x_coord, mlx->ply->ply_y_coord, 0xFF0000FF);
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->ply_x_coord, mlx->ply->ply_y_coord + 1, 0xFF0000FF);
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->ply_x_coord, mlx->ply->ply_y_coord + 2, 0xFF0000FF);
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->ply_x_coord, mlx->ply->ply_y_coord + 3, 0xFF0000FF);
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->ply_x_coord, mlx->ply->ply_y_coord + 4, 0xFF0000FF);
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->ply_x_coord + 1, mlx->ply->ply_y_coord, 0xFF0000FF);
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->ply_x_coord - 1, mlx->ply->ply_y_coord, 0xFF0000FF);
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->ply_x_coord + 2, mlx->ply->ply_y_coord, 0xFF0000FF);
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->ply_x_coord - 2, mlx->ply->ply_y_coord, 0xFF0000FF);
}

void	arrow_east(t_mlx *mlx)
{
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->ply_x_coord, mlx->ply->ply_y_coord, 0xFF0000FF);
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->ply_x_coord - 1, mlx->ply->ply_y_coord, 0xFF0000FF);
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->ply_x_coord - 2, mlx->ply->ply_y_coord, 0xFF0000FF);
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->ply_x_coord - 3, mlx->ply->ply_y_coord, 0xFF0000FF);
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->ply_x_coord - 4, mlx->ply->ply_y_coord, 0xFF0000FF);
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->ply_x_coord + 1, mlx->ply->ply_y_coord, 0xFF0000FF);
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->ply_x_coord + 2, mlx->ply->ply_y_coord, 0xFF0000FF);
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->ply_x_coord, mlx->ply->ply_y_coord - 1, 0xFF0000FF);
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->ply_x_coord, mlx->ply->ply_y_coord - 2, 0xFF0000FF);
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->ply_x_coord, mlx->ply->ply_y_coord + 1, 0xFF0000FF);
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->ply_x_coord, mlx->ply->ply_y_coord + 2, 0xFF0000FF);
}

void	arrow_south(t_mlx *mlx)
{
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->ply_x_coord, mlx->ply->ply_y_coord - 1, 0xFF0000FF);
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->ply_x_coord, mlx->ply->ply_y_coord - 2, 0xFF0000FF);
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->ply_x_coord, mlx->ply->ply_y_coord - 3, 0xFF0000FF);
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->ply_x_coord, mlx->ply->ply_y_coord - 4, 0xFF0000FF);
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->ply_x_coord, mlx->ply->ply_y_coord + 1, 0xFF0000FF);
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->ply_x_coord, mlx->ply->ply_y_coord + 2, 0xFF0000FF);
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->ply_x_coord, mlx->ply->ply_y_coord, 0xFF0000FF);
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->ply_x_coord + 1, mlx->ply->ply_y_coord, 0xFF0000FF);
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->ply_x_coord + 2, mlx->ply->ply_y_coord, 0xFF0000FF);
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->ply_x_coord - 1, mlx->ply->ply_y_coord, 0xFF0000FF);
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->ply_x_coord - 2, mlx->ply->ply_y_coord, 0xFF0000FF);
}

void	arrow_west(t_mlx *mlx)
{
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->ply_x_coord, mlx->ply->ply_y_coord, 0xFF0000FF);
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->ply_x_coord - 1, mlx->ply->ply_y_coord, 0xFF0000FF);
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->ply_x_coord - 2, mlx->ply->ply_y_coord, 0xFF0000FF);
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->ply_x_coord + 1, mlx->ply->ply_y_coord, 0xFF0000FF);
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->ply_x_coord + 2, mlx->ply->ply_y_coord, 0xFF0000FF);
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->ply_x_coord + 3, mlx->ply->ply_y_coord, 0xFF0000FF);
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->ply_x_coord + 4, mlx->ply->ply_y_coord, 0xFF0000FF);
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->ply_x_coord, mlx->ply->ply_y_coord - 1, 0xFF0000FF);
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->ply_x_coord, mlx->ply->ply_y_coord - 2, 0xFF0000FF);
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->ply_x_coord, mlx->ply->ply_y_coord + 1, 0xFF0000FF);
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->ply_x_coord, mlx->ply->ply_y_coord + 2, 0xFF0000FF);
}
