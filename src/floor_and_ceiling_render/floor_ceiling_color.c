/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceiling_color.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 16:45:52 by nsabia            #+#    #+#             */
/*   Updated: 2024/10/10 02:00:14 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_and_format(uint8_t ceiling[3], int *i, t_mlx *mlx, bool floor);

void	check_rgb_values(char *str)
{
	int	i;
	int	check_commas;

	i = -1;
	check_commas = 0;
	while (str[++i])
		if (str[i] == ',')
			check_commas++;
	if (!(check_commas == 2))
		clean_exit("Please only three numbers seperated with two commas!\n");
	i = 0;
	while (str[i] && ft_strchr(" 	,0123456789", str[i]))
		i++;
	if (!ft_strchr(" 	,0123456789\n\0", str[i]))
		clean_exit("Unallowed chars in F or C detected!\n");
}

char	*char_to_str(char c)
{
	char	*result;

	result = ft_malloc(2);
	result[0] = c;
	result[1] = '\0';
	return (result);
}

void	init_floor_color(t_mlx *mlx)
{
	uint8_t		floor_color[3];
	char		*temp;
	char		*temp2;
	static int	i;
	static int	k;

	check_rgb_values(mlx->parse->floor);
	while (strchr(" \t", mlx->parse->floor[k]))
		k++;
	while (mlx->parse->floor[k] && i < 3)
	{
		temp = ft_malloc(1);
		temp[0] = '\0';
		while (strchr("0123456789", mlx->parse->floor[k]))
		{
			temp2 = char_to_str(mlx->parse->floor[k++]);
			temp = ft_strjoin(temp, temp2);
		}
		floor_color[i++] = ft_atoi(temp);
		if (ft_atoi(temp) < 0 || ft_atoi(temp) > 255)
			clean_exit("Wrong number in F or C choose between 0 and 255!");
		if (mlx->parse->floor[k] == ',')
			k++;
	}
	check_and_format(floor_color, &i, mlx, true);
}

void	init_celing_color(t_mlx *mlx)
{
	uint8_t		ceiling_color[3];
	char		*temp;
	char		*temp2;
	static int	i;
	static int	k;

	while (strchr(" \t", mlx->parse->ceiling[k]))
		k++;
	while (mlx->parse->ceiling[k] && i < 3)
	{
		temp = ft_malloc(1);
		temp[0] = '\0';
		while (strchr("0123456789", mlx->parse->ceiling[k]))
		{
			temp2 = char_to_str(mlx->parse->ceiling[k++]);
			temp = ft_strjoin(temp, temp2);
		}
		ceiling_color[i++] = ft_atoi(temp);
		if (ft_atoi(temp) < 0 || ft_atoi(temp) > 255)
			clean_exit("Wrong number in F or C choose between 0 and 255!");
		if (mlx->parse->ceiling[k] == ',')
			k++;
	}
	check_and_format(ceiling_color, &i, mlx, false);
}

void	init_floor_celing_colors(t_mlx *mlx)
{
	check_rgb_values(mlx->parse->ceiling);
	check_rgb_values(mlx->parse->floor);
	init_celing_color(mlx);
	init_floor_color(mlx);
}
