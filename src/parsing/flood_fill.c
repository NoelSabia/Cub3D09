/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 16:22:28 by nsabia            #+#    #+#             */
/*   Updated: 2024/10/09 14:23:09 by nsabia           ###   ########.fr       */
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

void	floodFill(t_mlx *mlx, int x, int y, char **map_copy)
{
	if (y < 0 || y >= mlx->parse->rows || x < 0
		|| x >= (int)ft_strlen(map_copy[y]))
	{
		printf("x: %d\n", x);
		printf("y: %d\n", y);
		clean_exit("Error: player isn't locked inside the map\n");
	}
	else if (map_copy[y][x] != '0' && map_copy[y][x] != '1')
		clean_exit("Error: Map is invalid!\n");
	else if (map_copy[y][x] == '1')
		return ;
	map_copy[y][x] = '1';
	floodFill(mlx, x - 1, y, map_copy);
	floodFill(mlx, x + 1, y, map_copy);
	floodFill(mlx, x, y - 1, map_copy);
	floodFill(mlx, x, y + 1, map_copy);
}

void	floodFillOrganizer(t_mlx *mlx)
{
	char	**map_copy;
	int		len;

	len = 0;
	outOfBounceProtection(mlx, len);
	findPlayer(mlx);
	map_copy = prepareMapForFloodFill(mlx);
	printf("y1: %d\n", mlx->parse->ply_y_pos_in_map);
	printf("x1: %d\n", mlx->parse->ply_x_pos_in_map);
	for (int i = 0; i < 6; i++)
		printf("map: %s\n", map_copy[i]);
	floodFill(mlx, mlx->parse->ply_x_pos_in_map,
			mlx->parse->ply_y_pos_in_map, map_copy);
}
