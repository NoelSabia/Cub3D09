/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_preparation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noel <noel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 16:14:01 by nsabia            #+#    #+#             */
/*   Updated: 2024/09/29 10:35:33 by noel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	copyMap(int *i, t_mlx *mlx)
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

void	searchForMapStart(t_mlx *mlx)
{
	int	i;

	i = 0;
	while (mlx->parse->input[i])
	{
		if (char_validation(mlx->parse->input[i]) == true)
		{
			copyMap(&i, mlx);
			return ;
		}
		i++;
	}
}

void	validateMap(t_mlx *mlx)
{
	searchForMapStart(mlx);
	floodFillOrganizer(mlx);
}
