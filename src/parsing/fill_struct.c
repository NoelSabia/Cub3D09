/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 21:05:20 by nsabia            #+#    #+#             */
/*   Updated: 2024/10/10 01:57:46 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*clean_data(char *str)
{
	int		i;
	char	*result;

	i = 0;
	while (str[i] && ft_strchr("NOSWAFEC 	", str[i]))
		i++;
	result = ft_strncpy(str, i, ft_strlen(str));
	return (result);
}

int	get_floor_color(char *str_in, t_mlx *mlx, char *line)
{
	char	*str_tmp;

	if (ft_strncmp(str_in, "F", 1) == 0)
	{
		if (mlx->parse->floor_set)
			clean_exit("Error: 'F' specified more than once.");
		str_tmp = clean_data(line);
		mlx->parse->floor = str_tmp;
		mlx->parse->floor_set = 1;
		mlx->parse->input_counter++;
		return (1);
	}
	return (0);
}

int	get_celing_color(char *str_in, t_mlx *mlx, char *line)
{
	char	*str_tmp;

	if (ft_strncmp(str_in, "C", 1) == 0)
	{
		if (mlx->parse->ceiling_set)
			clean_exit("Error: 'C' specified more than once.");
		str_tmp = clean_data(line);
		mlx->parse->ceiling = str_tmp;
		mlx->parse->ceiling_set = 1;
		mlx->parse->input_counter++;
		return (1);
	}
	return (0);
}

void	map_and_graphic_validation(char *str1, char *str2, t_mlx *mlx, char *line)
{
	if (ft_strncmp(str2, "\n", 1) == 0)
		return ;
	else if (ft_strncmp(str1, "0", 1) == 0 || ft_strncmp(str1, "1", 1) == 0
		|| ft_strncmp(str2, "0", 1) == 0 || ft_strncmp(str2, "1", 1) == 0)
		return ;
	if (get_floor_color(str1, mlx, line) || get_celing_color(str1, mlx, line)
		|| graphic_path_west(str1, mlx, line)
		|| graphic_path_east(str1, mlx, line)
		|| graphic_path_north(str1, mlx, line)
		|| graphic_path_south(str1, mlx, line))
		return ;
	clean_exit("Not all elements included in the .cub file!");
}

void	map_path_file_validation(t_mlx *mlx)
{
	int		i;
	int		m;
	char	*str1;
	char	*str2;
	char	*line;

	i = -1;
	while (mlx->parse->input[++i])
	{
		m = 0;
		while (mlx->parse->input[i][m] == '\t'
			|| mlx->parse->input[i][m] == 32)
			m++;
		str1 = ft_strncpy(&mlx->parse->input[i][m], 0, 1);
		str2 = ft_strncpy(&mlx->parse->input[i][m], 0, 0);
		line = mlx->parse->input[i];
		map_and_graphic_validation(str1, str2, mlx, line);
	}
	if (!mlx->parse->north_set || !mlx->parse->west_set
		|| !mlx->parse->south_set || !mlx->parse->east_set
		|| !mlx->parse->ceiling_set || !mlx->parse->floor_set)
		clean_exit("Not all elements included in the .cub file!");
}
