/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_position.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 16:45:09 by tpaesch           #+#    #+#             */
/*   Updated: 2024/10/20 18:40:35 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	val_ply_pos(int ply_y, int ply_x, t_mlx *mlx)
{
	if (mlx->parse->map[(ply_y / TILE_SIZE)][(ply_x / TILE_SIZE)] != '1')
		return (true);
	return (false);
}

bool	y_move_check(int new_y, int old_x, t_mlx *mlx)
{
	if (val_ply_pos(new_y - 10, old_x, mlx)
		&& val_ply_pos(new_y + 10, old_x, mlx)
		&& val_ply_pos(new_y, old_x + 10, mlx)
		&& val_ply_pos(new_y, old_x - 10, mlx)
		&& val_ply_pos(new_y, old_x, mlx))
		return (true);
	return (false);
}

bool	x_move_check(int old_y, int new_x, t_mlx *mlx)
{
	if (val_ply_pos(old_y - 10, new_x, mlx)
		&& val_ply_pos(old_y + 10, new_x, mlx)
		&& val_ply_pos(old_y, new_x + 10, mlx)
		&& val_ply_pos(old_y, new_x - 10, mlx)
		&& val_ply_pos(old_y, new_x, mlx))
		return (true);
	return (false);
}
