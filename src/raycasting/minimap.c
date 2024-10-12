/* ************************************************************************** */
/*			                                                                */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 11:57:41 by nsabia            #+#    #+#             */
/*   Updated: 2024/10/10 14:55:14 by nsabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	minimap_dynamic_scale(t_mlx *mlx)
{
	int	dynamic_minimap_size;

	dynamic_minimap_size = (SCREEN_WIDTH / 100) * 25 / mlx->parse->rows;
	if (dynamic_minimap_size > 50)
		return (50);
	return (dynamic_minimap_size);
}

void	draw_player(t_mlx *mlx)
{
	float	eighth_of_unit_square;
	int		squaresize;

	squaresize = minimap_dynamic_scale(mlx);
	eighth_of_unit_square = (M_PI / 2) / 2;
	mlx->ply->minimap_x_coord = mlx->parse->ply_x_pos_in_map
		* squaresize + (squaresize / 2);
	mlx->ply->minimap_y_coord = mlx->parse->ply_y_pos_in_map
		* squaresize + (squaresize / 2);
	if (mlx->ply->minimap_x_coord < 5 || mlx->ply->minimap_x_coord >= 1915
		|| mlx->ply->minimap_y_coord < 5 || mlx->ply->minimap_y_coord >= 1075)
		return ;
	if (mlx->ply->center_angle >= (3 * M_PI / 2) - eighth_of_unit_square
		&& mlx->ply->center_angle <= (3 * M_PI / 2) + eighth_of_unit_square)
		arrow_north(mlx);
	else if (mlx->ply->center_angle >= 0 + eighth_of_unit_square
		&& mlx->ply->center_angle <= (M_PI) - eighth_of_unit_square)
		arrow_south(mlx);
	else if (mlx->ply->center_angle > (M_PI / 2) + eighth_of_unit_square
		&& mlx->ply->center_angle < (3 * M_PI / 2) - eighth_of_unit_square)
		arrow_west(mlx);
	else
		arrow_east(mlx);
}

void	minimap_draw(t_mlx *mlx)
{
	draw_vert(mlx);
	draw_horiz(mlx);
	draw_walls(mlx);
	draw_player(mlx);
}
