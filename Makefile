CFLAGS = -Wall -Wextra -Werror -g3
MLXFLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11
NAME = cub3D
SRC = src/fabio_parsing.c \
	src/parsing_create_map.c \
	src/parsing_check_map.c \
	src/parsing_check_map_utils.c \
	src/parsing_check_map_utils2.c \
	src/parsing_clean_data.c \
	src/parsing_data.c \
	src/parsing_data_check_line.c \
	src/parsing_data_utils.c \
	src/parsing_free.c \
	src/parsing_init.c \
	src/parsing_utils.c \
	src/parsing_prepare_data.c \
	src/allocate_walls.c \
	src/allocate_display.c \
	src/minimap.c src/raycasting.c \
	src/raycasting_2.c \
	src/movements.c \
	src/camera_rotation.c \
	src/colision.c \
	src/draw.c \
	src/end_process.c \
	src/mlx.c \
	main.c
OBJETS = $(SRC:.c=.o)

CLEANLINE=\33[2K

GREEN=\033[0;32m
BLUE=\033[0;34m
YELLOW=\033[0;33m
RED=\033[0;31m
NC=\033[0m

all : libft/libft.a minilibx-linux/libmlx_Linux.a $(NAME) 

libft/libft.a :
	@make -C libft

minilibx-linux/libmlx_Linux.a :
	@rm -rf minilibx-linux
	@git clone https://github.com/42Paris/minilibx-linux.git
	@make -C minilibx-linux

$(NAME) : $(OBJETS) libft/libft.a cub3d.h
	@cc $(CFLAGS) -o $(NAME) $(OBJETS) -Lminilibx-linux -lmlx -L/usr/lib/X11 -lXext -lX11 libft/libft.a -lm
	@echo "$(GREEN)Compilation OK$(NC)"

%.o:%.c
	@cc $(CFLAGS) -c -o $@ $<

clean :
	@rm -f $(OBJETS)
	@make -C libft clean
	@make -C minilibx-linux clean
	@echo "$(BLUE)Clean OK$(NC)"

fclean :
	@rm -f $(NAME)
	@rm -f $(OBJETS)
	@make -C libft fclean
	@make -C minilibx-linux clean
	@echo "$(YELLOW)Fclean OK$(NC)"

re : fclean all

.PHONY : all clean fclean re