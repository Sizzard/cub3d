/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facarval <facarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 10:12:39 by facarval          #+#    #+#             */
/*   Updated: 2024/04/10 15:51:01 by facarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define SUCCESS 0
# define FAILURE 1

# define FALSE 0
# define TRUE 1

# define PI 3.141592

# define FOV 60

enum
{
	UP = 0,
	LEFT = 1,
	DOWN = 2,
	RIGHT = 3,
};

typedef struct s_pixel
{
	int				x;
	int				y;
}					t_pixel;

typedef struct s_rgb
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
}					t_rgb;

typedef struct s_img
{
	void			*ptr;
	char			*str;
	int				bits;
	int				size_line;
	int				endian;
}					t_img;

typedef struct s_wall
{
	void			*wall_n;
	void			*wall_s;
	void			*wall_e;
	void			*wall_w;
}					t_wall;

typedef struct s_player
{
	double			x1;
	double			y1;
	double			x2;
	double			y2;
	double			pos_x;
	double			pos_y;
}					t_player;

typedef struct t_wall
{
	t_player		player;
	t_pixel			pixel;
	t_wall			wall;
	t_img			img;
	void			*mlx_ptr;
	void			*win_ptr;
	char			**map;
	int				screen_size_x;
	int				screen_size_y;
	int				x_len;
	int				y_len;
	double			dir_x;
	double			dir_y;
}					t_data;

/*						Parsing						*/
void				create_map(t_data *data);

/*						Draw						*/
void				ft_draw_minimap(t_data *data);

/*						Raycasting					*/
void				ft_raycasting(t_data *data);

/*						Move						*/
void				ft_move(int keysym, t_data *data);
int					ft_is_colision(t_data *data, int direction);

/*						Utils						*/
int					ft_convert(double nb);

#endif