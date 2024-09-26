/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 16:22:28 by nsabia            #+#    #+#             */
/*   Updated: 2024/09/26 17:30:26 by nsabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_abs(int num);
void	find_player(t_mlx *mlx);
char	**map_copy_it(t_mlx *mlx);

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

char	*combine_strs(char *str1, char *str2)
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
	result[i + j] = '\n'; /*why newline here? cause if fucking works xD*/
	result[i + j + 1] = '\0';
	return (result);
}

void	out_of_bounds_procection(t_mlx *mlx, int len)
{
	int	longest;
	int	i;
	int	m;

	len = 0;
	i = -1;
	longest = 0;
	while (mlx->parse->map[++i])
	{
		len = ft_strlen(mlx->parse->map[i]);
		if (len > longest)
			longest = len;
	}
	longest--;
	mlx->parse->cols = i;
	mlx->parse->rows = longest;
	i = -1;
	while (mlx->parse->map[++i])
	{
		m = 0;
		while (mlx->parse->map[i][m])
			m++;
		mlx->parse->map[i] = combine_strs(mlx->parse->map[i],
				fill_spaces(longest - m));
	}
}

void	flood_fill(t_mlx *mlx, int x, int y, char **map_copy)
{
	// for (int i  = 0; i < 5 ; i++)
	// 	for (int j = 0; j < 3; j++)
	// 	printf("%c", map_copy[i][j]);
	if (x < 0 || x >= mlx->parse->cols || y < 0
		|| y >= (int)ft_strlen(map_copy[x]))
		clean_exit("Error: player isn't locked inside the map\n");
	else if (map_copy[x][y] != '0' && map_copy[x][y] != '1')
		clean_exit("Error: Map is invalid!\n");
	else if (map_copy[x][y] == '1')
		return ;
	map_copy[x][y] = '1';
	flood_fill(mlx, x - 1, y, map_copy);
	flood_fill(mlx, x + 1, y, map_copy);
	flood_fill(mlx, x, y - 1, map_copy);
	flood_fill(mlx, x, y + 1, map_copy);
}

void	flood_fill_organizer(t_mlx *mlx)
{
	char	**map_copy;
	int		len;

	len = 0;
	out_of_bounds_procection(mlx, len);
	find_player(mlx);
	map_copy = map_copy_it(mlx);
	map_copy[mlx->parse->ply_y_pos_in_map][mlx->parse->ply_x_pos_in_map] = '0';
	flood_fill(mlx, mlx->parse->ply_x_pos_in_map,
			mlx->parse->ply_y_pos_in_map, map_copy);
}
