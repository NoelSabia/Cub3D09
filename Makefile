NAME := cub3D
CC = cc
CFLAGS := -Wextra -Wall -Werror -Ofast

LIBFTDIR := ./libft
LIBFT := $(LIBFTDIR)/libft.a

INCLUDEDIRS := includes \
               $(LIBMLXDIR)/include \
			   $(LIBFTDIR)
INCLUDES := $(addprefix -I, $(INCLUDEDIRS))
HEADERS := cub3d.h

LIBMLXDIR := ./MLX42
LIBMLX := $(LIBMLXDIR)/build/libmlx42.a
LIBS := $(LIBMLX)
ifeq ($(shell uname),Darwin)
	LIBS += -framework Cocoa -framework OpenGL -framework IOKit -lglfw
else ifeq ($(shell uname),Linux)
	LIBS += -ldl -lglfw -pthread -lm
endif

LIBS += -L$(LIBFTDIR) -lft

SRCDIRS := src \
		   src/floor_and_ceiling_render \
		   src/parsing \
		   src/player_movement \
		   src/raycasting \
		   src/wall_render

OBJDIR := obj

# Source files
SRCS = main.c \
	   init.c \
	   floor_ceiling_color.c \
	   floor_ceiling_init.c \
	   parsing.c \
	   flood_fill.c \
	   flood_fill_preparation.c \
	   flood_fill_helpers.c \
	   parse_map_file.c \
	   graphic_orientation.c \
	   player_movement.c \
	   minimap.c \
	   minimap_plyr_dir.c \
	   raycasting.c \
	   render_walls.c \
	   map_validation.c \
	   key_strokes.c \
	   draw_walls.c \
	   intersection_check.c \
	   texture_init.c \
	   validate_position.c


vpath %.c $(SRCDIRS)
vpath %.h $(INCLUDEDIRS)

OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(LIBMLX) $(LIBFT) $(OBJS)
	$(CC) $(OBJS) $(LIBS) -o $(NAME)

$(OBJDIR)/%.o: %.c $(HEADERS) | $(OBJDIR)
	@echo "Compiling $< to $@"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(LIBFT):
	@$(MAKE) -C $(LIBFTDIR)

$(LIBMLX):
	@if [ ! -d "$(LIBMLXDIR)" ]; then \
		git clone -b v2.3.4 https://github.com/codam-coding-college/MLX42.git $(LIBMLXDIR); \
	fi
	@if [ ! -d "$(LIBMLXDIR)/build" ]; then \
		mkdir -p $(LIBMLXDIR)/build; \
		cd $(LIBMLXDIR)/build && cmake .. && make -j4; \
	fi

clean:
	@$(MAKE) -C $(LIBFTDIR) clean
	@rm -rf $(OBJDIR)

fclean: clean
	@$(MAKE) -C $(LIBFTDIR) fclean
	@rm -rf $(NAME)
	@if [ -d "$(LIBMLXDIR)" ]; then \
		rm -rf $(LIBMLXDIR); \
	fi

re: fclean all

run: all
	./$(NAME)

rerun: re run

norm:
	@cd src && norminette | grep "Error:" | wc -l

norminette: norm

.PHONY: all clean fclean re run rerun norm norminette debug
