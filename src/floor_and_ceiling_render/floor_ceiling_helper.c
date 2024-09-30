/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceiling_helper.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noel <noel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 16:47:33 by nsabia            #+#    #+#             */
/*   Updated: 2024/09/29 12:55:59 by noel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	checkAndFormat(uint8_t ceiling[3], int *i, t_mlx *mlx, bool floor)
{
	if (*i != 3)
		clean_exit("Invalid ceiling color format!");
	if (floor == false)
		mlx->parse->ceiling_color = (ceiling[0] << 24)
			| (ceiling[1] << 16) | (ceiling[2] << 8) | 0xFF;
	else if(floor == true)
		mlx->parse->floor_color = (ceiling[0] << 24)
			| (ceiling[1] << 16) | (ceiling[2] << 8) | 0xFF;
}
