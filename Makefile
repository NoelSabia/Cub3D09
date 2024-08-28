NAME := cub3D

CFLAGS = -Wextra -Wall #-Werror  //dont forget to uncomment!!

HEADERS := -I ./include -I ./libft -I ./MLX/include

SRCDIR := ./src/
SRCS := $(SRCDIR)main.c \
		$(SRCDIR)init.c \
		$(SRCDIR)wall_render/floor_ceiling_color.c \
		$(SRCDIR)wall_render/floor_ceiling_helper.c \
		$(SRCDIR)parsing/parsing.c \
		$(SRCDIR)parsing/flood_fill.c \
		$(SRCDIR)parsing/flood_fill_preparation.c \
		$(SRCDIR)parsing/flood_fill_helpers.c \
		$(SRCDIR)parsing/fill_struct.c \
		$(SRCDIR)parsing/fill_struct_helpers.c \
		$(SRCDIR)player_movement/player_movement.c \
		$(SRCDIR)raycasting/minimap.c


OBJDIR := ./obj/
OBJS := $(SRCS:$(SRCDIR)%.c=$(OBJDIR)%.o)

CC := cc

MLX_LIB		= ./MLX42/build/libmlx42.a
MLX_PATH	= ./MLX42
MLX			= -ldl -lglfw -pthread -lm
MLX_DIR = MLX42
# MLX = $(MLX_DIR)/build/libmlx42.a
# MLX_FLAGS = -L$(MLX_DIR)/build -lmlx42 -framework Cocoa -framework OpenGL -framework IOKit -lglfw

.PHONY: all clean fclean re

all: $(NAME)

libft/libft.a:
	@$(MAKE) -C libft

$(MLX):
	@cd $(MLX_DIR)/build && cmake .. && make -j4

$(OBJDIR)%.o: $(SRCDIR)%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -I$(MLX_PATH)/include -c $< -o $@ $(HEADERS)

$(NAME): $(MLX_LIB) $(OBJS) libft/libft.a
	$(CC) $(OBJS) $(MLX_LIB) $(MLX) -o $(NAME) -Llibft -lft

# $(NAME): $(OBJS) libft/libft.a $(MLX)
# 	$(CC) $(OBJS) -o $(NAME) -Llibft -lft $(MLX_FLAGS)

$(MLX_LIB):
	git clone https://github.com/codam-coding-college/MLX42.git $(MLX_PATH)
	mkdir -p $(MLX_PATH)/build
	cd $(MLX_PATH)/build && cmake ..
	make -C $(MLX_PATH)/build

clean:
	@$(MAKE) -C libft clean
	@$(MAKE) -C $(MLX_DIR)/build clean
	@rm -rf $(OBJDIR)

fclean: clean
	@$(MAKE) -C libft fclean
	@rm -rf $(NAME)
	@rm -rf $(MLX_PATH)

re: fclean all

run: all
	./$(NAME)

rerun: re run

norm:
	@cd src && norminette | grep "Error:" | wc -l

norminette: norm