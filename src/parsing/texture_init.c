/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:37:46 by nsabia            #+#    #+#             */
/*   Updated: 2024/10/22 17:52:08 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_textures(t_mlx *mlx)
{
	mlx->parse->north_tex = mlx_load_png(mlx->parse->north);
	if (!mlx->parse->north_tex)
		clean_exit("Texturepath is wrong or Texture not available", mlx);
	mlx->parse->east_tex = mlx_load_png(mlx->parse->east);
	if (!mlx->parse->east_tex)
		clean_exit("Texturepath is wrong or Texture not available", mlx);
	mlx->parse->south_tex = mlx_load_png(mlx->parse->south);
	if (!mlx->parse->south_tex)
		clean_exit("Texturepath is wrong or Texture not available", mlx);
	mlx->parse->west_tex = mlx_load_png(mlx->parse->west);
	if (!mlx->parse->west_tex)
		clean_exit("Texturepath is wrong or Texture not available", mlx);
}
