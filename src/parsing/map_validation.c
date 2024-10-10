/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:22:25 by tpaesch           #+#    #+#             */
/*   Updated: 2024/10/10 14:26:50 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*read_map_file(char *filename)
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

char	*map_tab_to_space(const char *str)
{
	int		i;
	int		count;
	int		new_str_len;
	char	*new_line_no_tabs;

	i = -1;
	count = 0;
	while (str[++i])
		if (str[i] == '\t')
			count++;
	new_str_len = ((count * 4) + ft_strlen(str) + 2);
	new_line_no_tabs = ft_calloc(new_str_len, 1);
	new_line_no_tabs = ft_tab_to_space(str, new_line_no_tabs);
	return (new_line_no_tabs);
}

void	map_to_doublearray(t_mlx *mlx, char *clean_file_content)
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
