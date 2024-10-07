/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceiling_color.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 16:45:52 by nsabia            #+#    #+#             */
/*   Updated: 2024/10/07 16:24:16 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	checkAndFormat(uint8_t ceiling[3], int *i, t_mlx *mlx, bool floor);

void	checkRGBValues(char *str)
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

void	initalizeFloorColor(t_mlx *mlx)
{
	uint8_t		floor_color[3];
	char		*temp;
	char		*temp2;
	static int	i;
	static int	k;

	checkRGBValues(mlx->parse->floor);
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
	checkAndFormat(floor_color, &i, mlx, true);
}

void	initalizeCeilingColor(t_mlx *mlx)
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
	checkAndFormat(ceiling_color, &i, mlx, false);
}

void	floorAndCeilingColor(t_mlx *mlx)
{
	checkRGBValues(mlx->parse->ceiling);
	checkRGBValues(mlx->parse->floor);
	initalizeCeilingColor(mlx);
	initalizeFloorColor(mlx);
}
