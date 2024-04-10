CFLAGS = -Wall -Wextra -Werror -g3
MLXFLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11
NAME = cub3d
SRC = src/parsing.c src/raycasting.c src/move.c src/colision.c src/utils.c\
	main.c
OBJETS = $(SRC:.c=.o)

all : libft/libft.a minilibx-linux/libmlx_Linux.a $(NAME) 

libft/libft.a :
	make -C libft

minilibx-linux/libmlx_Linux.a :
	make -C minilibx-linux

$(NAME) : $(OBJETS) libft/libft.a cub3d.h
	cc $(CFLAGS) -o $(NAME) $(OBJETS) -Lminilibx-linux -lmlx -L/usr/lib/X11 -lXext -lX11 libft/libft.a -lm

%.o:%.c
	cc $(CFLAGS) -c -o $@ $<

clean :
	rm -f $(OBJETS)
	make -C libft clean
	make -C minilibx-linux clean

fclean :
	rm -f $(NAME)
	rm -f $(OBJETS)
	make -C libft fclean
	make -C minilibx-linux clean

re : fclean all

.PHONY : all clean fclean re