/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_orientation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 16:37:30 by nsabia            #+#    #+#             */
/*   Updated: 2024/10/22 17:51:25 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	graphic_path_north(char *str_in, t_mlx *mlx, char *line)
{
	char	*str_tmp;
	int		where_to_place_null;

	if (ft_strncmp(str_in, "NO", 2) == 0)
	{
		if (mlx->parse->north_set)
			clean_exit("Error: 'NO' specified more than once.", mlx);
		str_tmp = clean_data(line);
		mlx->parse->north = str_tmp;
		mlx->parse->north_set = 1;
		mlx->parse->input_counter++;
		where_to_place_null = ft_strlen(mlx->parse->north);
		mlx->parse->north[where_to_place_null - 1] = '\0';
		return (1);
	}
	return (0);
}

int	graphic_path_south(char *str_in, t_mlx *mlx, char *line)
{
	char	*str_tmp;
	int		where_to_place_null;

	if (ft_strncmp(str_in, "SO", 2) == 0)
	{
		if (mlx->parse->south_set)
			clean_exit("Error: 'SO' specified more than once.", mlx);
		str_tmp = clean_data(line);
		mlx->parse->south = str_tmp;
		mlx->parse->south_set = 1;
		mlx->parse->input_counter++;
		where_to_place_null = ft_strlen(mlx->parse->south);
		mlx->parse->south[where_to_place_null - 1] = '\0';
		return (1);
	}
	return (0);
}

int	graphic_path_west(char *str_in, t_mlx *mlx, char *line)
{
	char	*str_tmp;
	int		where_to_place_null;

	if (ft_strncmp(str_in, "WE", 2) == 0)
	{
		if (mlx->parse->west_set)
			clean_exit("Error: 'WE' specified more than once.", mlx);
		str_tmp = clean_data(line);
		mlx->parse->west = str_tmp;
		mlx->parse->west_set = 1;
		mlx->parse->input_counter++;
		where_to_place_null = ft_strlen(mlx->parse->west);
		mlx->parse->west[where_to_place_null - 1] = '\0';
		return (1);
	}
	return (0);
}

int	graphic_path_east(char *str_in, t_mlx *mlx, char *line)
{
	char	*str_tmp;
	int		where_to_place_null;

	if (ft_strncmp(str_in, "EA", 2) == 0)
	{
		if (mlx->parse->east_set)
			clean_exit("Error: 'EA' specified more than once.", mlx);
		str_tmp = clean_data(line);
		mlx->parse->east = str_tmp;
		mlx->parse->east_set = 1;
		mlx->parse->input_counter++;
		where_to_place_null = ft_strlen(mlx->parse->east);
		mlx->parse->east[where_to_place_null - 1] = '\0';
		return (1);
	}
	return (0);
}
