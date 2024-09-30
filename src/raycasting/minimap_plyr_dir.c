/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_direction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:05:59 by nsabia            #+#    #+#             */
/*   Updated: 2024/09/30 12:16:47 by nsabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	arrow_north(t_mlx *mlx)
{
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->minimap_y_coord + 3, mlx->ply->minimap_x_coord, 0x00FF00FF);
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->minimap_y_coord + 2, mlx->ply->minimap_x_coord, 0x00FF00FF);
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->minimap_y_coord + 1, mlx->ply->minimap_x_coord, 0x00FF00FF);
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->minimap_y_coord, mlx->ply->minimap_x_coord, 0x00FF00FF);
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->minimap_y_coord + 2, mlx->ply->minimap_x_coord + 1, 0x00FF00FF);
	mlx_put_pixel(mlx->ray->minimap, mlx->ply->minimap_y_coord + 2, mlx->ply->minimap_x_coord - 1, 0x00FF00FF);
}

void	arrow_east(t_mlx *mlx)
{

}

void	arrow_south(t_mlx *mlx)
{

}

void	arrow_west(t_mlx *mlx)
{

}

void	arrow_north_east(t_mlx *mlx)
{

}

void	arrow_south_east(t_mlx *mlx)
{

}

void	arrow_south_west(t_mlx *mlx)
{

}

void	arrow_north_west(t_mlx *mlx)
{

}
