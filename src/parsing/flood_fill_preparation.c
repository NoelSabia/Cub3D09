/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_preparation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 16:14:01 by nsabia            #+#    #+#             */
/*   Updated: 2024/09/26 13:17:45 by nsabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	copy_map(int *i, t_mlx *mlx)
{
	int	len;
	int	k;

	len = 0;
	k = -1;
	while (mlx->parse->input[(*i)++])
		len++;
	(*i) -= len;
	len += (*i);
	mlx->parse->map = ft_malloc(len * sizeof(char *));
	(*i) -= 2;
	while (mlx->parse->input[++(*i)])
		mlx->parse->map[++k] = ft_strdup(mlx->parse->input[(*i)]);
	mlx->parse->map[++k] = NULL;
}

bool	char_validation(char *str)
{
	int		i;
	size_t	is_inside;

	i = -1;
	is_inside = 0;
	if (ft_strchr(str, '0') == NULL && ft_strchr(str, '1') == NULL)
		return (false);
	while (str[++i])
	{
		if (str[i] == '0' || str[i] == '1' || str[i] == 'N'
			|| str[i] == 'W' || str[i] == 'E' || str[i] == 'S'
			|| str[i] == 32 || str[i] == '\t' || str[i] == '\n')
			is_inside++;
	}
	if (is_inside == ft_strlen(str))
		return (true);
	return (false);
}

void	search_for_map_start(t_mlx *mlx)
{
	int	i;

	i = 0;
	while (mlx->parse->input[i])
	{
		if (char_validation(mlx->parse->input[i]) == true)
		{
			copy_map(&i, mlx);
			return ;
		}
		i++;
	}
}

void	validate_map(t_mlx *mlx)
{
	search_for_map_start(mlx);
	flood_fill_organizer(mlx);
}
