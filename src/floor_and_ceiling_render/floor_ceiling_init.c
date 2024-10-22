/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceiling_init.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 16:47:33 by nsabia            #+#    #+#             */
/*   Updated: 2024/10/22 18:03:19 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_celing_color(t_mlx *mlx)
{
	uint8_t		ceiling_color[3];
	char		*temp;
	char		*temp2;
	static int	i;
	static int	k;

	while (ft_strchr(" \t", mlx->parse->ceiling[k]))
		k++;
	while (mlx->parse->ceiling[k] && i < 3)
	{
		temp = ft_malloc(1);
		temp[0] = '\0';
		while (ft_strchr("0123456789", mlx->parse->ceiling[k]))
		{
			temp2 = ft_char_to_str(mlx->parse->ceiling[k++]);
			temp = ft_strjoin(temp, temp2);
		}
		ceiling_color[i++] = ft_atoi(temp);
		if (ft_atoi(temp) < 0 || ft_atoi(temp) > 255)
			clean_exit("Wrong number in F or C choose between 0 and 255!", mlx);
		if (mlx->parse->ceiling[k] == ',')
			k++;
	}
	check_and_format(ceiling_color, &i, mlx, false);
}

void	init_floor_color(t_mlx *mlx)
{
	uint8_t		floor_color[3];
	char		*temp;
	char		*temp2;
	static int	i;
	static int	k;

	while (ft_strchr(" \t", mlx->parse->floor[k]))
		k++;
	while (mlx->parse->floor[k] && i < 3)
	{
		temp = ft_malloc(1);
		temp[0] = '\0';
		while (ft_strchr("0123456789", mlx->parse->floor[k]))
		{
			temp2 = ft_char_to_str(mlx->parse->floor[k++]);
			temp = ft_strjoin(temp, temp2);
		}
		floor_color[i++] = ft_atoi(temp);
		if (ft_atoi(temp) < 0 || ft_atoi(temp) > 255)
			clean_exit("Wrong number in F or C choose between 0 and 255!", mlx);
		if (mlx->parse->floor[k] == ',')
			k++;
	}
	check_and_format(floor_color, &i, mlx, true);
}

void	init_floor_celing_colors(t_mlx *mlx)
{
	check_rgb_values(mlx->parse->ceiling, mlx);
	check_rgb_values(mlx->parse->floor, mlx);
	init_celing_color(mlx);
	init_floor_color(mlx);
}
