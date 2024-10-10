/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:57:54 by tpaesch           #+#    #+#             */
/*   Updated: 2024/10/10 14:58:59 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_vert(t_mlx *mlx)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	j = 1;
	while (k < (mlx->parse->rows))
	{
		while (i < minimap_dynamic_scale(mlx) * (mlx->parse->cols))
		{
			mlx_put_pixel(mlx->ray->minimap,
				minimap_dynamic_scale(mlx) * j, i, 0xFFFFFFFF);
			i++;
		}
		i = 0;
		j++;
		k++;
	}
}

void	draw_horiz(t_mlx *mlx)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	j = 1;
	while (k < (mlx->parse->cols))
	{
		while (i < minimap_dynamic_scale(mlx) * (mlx->parse->rows))
		{
			mlx_put_pixel(mlx->ray->minimap, i,
				minimap_dynamic_scale(mlx) * j, 0xFFFFFFFF);
			i++;
		}
		i = 0;
		j++;
		k++;
	}
}

void	put_block(t_mlx *mlx, int i, int j)
{
	int		i_end;
	int		j_end;
	int		j_zero;

	j_zero = j;
	i_end = i + minimap_dynamic_scale(mlx);
	j_end = j + minimap_dynamic_scale(mlx);
	while (i < i_end)
	{
		while (j < j_end)
		{
			mlx_put_pixel(mlx->ray->minimap, i, j, 0xFFFFFFFF);
			j++;
		}
		j = j_zero;
		i++;
	}
}

void	draw_walls(t_mlx *mlx)
{
	int	i;
	int	j;
	int	len_for_draw;

	i = 0;
	len_for_draw = minimap_dynamic_scale(mlx);
	while (i < mlx->parse->cols)
	{
		j = 0;
		while (j < mlx->parse->rows)
		{
			if (mlx->parse->map[i][j] == '1')
			{
				put_block(mlx, j * len_for_draw, i * len_for_draw);
			}
			j++;
		}
		i++;
	}
}
