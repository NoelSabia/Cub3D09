/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 16:22:28 by nsabia            #+#    #+#             */
/*   Updated: 2024/10/09 15:22:09 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_abs(int num);
void	findPlayer(t_mlx *mlx);
char	**prepareMapForFloodFill(t_mlx *mlx);

char	*fill_spaces(int len)
{
	char	*str;
	int		counter;

	str = ft_malloc(ft_abs(len) + 10);
	counter = 0;
	while (counter++ <= len)
		str = ft_strjoin(" ", str);
	str[counter] = '\0';
	return (str);
}

char	*combineMapStringWithSpaces(char *str1, char *str2)
{
	int		i;
	int		j;
	char	*result;
	int		len;

	i = -1;
	j = -1;
	while (str1[++i])
		if (ft_strchr("01NWSE \n", str1[i]) == NULL)
			clean_exit("Unallowed characters in map detected!\n\
or map not at the bottom of the file!\n");
	result = ft_malloc(ft_strlen(str1) + ft_strlen(str2) + 2);
	len = ft_strlen(str1);
	if (len > 0 && str1[len - 1] == '\n')
		str1[len - 1] = '\0';
	i = -1;
	while (str1[++i])
		result[i] = str1[i];
	while (str2[++j])
		result[i + j] = str2[j];
	result[i + j] = '\n';
	result[i + j + 1] = '\0';
	return (result);
}

void	outOfBounceProtection(t_mlx *mlx, int len)
{
	int	longest_line;
	int	i;
	int	m;

	len = 0;
	i = -1;
	longest_line = 0;
	while (mlx->parse->map[++i])
	{
		len = ft_strlen(mlx->parse->map[i]);
		if (len > longest_line)
			longest_line = len;
	}
	longest_line--;
	mlx->parse->cols = i;
	mlx->parse->rows = longest_line;
	i = -1;
	while (mlx->parse->map[++i])
	{
		m = 0;
		while (mlx->parse->map[i][m])
			m++;
		mlx->parse->map[i] = combineMapStringWithSpaces(mlx->parse->map[i],
				fill_spaces(longest_line - m));
	}
}

void	floodFill(t_mlx *mlx, int y, int x, char **map_copy)
{
	if (map_copy[y][x] != '0' && map_copy[y][x] != '1')
		clean_exit("Error: Map is invalid!\n");
	else if (map_copy[y][x] == '1')
		return ;
	map_copy[y][x] = '1';
	floodFill(mlx, y - 1, x, map_copy);
	floodFill(mlx, y + 1, x, map_copy);
	floodFill(mlx, y, x - 1, map_copy);
	floodFill(mlx, y, x + 1, map_copy);
}

void	floodFillOrganizer(t_mlx *mlx)
{
	char	**map_copy;
	int		len;

	len = 0;
	outOfBounceProtection(mlx, len);
	findPlayer(mlx);
	map_copy = prepareMapForFloodFill(mlx);
	floodFill(mlx, mlx->parse->ply_y_pos_in_map,
		mlx->parse->ply_x_pos_in_map, map_copy);
}
