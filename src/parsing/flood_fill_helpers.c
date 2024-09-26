/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_helpers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 16:34:48 by nsabia            #+#    #+#             */
/*   Updated: 2024/09/26 17:12:18 by nsabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_abs(int num)
{
	if (num < 0)
		num *= -1;
	return (num);
}

void	find_player(t_mlx *mlx)
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

char	**map_copy_it(t_mlx *mlx)
{
	char	**copy;
	int		i;

	copy = ft_malloc((mlx->parse->cols + 1) * sizeof(char *));
	i = -1;
	while (++i < mlx->parse->cols)
		copy[i] = ft_strdup(mlx->parse->map[i]);
	copy[i] = NULL;
	return (copy);
}
