/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceiling_color.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noel <noel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 16:45:52 by nsabia            #+#    #+#             */
/*   Updated: 2024/08/27 10:52:28 by noel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	check_format_and_init_floor_color(uint8_t ceiling[3],
			int *i, t_mlx *mlx);

void	check_string(char *str)
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

void	floor_color(t_mlx *mlx)
{
	uint8_t		floor_color[3];
	char		*temp;
	char		*temp2;
	static int	i;
	static int	k;

	check_string(mlx->parse->floor);
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
	check_format_and_init_floor_color(floor_color, &i, mlx);
}

void	fuck_norminette(t_mlx *mlx, int *k)
{
	while (strchr(" \t", mlx->parse->ceiling[(*k)]))
		(*k)++;
}

void	floor_and_ceiling_color(t_mlx *mlx)
{
	uint8_t		ceiling[3];
	char		*temp;
	char		*temp2;
	static int	i;
	static int	k;

	floor_color(mlx);
	check_string(mlx->parse->ceiling);
	fuck_norminette(mlx, &k);
	while (mlx->parse->ceiling[k] && i < 3)
	{
		temp = ft_malloc(1);
		temp[0] = '\0';
		while (strchr("0123456789", mlx->parse->ceiling[k]))
		{
			temp2 = char_to_str(mlx->parse->ceiling[k++]);
			temp = ft_strjoin(temp, temp2);
		}
		ceiling[i++] = ft_atoi(temp);
		if (ft_atoi(temp) < 0 || ft_atoi(temp) > 255)
			clean_exit("Wrong number in F or C choose between 0 and 255!");
		if (mlx->parse->ceiling[k] == ',')
			k++;
	}
	check_format_and_init_floor_color(ceiling, &i, mlx);
}