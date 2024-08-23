/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct_helpers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 16:37:30 by nsabia            #+#    #+#             */
/*   Updated: 2024/08/23 16:38:42 by nsabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*clean_data(char *str);

int	check_if_exists4(char *str1, char *str2, t_mlx *mlx, char *line)
{
	char	*str;

	(void)str2;
	if (ft_strncmp(str1, "NO", 2) == 0)
	{
		if (mlx->parse->north_set)
			clean_exit("Error: 'NO' specified more than once.");
		str = clean_data(line);
		mlx->parse->north = str;
		mlx->parse->north_set = 1;
		mlx->parse->input_counter++;
		return (0);
	}
	else if (ft_strncmp(str1, "SO", 2) == 0)
	{
		if (mlx->parse->south_set)
			clean_exit("Error: 'SO' specified more than once.");
		str = clean_data(line);
		mlx->parse->south = str;
		mlx->parse->south_set = 1;
		mlx->parse->input_counter++;
		return (0);
	}
	return (1);
}
