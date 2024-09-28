/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noel <noel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 12:38:53 by nsabia            #+#    #+#             */
/*   Updated: 2024/09/28 22:00:18 by noel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	init(t_mlx *mlx);

void	clean_exit(char *str)
{
	printf("Error\n");
	printf("%s\n", str);
	ft_free_all();
	exit(EXIT_FAILURE);
}

t_mlx *initalize_structs()
{
	t_mlx *mlx;

	mlx = ft_calloc(1, sizeof(t_mlx));
	mlx->parse = ft_calloc(1, sizeof(t_parsing));
	mlx->ply = ft_calloc(1, sizeof(t_player));
	mlx->ray = ft_calloc(1, sizeof(t_raytracing));
	mlx->key_data = ft_calloc(1, sizeof(mlx_key_data_t));
	return (mlx);
}

int	main(int argc, char *argv[])
{
	t_mlx	*mlx;

	mlx = initalize_structs();
	parsing(mlx, argv[1], argc);
	init(mlx);
	ft_free_all();
	return (0);
}