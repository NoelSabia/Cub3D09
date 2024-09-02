/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 11:57:45 by nsabia            #+#    #+#             */
/*   Updated: 2024/09/02 17:39:57 by nsabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

float	rad_to_degree(float radian)
{
	float	degree;

	degree = radian * (180 / M_PI);
	return (degree);
}

float	degree_to_rad(float degree)
{
	float	radians;

	radians = degree * (M_PI / 180);
	return (radians);
}

void	raycasting_init(t_mlx *mlx)
{
    mlx->ply->most_left_angle = mlx->ply->player_angle - (FOV / 2);
    mlx->ply->most_right_angle = mlx->ply->most_left_angle + FOV;

    if (mlx->ply->most_left_angle < 0)
        mlx->ply->most_left_angle += 360;
    if (mlx->ply->most_right_angle < 0)
        mlx->ply->most_right_angle += 360;
}

double	get_y_inter(t_mlx *mlx, double main_ray)
{

}

double	get_x_inter(t_mlx *mlx, double main_ray)
{
	float	intersec_x;
	float	intersec_y;
	float	x_step;
	float	y_step;

	
}

float	num_check(float angle)
{
	if (angle < 0)
		angle += 359;
	if (angle > 359)
		angle -= 359;
	return (angle);
}

//Important Information:
//Im using degrees instead of radians for my unit square
//BUT because sin(), cos() and tan() expect angles in radians we need to convert them
//therefore we have the functions convert_degrees_to_radians() and otherwise
void	raycasting(t_mlx *mlx)
{
	int		i;
	double	y_coord;
	double	x_coord;

	i = 0;
	mlx->ray->main_ray = mlx->ply->most_left_angle;
	while (i < SCREEN_WIDTH)
	{
		x_coord = get_x_inter(mlx, num_check(mlx->ray->main_ray));
		y_coord = get_y_inter(mlx, num_check(mlx->ray->main_ray));
	}
}


//Programflow:
//1) raycasting is initalized means -> we init the values in the struct player like the angle or FOV
//2) 