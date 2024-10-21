/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceiling_color.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 16:45:52 by nsabia            #+#    #+#             */
/*   Updated: 2024/10/21 17:39:17 by tpaesch          ###   ########.fr       */
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
