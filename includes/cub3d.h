/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 12:39:19 by nsabia            #+#    #+#             */
/*   Updated: 2024/10/15 10:44:03 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <stdbool.h>
# include <math.h>

# include "../libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"

# define SCREEN_WIDTH 1920
# define SCREEN_HEIGHT 1080
# define FOV 60
# define TILE_SIZE 50
# define RAY_LIMIT 1920
# define ROTATION_SPEED M_PI / (RAY_LIMIT / 50)
# define MOVEMENT_SPEED 15
# define WALL_SLICE_WIDTH (SCREEN_WIDTH / RAY_LIMIT)

/*Parsing*/
typedef struct s_parsing
{
	char			**input;
	int				input_counter;
	char			*north;
	char			*south;
	char			*west;
	char			*east;
	char			*floor;
	char			*ceiling;
	int				north_set;
	int				south_set;
	int				west_set;
	int				east_set;
	int				floor_set;
	int				ceiling_set;
	uint32_t		floor_color;
	uint32_t		ceiling_color;
	char			**map;
	int				ply_x_pos_in_map;
	int				ply_y_pos_in_map;
	int				rows;
	int				cols;
	mlx_texture_t	*north_tex;
	mlx_texture_t	*east_tex;
	mlx_texture_t	*south_tex;
	mlx_texture_t	*west_tex;
}	t_parsing;

typedef struct s_player
{
	float			most_left_angle;
	float			center_angle;
	float			most_right_angle;
	int				ply_x_coord;
	int				ply_y_coord;
	int				minimap_x_coord;
	int				minimap_y_coord;
	float			fov_rd;
	bool			looking_left;
	bool			looking_right;
	bool			pressing_w;
	bool			pressing_a;
	bool			pressing_s;
	bool			pressing_d;
}	t_player;

typedef struct raytracing
{
	mlx_image_t	*minimap;
	double		main_ray;
	bool		no_or_so_wallhit_flag;
	double		distance_to_w;
	float		horiz_x;
	float		horiz_y;
	float		vert_x;
	float		vert_y;
	int			ray_counter;
}	t_raytracing;

/*Mainstruct*/
typedef struct s_mlx
{
	mlx_image_t		*img;
	mlx_t			*mlx_p;
	mlx_key_data_t	*key_data;
	t_parsing		*parse;
	t_player		*ply;
	t_raytracing	*ray;
}	t_mlx;

/*Parsing*/
void	map_path_file_validation(t_mlx *mlx);
void	validate_map(t_mlx *mlx);
void	floodfill_organiser(t_mlx *mlx);
void	parsing(t_mlx *mlx, char *filename, int argc);
void	init_floor_celing_colors(t_mlx *mlx);
char	*read_map_file(char *filename);
char	*map_tab_to_space(const char *str);
void	map_to_doublearray(t_mlx *mlx, char *clean_file_content);
void	init_textures(t_mlx *mlx);

/*Input reception*/
char	*clean_data(char *str);
int		get_floor_color(char *str_in, t_mlx *mlx, char *line);
int		get_celing_color(char *str_in, t_mlx *mlx, char *line);
int		graphic_path_west(char *str_in, t_mlx *mlx, char *line);
int		graphic_path_east(char *str_in, t_mlx *mlx, char *line);
int		graphic_path_north(char *str_in, t_mlx *mlx, char *line);
int		graphic_path_south(char *str_in, t_mlx *mlx, char *line);
void	check_if_exists(char *str1, char *str2, t_mlx *mlx, char *line);

/*Movement*/
void	are_keys_released(mlx_key_data_t keydata, t_mlx *mlx);
void	look_left(mlx_key_data_t keydata, t_mlx *mlx);
void	look_right(mlx_key_data_t keydata, t_mlx *mlx);
void	update_player_position(t_mlx *mlx);

/*Math calculations*/
float	get_y_inter(t_mlx *mlx, float angl);
float	get_x_inter(t_mlx *mlx, float angl);
int		inter_check(float angle, float *inter, float *step, int is_horizon);
int		unit_circle(float angle, char c);
int		wall_hit(float x, float y, t_mlx *mlx);
void	calculate_wall_hight(t_mlx *mlx);

/*Minimap*/
void	minimap_draw(t_mlx *mlx);
void	draw_vert(t_mlx *mlx);
void	draw_horiz(t_mlx *mlx);
void	draw_walls(t_mlx *mlx);
void	arrow_north(t_mlx *mlx);
void	arrow_east(t_mlx *mlx);
void	arrow_south(t_mlx *mlx);
void	arrow_west(t_mlx *mlx);
int		minimap_dynamic_scale(t_mlx *mlx);

/*Main*/
void	start_game(t_mlx *mlx);
void	clean_exit(char *str);
void	init_raycasting(t_mlx *mlx);
void	raycasting(t_mlx *mlx);

#endif