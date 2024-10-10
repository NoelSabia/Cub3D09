/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 12:47:05 by nsabia            #+#    #+#             */
/*   Updated: 2024/10/10 12:49:04 by nsabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_textures(t_mlx *mlx);

char	*readCubFile(char *filename)
{
	int			fd;
	char		*buffer;
	size_t		size;

	size = 100000000;
	buffer = ft_calloc(1, size);
	fd = open(filename, O_RDONLY);
	while (read(fd, buffer, size - 1))
	{
		buffer = ft_realloc(buffer, size, size + 100);
		size = size + 100;
	}
	close(fd);
	return (buffer);
}

char	*mapTabstoSpaces(const char *str)
{
	int		i;
	int		count;
	int		new_str_len;
	char	*newLineWithoutTabs;

	i = -1;
	count = 0;
	while (str[++i])
		if (str[i] == '\t')
			count++;
	new_str_len = ((count * 4) + ft_strlen(str) + 2);
	newLineWithoutTabs = ft_calloc(new_str_len, 1);
	newLineWithoutTabs = ft_tab_to_space(str, newLineWithoutTabs);
	return (newLineWithoutTabs);
}

void	convertMapStringIn2DArray(t_mlx *mlx, char *clean_file_content)
{
	int		i;
	int		j;
	int		k;
	int		line_count;
	char	*str;

	i = -1;
	j = 0;
	k = 0;
	line_count = 0;
	while (clean_file_content[++i])
		if (clean_file_content[i] == '\n')
			line_count++;
	mlx->parse->input = ft_malloc((line_count + 3) * sizeof(char *));
	i = 0;
	while (clean_file_content[i])
	{
		while (clean_file_content[i] && clean_file_content[i] != '\n')
			i++;
		str = ft_strncpy(clean_file_content, j, i);
		i++;
		j = i;
		mlx->parse->input[k++] = ft_strdup(str);
	}
	mlx->parse->input[k] = NULL;
}

void	playerDirection(t_mlx *mlx)
{
	char	c;

	c = mlx->parse->map[mlx->parse->ply_y_pos_in_map][mlx->parse->ply_x_pos_in_map];
	if (c == 'E')
		mlx->ply->center_angle = 0 + 0.28;
	else if (c == 'S')
		mlx->ply->center_angle = (M_PI / 2) + 0.28;
	else if (c == 'W')
		mlx->ply->center_angle = M_PI + 0.28;
	else if (c == 'N')
		mlx->ply->center_angle = (3 * M_PI) / 2 + 0.28;
	else
		clean_exit("Player spawn is not W N E or S!");
}

void	validateArgsAndFileName(char *filename, int argc)
{
	char	*cub;

	if (argc < 2 || argc > 2)
		clean_exit("Usage: ./Cub3d <filename>.cub\n");
	cub = ft_strnstr(filename, ".cub", ft_strlen(filename));
	if (!cub || cub == filename)
		clean_exit("No .cub found!");
	while (*cub)
		if (!ft_strchr(".cub", *cub++))
			clean_exit("Please only .cub at the end!\n");
	if (!ft_strnstr(filename, ".cub", ft_strlen(filename)))
		clean_exit("Please submit a .cub file!\n");
}

void	parsing(t_mlx *mlx, char *filename, int argc)
{
	char	*file_content;
	char	*clean_file_content;

	validateArgsAndFileName(filename, argc);
	file_content = readCubFile(filename);
	clean_file_content = mapTabstoSpaces(file_content);
	convertMapStringIn2DArray(mlx, clean_file_content);
	verifyMapPathAndFile(mlx);
	validateMap(mlx);
	init_textures(mlx);
	floorAndCeilingColor(mlx);
	playerDirection(mlx);
}
