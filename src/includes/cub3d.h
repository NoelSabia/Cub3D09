/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 12:39:19 by nsabia            #+#    #+#             */
/*   Updated: 2024/08/28 17:39:49 by tpaesch          ###   ########.fr       */
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
	double			angle;
	int				ply_x_coord;
	int				ply_y_coord;
}	t_player;

typedef struct raytracing
{
	mlx_image_t	*minimap;
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
void	fill_parse_struct(t_mlx *mlx);
void	validate_map(t_mlx *mlx);
void	flood_fill_organizer(t_mlx *mlx);
void	parsing(t_mlx *mlx, char *filename);

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


/*Main*/
void	clean_exit(char *str);

#endif