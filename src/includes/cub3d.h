/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 12:39:19 by nsabia            #+#    #+#             */
/*   Updated: 2024/10/01 09:47:36 by nsabia           ###   ########.fr       */
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

# include "../../libft/libft.h"
# include "../../MLX42/include/MLX42/MLX42.h"

# define SCREEN_WIDTH 1920
# define SCREEN_HEIGHT 1080
# define FOV 60
# define TILE_SIZE 50
# define RAY_LIMIT 120
# define ROTATION_SPEED M_PI / 80
# define MOVEMENT_SPEED 2

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
	int			wallhit_flag;
	double		distance_to_w;
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
void	verifyMapPathAndFile(t_mlx *mlx);
void	validateMap(t_mlx *mlx);
void	floodFillOrganizer(t_mlx *mlx);
void	parsing(t_mlx *mlx, char *filename, int argc);
void	floorAndCeilingColor(t_mlx *mlx);


/*Input reception*/
char	*clean_data(char *str);
int		get_floor_color(char *str_in, t_mlx *mlx, char *line);
int		get_celing_color(char *str_in, t_mlx *mlx, char *line);
int		graphic_path_west(char *str_in, t_mlx *mlx, char *line);
int		graphic_path_east(char *str_in, t_mlx *mlx, char *line);
int		graphic_path_north(char *str_in, t_mlx *mlx, char *line);
int		graphic_path_south(char *str_in, t_mlx *mlx, char *line);
void	check_if_exists(char *str1, char *str2, t_mlx *mlx, char *line);


/*Minimap*/
void	minimap_draw(t_mlx *mlx);
void	arrow_north(t_mlx *mlx);
void	arrow_east(t_mlx *mlx);
void	arrow_south(t_mlx *mlx);
void	arrow_west(t_mlx *mlx);

/*Main*/
void	clean_exit(char *str);
void	initalizeRaycasting(t_mlx *mlx);
void	raycasting(t_mlx *mlx);

#endif