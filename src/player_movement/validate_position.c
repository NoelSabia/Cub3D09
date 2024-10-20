/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_position.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 16:45:09 by tpaesch           #+#    #+#             */
/*   Updated: 2024/10/20 18:13:52 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	val_ply_pos(int ply_y, int ply_x, t_mlx *mlx)
{
	if (mlx->parse->map[(ply_y / TILE_SIZE)][(ply_x / TILE_SIZE)] != '1')
		return (true);
	return (false);
}
