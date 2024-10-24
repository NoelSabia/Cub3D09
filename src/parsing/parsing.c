/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 12:47:05 by nsabia            #+#    #+#             */
/*   Updated: 2024/10/22 17:58:44 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	define_player_direction(t_mlx *mlx)
{
	char	c;

	c = mlx->parse->map[mlx->parse->ply_y_pos_in_map]
	[mlx->parse->ply_x_pos_in_map];
	if (c == 'N')
		mlx->ply->center_angle = 0;
	else if (c == 'S')
		mlx->ply->center_angle = (M_PI / 2);
	else if (c == 'W')
		mlx->ply->center_angle = M_PI;
	else if (c == 'E')
		mlx->ply->center_angle = (3 * M_PI) / 2;
	else
		clean_exit("Player spawn is not W N E or S!", mlx);
}

void	argument_validation(char *filename, int argc, t_mlx *mlx)
{
	char	*cub;

	if (argc < 2 || argc > 2)
		clean_exit("Usage: ./Cub3d <filename>.cub\n", mlx);
	cub = ft_strnstr(filename, ".cub", ft_strlen(filename));
	if (!cub || cub == filename)
		clean_exit("No .cub found!", mlx);
	while (*cub)
		if (!ft_strchr(".cub", *cub++))
			clean_exit("Please only .cub at the end!\n", mlx);
	if (!ft_strnstr(filename, ".cub", ft_strlen(filename)))
		clean_exit("Please submit a .cub file!\n", mlx);
}

void	parsing(t_mlx *mlx, char *filename, int argc)
{
	char	*file_content;
	char	*clean_file_content;

	argument_validation(filename, argc, mlx);
	file_content = read_map_file(filename);
	clean_file_content = map_tab_to_space(file_content);
	map_to_doublearray(mlx, clean_file_content);
	map_path_file_validation(mlx);
	validate_map(mlx);
	init_floor_celing_colors(mlx);
	define_player_direction(mlx);
	init_textures(mlx);
}
