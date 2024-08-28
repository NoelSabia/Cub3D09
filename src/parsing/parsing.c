/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noel <noel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 12:47:05 by nsabia            #+#    #+#             */
/*   Updated: 2024/08/28 11:19:15 by noel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*replace_tab_helper(const char *str, char *result, int *j, int *i);

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

char	*replace_tab(const char *str, char old_char, const char *new_str)
{
	int		i;
	int		count;
	int		new_str_len;
	char	*result;
	int		j;

	i = -1;
	count = 0;
	j = -1;
	new_str_len = ft_strlen(new_str);
	while (str[++i])
		if (str[i] == old_char)
			count++;
	result = ft_calloc(1, (count * new_str_len) + (ft_strlen(str) + 1) + 10);
	i = -1;
	result = replace_tab_helper(str, result, &j, &i);
	result[++j] = '\0';
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

	c = mlx->parse->map[mlx->parse->ply_x_pos_in_map][mlx->parse->ply_y_pos_in_map];
	if (c == 'E')
		mlx->ply->angle = 90;
	else if (c == 'N')
		mlx->ply->angle = 0;
	else if (c == 'W')
		mlx->ply->angle = 270;
	else if (c == 'S')
		mlx->ply->angle = 180;
	else
		clean_exit("Player spawn is not W N E or S!");
	// mlx->ply->most_left_angle = mlx->ply->angle + 30;
	// mlx->ply->most_right_angle = mlx->ply->angle - 30;
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
	clean_output = replace_tab(output, '	', "    ");
	put_in_2d_str(mlx, clean_output);
	fill_parse_struct(mlx);
	validate_map(mlx);
	player_direction(mlx);
}
