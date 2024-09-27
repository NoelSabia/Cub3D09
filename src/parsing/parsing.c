/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 12:47:05 by nsabia            #+#    #+#             */
/*   Updated: 2024/09/27 13:35:32 by nsabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*read_into_input(char *filename)
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

char	*replace_tab(const char *str)
{
	int		i;
	int		count;
	int		new_str_len;
	char	*result;

	i = -1;
	count = 0;
	while (str[++i])
		if (str[i] == '\t')
			count++;
	new_str_len = ((count * 4) + ft_strlen(str) + 2);
	result = ft_calloc(new_str_len, 1);
	result = ft_tab_to_space(str, result);
	return (result);
}

void	put_in_2d_str(t_mlx *mlx, char *clean_output)
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
	while (clean_output[++i])
		if (clean_output[i] == '\n')
			line_count++;
	mlx->parse->input = ft_malloc((line_count + 3) * sizeof(char *));
	i = 0;
	while (clean_output[i])
	{
		while (clean_output[i] && clean_output[i] != '\n')
			i++;
		str = ft_strncpy(clean_output, j, i);
		i++;
		j = i;
		mlx->parse->input[k++] = ft_strdup(str);
	}
	mlx->parse->input[k] = NULL;
}

void	player_direction(t_mlx *mlx)
{
	char	c;

	c = mlx->parse->map[mlx->parse->ply_y_pos_in_map][mlx->parse->ply_x_pos_in_map];
	if (c == 'E')
		mlx->ply->center_angle = 0;
	else if (c == 'S')
		mlx->ply->center_angle = (M_PI / 2);
	else if (c == 'W')
		mlx->ply->center_angle = M_PI;
	else if (c == 'N')
		mlx->ply->center_angle = (3 * M_PI) / 2;
	else
		clean_exit("Player spawn is not W N E or S!");
}

void	parsing(t_mlx *mlx, char *filename)
{
	char	*output;
	char	*clean_output;
	char	*cub;

	cub = ft_strnstr(filename, ".cub", ft_strlen(filename));
	if (!cub || cub == filename)
		clean_exit("No .cub found!");
	while (*cub)
		if (!ft_strchr(".cub", *cub++))
			clean_exit("Please only .cub at the end!\n");
	if (!ft_strnstr(filename, ".cub", ft_strlen(filename)))
		clean_exit("Please submit a .cub file!\n");
	output = read_into_input(filename);
	clean_output = replace_tab(output);
	put_in_2d_str(mlx, clean_output);
	fill_parse_struct(mlx);
	validate_map(mlx);
	player_direction(mlx);
}
