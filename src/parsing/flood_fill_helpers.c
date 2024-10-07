/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_helpers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 16:34:48 by nsabia            #+#    #+#             */
/*   Updated: 2024/10/07 16:24:29 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_abs(int num)
{
	if (num < 0)
		num *= -1;
	return (num);
}

void	findPlayer(t_mlx *mlx)
{
	int		y;
	int		x;

	y = -1;
	while (++y < mlx->parse->cols)
	{
		x = -1;
		while (mlx->parse->map[y][++x] != '\n')
		{
			if (mlx->parse->map[y][x] == 'N' || mlx->parse->map[y][x] == 'S'\
			|| mlx->parse->map[y][x] == 'W' || mlx->parse->map[y][x] == 'E')
			{
				mlx->parse->ply_x_pos_in_map = x;
				mlx->parse->ply_y_pos_in_map = y;
				return ;
			}
		}
	}
}

char	**prepareMapForFloodFill(t_mlx *mlx)
{
	char	**copy;
	int		i;

	copy = ft_malloc((mlx->parse->cols + 1) * sizeof(char *));
	i = -1;
	while (++i < mlx->parse->cols)
		copy[i] = ft_strdup(mlx->parse->map[i]);
	copy[i] = NULL;
	copy[mlx->parse->ply_y_pos_in_map][mlx->parse->ply_x_pos_in_map] = '0';
	return (copy);
}
