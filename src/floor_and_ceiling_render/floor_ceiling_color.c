/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceiling_color.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 16:45:52 by nsabia            #+#    #+#             */
/*   Updated: 2024/10/22 18:02:38 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_and_format(uint8_t ceiling[3], int *i, t_mlx *mlx, bool floor)
{
	if (*i != 3)
		clean_exit("Invalid ceiling color format!", mlx);
	if (floor == false)
		mlx->parse->ceiling_color = (ceiling[0] << 24)
			| (ceiling[1] << 16) | (ceiling[2] << 8) | 0xFF;
	else if (floor == true)
		mlx->parse->floor_color = (ceiling[0] << 24)
			| (ceiling[1] << 16) | (ceiling[2] << 8) | 0xFF;
}

int	ft_isspace(char c)
{
	if (c == 32 || c == 9 || c == 10 || c == 11
		|| c == 12 || c == 13)
		return (1);
	return (0);
}

void	rgb_comma_check(char *str, int *commas, int *num_count, int count)
{
	int	i;

	i = 0;
	while (str[i])
	{
		while (ft_isspace(str[i]))
			i++;
		if (ft_isdigit(str[i]))
		{
			count = 0;
			while (ft_isdigit(str[i]))
			{
				count++;
				i++;
			}
			if (str[i] == ',')
				(*commas)++;
			if (str[i] == ',')
				i++;
			(*num_count)++;
		}
		else if ((*num_count) != 3)
			break ;
	}
}

void	check_rgb_values(char *str, t_mlx *mlx)
{
	int	check_commas;
	int	num_count;
	int	general_num_count;

	check_commas = 0;
	num_count = 0;
	general_num_count = 0;
	rgb_comma_check(str, &check_commas, &general_num_count, num_count);
	if (check_commas != 2 || general_num_count != 3)
		clean_exit("RGB values are not correct!\n", mlx);
}
