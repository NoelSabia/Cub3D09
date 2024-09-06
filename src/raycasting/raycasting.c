/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 11:57:45 by nsabia            #+#    #+#             */
/*   Updated: 2024/09/06 15:27:13 by nsabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	minimap_draw_line(t_mlx *mlx, float x_coord, float y_coord);

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
	mlx->ply->ply_x_coord = (mlx->parse->ply_x_pos_in_map) * TILE_SIZE + TILE_SIZE / 2;
	mlx->ply->ply_y_coord = (mlx->parse->ply_y_pos_in_map) * TILE_SIZE + TILE_SIZE / 2;
    mlx->ply->most_left_angle = mlx->ply->player_angle - (FOV / 2);
    mlx->ply->most_right_angle = mlx->ply->most_left_angle + FOV;
    if (mlx->ply->most_left_angle < 0)
        mlx->ply->most_left_angle += 360;
    if (mlx->ply->most_right_angle < 0)
        mlx->ply->most_right_angle += 360;
}

bool	intersec_check(float main_ray_angle, float *intersec, float *step, bool is_w_to_east)
{
	if (is_w_to_east == true)
	{
		if (main_ray_angle > 90 && main_ray_angle < 270)
		{
			*intersec += TILE_SIZE;
			return (false);
		}
		*step *= -1;
	}
	if (is_w_to_east == false)
	{
		if (!(main_ray_angle > 180 && main_ray_angle < 360))
		{
			*intersec += TILE_SIZE;
			return (false);
		}
		*step *= -1;
	}
	return (true);
}

bool	unit_circle(float main_ray_angle, bool horizontal)
{
	if (horizontal == true)
		if (main_ray_angle > 90 && main_ray_angle < 270)
			return (true);
	if (horizontal == false)
		if (main_ray_angle > 180 && main_ray_angle < 360)
			return (true);
	return (false);
}

//rewrite
bool	wall_hit(float x, float y, t_mlx *mlx)
{
	int  x_m;
	int  y_m;

	if (x < 0 || y < 0)
		return (false);
	x_m = floor (x / TILE_SIZE);
	y_m = floor (y / TILE_SIZE);
	if ((y_m >= mlx->parse->cols || x_m >= mlx->parse->rows))
		return (false);
	if (mlx->parse->map[y_m] && x_m <= (int)strlen(mlx->parse->map[y_m]))
		if (mlx->parse->map[y_m][x_m] == '1')
			return (false);
	return (true);
}

double	get_y_inter(t_mlx *mlx, double main_ray_angle)
{
	float	intersec_x;
	float	intersec_y;
	float	x_step;
	float	y_step;
	int		pixel;

	y_step = TILE_SIZE;
	x_step = TILE_SIZE / tan(degree_to_rad((float)main_ray_angle));
	intersec_y = floor(mlx->ply->ply_y_coord / TILE_SIZE) * TILE_SIZE;
	pixel = intersec_check(main_ray_angle, &intersec_y, &y_step, true);
	intersec_x = mlx->ply->ply_x_coord + (intersec_y - mlx->ply->ply_y_coord) / tan(degree_to_rad((float)main_ray_angle));
	if((unit_circle(main_ray_angle, false) && x_step > 0) || (!unit_circle(main_ray_angle, false) && x_step < 0))
		x_step *= -1;
	while (wall_hit(intersec_x, intersec_y - pixel, mlx))
	{
		intersec_x += x_step;
		intersec_y += y_step;
	}
	return (sqrt(pow(intersec_x - mlx->ply->ply_x_coord, 2) + pow(intersec_y - mlx->ply->ply_y_coord, 2)));
}

double	get_x_inter(t_mlx *mlx, double main_ray_angle)
{
	float	intersec_x;
	float	intersec_y;
	float	x_step;
	float	y_step;
	int		pixel;

	x_step = TILE_SIZE;
	y_step = TILE_SIZE * tan(degree_to_rad((float)main_ray_angle));
	// printf("-->y_step: %f\n", degree_to_rad((float)main_ray_angle));
	intersec_x = floor(mlx->ply->ply_x_coord / TILE_SIZE) * TILE_SIZE;
	// printf("1intersec_x: %f \n", intersec_x);
	pixel = intersec_check(main_ray_angle, &intersec_x, &x_step, false);
	// printf("pixel: %d\n", pixel);
	intersec_y = mlx->ply->ply_y_coord + (intersec_x - mlx->ply->ply_x_coord) * tan(degree_to_rad((float)main_ray_angle));
	// printf("1intersec_y: %f\n", intersec_y);
	if ((unit_circle(main_ray_angle, true) && x_step > 0) || (!unit_circle(main_ray_angle, true) && x_step < 0))
		y_step *= -1;
	// printf("1intersec_x: %f ", intersec_x);
	// printf("1intersec_y: %f ", intersec_y);
	// printf("\n");
	while (wall_hit(intersec_x - pixel, intersec_y, mlx))
	{
		intersec_x += x_step;
		// printf("intersec_x: %f ", intersec_x);
		// printf("x_step: %f\n", x_step);
		intersec_y += y_step;
		// printf("intersec_y: %f ", intersec_y);
		// printf("y_step: %f\n", y_step);
	}
	// printf("\n");
	return (sqrt(pow(intersec_x - mlx->ply->ply_x_coord, 2) + pow(intersec_y - mlx->ply->ply_y_coord, 2)));
}

float num_check(float angle)
{
    if (angle < 0)
        angle += 360;
    if (angle >= 360)
        angle -= 360;
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
	while (i < RAY_LIMIT)
	{
		x_coord = get_x_inter(mlx, num_check(mlx->ray->main_ray));
		y_coord = get_y_inter(mlx, num_check(mlx->ray->main_ray));
		printf("x: %f y: %f main_ray: %f\n", x_coord, y_coord, mlx->ray->main_ray);
		i++;
		mlx->ray->main_ray = num_check(mlx->ray->main_ray + ((double)FOV / (double)RAY_LIMIT));
		// minimap_draw_line(mlx, x_coord, y_coord);
	}
}


//Programflow:
//1) raycasting is initalized means -> we init the values in the struct player like the angle or FOV
//2) 