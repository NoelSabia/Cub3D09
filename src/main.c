/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 12:38:53 by nsabia            #+#    #+#             */
/*   Updated: 2024/10/25 15:58:11 by nsabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	clean_exit(char *str, t_mlx *mlx)
{
	printf("Error\n");
	printf("%s\n", str);
	if (mlx->parse->north_tex)
		mlx_delete_texture(mlx->parse->north_tex);
	if (mlx->parse->south_tex)
		mlx_delete_texture(mlx->parse->south_tex);
	if (mlx->parse->west_tex)
		mlx_delete_texture(mlx->parse->west_tex);
	if (mlx->parse->east_tex)
		mlx_delete_texture(mlx->parse->east_tex);
	ft_free_all();
	exit(EXIT_FAILURE);
}

t_mlx	*initalize_structs(void)
{
	t_mlx	*mlx;

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
	start_game(mlx);
	ft_free_all();
	if (mlx->parse->north_tex)
		mlx_delete_texture(mlx->parse->north_tex);
	if (mlx->parse->south_tex)
		mlx_delete_texture(mlx->parse->south_tex);
	if (mlx->parse->west_tex)
		mlx_delete_texture(mlx->parse->west_tex);
	if (mlx->parse->east_tex)
		mlx_delete_texture(mlx->parse->east_tex);
	return (0);
}
