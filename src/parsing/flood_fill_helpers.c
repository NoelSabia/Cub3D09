/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_helpers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 16:34:48 by nsabia            #+#    #+#             */
/*   Updated: 2024/09/23 15:02:36 by tpaesch          ###   ########.fr       */
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
	int		i;
	int		j;

	i = 0;
	while (i < mlx->parse->cols)
	{
		j = 0;
		while (mlx->parse->map[i][j] != '\n')
		{
			if (mlx->parse->map[i][j] == 'N' || mlx->parse->map[i][j] == 'S'\
			|| mlx->parse->map[i][j] == 'W' || mlx->parse->map[i][j] == 'E')
			{
				mlx->parse->ply_x_pos_in_map = i;
				mlx->parse->ply_y_pos_in_map = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

char	**map_copy_it(t_mlx *mlx)
{
	char	**copy;
	int		i;

	copy = ft_malloc((mlx->parse->cols + 1) * sizeof(char *));
	i = 0;
	while (i < mlx->parse->cols)
	{
		copy[i] = ft_strdup(mlx->parse->map[i]);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}
