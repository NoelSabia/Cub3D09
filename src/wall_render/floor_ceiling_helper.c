/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceiling_helper.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 16:47:33 by nsabia            #+#    #+#             */
/*   Updated: 2024/08/23 16:47:44 by nsabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	check_format_and_init_floor_color(uint8_t ceiling[3],
			int *i, t_mlx *mlx)
{
	if (*i != 3)
		clean_exit("Invalid ceiling color format!");
	mlx->parse->ceiling_color = (ceiling[0] << 24)
		| (ceiling[1] << 16) | (ceiling[2] << 8) | 0xFF;
}
