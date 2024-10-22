/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceiling_color.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 16:45:52 by nsabia            #+#    #+#             */
/*   Updated: 2024/10/22 16:46:45 by nsabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_and_format(uint8_t ceiling[3], int *i, t_mlx *mlx, bool floor)
{
	if (*i != 3)
		clean_exit("Invalid ceiling color format!");
	if (floor == false)
		mlx->parse->ceiling_color = (ceiling[0] << 24)
			| (ceiling[1] << 16) | (ceiling[2] << 8) | 0xFF;
	else if (floor == true)
		mlx->parse->floor_color = (ceiling[0] << 24)
			| (ceiling[1] << 16) | (ceiling[2] << 8) | 0xFF;
}

int		ft_isspace(char c)
{
	if (c == 32 || c == 9 || c == 10 || c == 11
		|| c == 12 || c == 13)
		return (1);
	return (0);
}

void	check_rgb_values_helper(char *str, int *check_commas, int *general_num_count, int num_count)
{
	int	i;

	i = 0;
	while (str[i])
	{
		while (ft_isspace(str[i]))
			i++;
		if (ft_isdigit(str[i]))
		{
			num_count = 0;
			while (ft_isdigit(str[i]))
			{
				num_count++;
				i++;
			}
			if (str[i] == ',')
				(*check_commas)++;
			if (str[i] == ',')
				i++;
			(*general_num_count)++;
		}
		else if ((*general_num_count) != 3)
			break ;	
	}
}

void	check_rgb_values(char *str)
{
	int check_commas;
	int num_count;
	int	general_num_count;

	check_commas = 0;
	num_count = 0;
	general_num_count = 0;
	check_rgb_values_helper(str, &check_commas, &general_num_count, num_count);
	if (check_commas != 2 || general_num_count != 3)
		clean_exit("Please only three numbers separated with two commas!\n");
}
