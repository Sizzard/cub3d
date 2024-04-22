/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facarval <facarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 10:12:39 by facarval          #+#    #+#             */
/*   Updated: 2024/04/22 17:20:27 by facarval         ###   ########.fr       */
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

# define TEXW 64
# define TEXH 64

enum
{
	UP = 0,
	LEFT = 1,
	DOWN = 2,
	RIGHT = 3,
};

enum
{
	NORTH = 0,
	WEST = 1,
	SOUTH = 2,
	EAST = 3,
};

typedef struct s_pixel
{
	int			x;
	int			y;
}				t_pixel;

typedef struct s_img
{
	void		*ptr;
	int			*str;
	int			bits;
	int			size_line;
	int			endian;
}				t_img;

typedef struct s_wall
{
	void		*wall_n_img;
	int			*n_str;
	void		*wall_s_img;
	int			*s_str;
	void		*wall_e_img;
	int			*e_str;
	void		*wall_w_img;
	int			*w_str;
}				t_wall;

typedef struct s_mini
{
	int			x;
	int			y;
	int			start_x;
	int			start_y;
}				t_mini;

typedef struct s_player
{
	double		pos_x;
	double		pos_y;
	double		plane_x;
	double		plane_y;
	double		time;
	double		old_time;
}				t_player;

typedef struct s_raycast
{
	int			x;
	int			map_x;
	int			map_y;
	double		camera_x;
	double		raydir_x;
	double		raydir_y;
	double		sidedist_x;
	double		sidedist_y;
	double		deltadist_x;
	double		deltadist_y;
	double		perpwalldist;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			lineheight;
	int			drawstart;
	int			drawend;
	double		w;
	double		h;
	double		wall_x;
	int			tex_x;
	double		step;
	double		texpos;
	int			tex_y;
	int			color;
}				t_raycast;

typedef struct t_wall
{
	t_player	player;
	t_pixel		pixel;
	t_wall		wall;
	t_img		img;
	int			color;
	void		*mlx_ptr;
	void		*win_ptr;
	char		**map;
	int			screen_size_x;
	int			screen_size_y;
	int			x_len;
	int			y_len;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
}				t_data;

/*						Parsing						*/
void			create_map(t_data *data);

/*						Allocations					*/
void			ft_init_img(t_data *data);

void			ft_create_img_wall(t_data *data);

/*						Draw						*/
void			ft_clear_window(t_data *data);
void			ft_create_buffer_img(t_data *data);
void			ft_put_pixel_in_image(t_data *data, int color, int x, int y);
void			ft_draw_minimap(t_data *data);
void			ft_draw_scene(t_data *data);
void			ft_draw_line(t_data *data, t_raycast *ray);

/*						MLX							*/
int				on_destroy(t_data *data);
int				on_keypress(int keysym, t_data *data);

/*						Raycasting					*/
void			ft_raycasting(t_data *data);
void			ft_init_raycasting(t_data *data, t_raycast *ray);
int				ft_check_side(int side, double ray_x, double ray_y);

/*						Movements						*/
void			ft_move(int keysym, t_data *data);
int				ft_is_colision(t_data *data, int direction);
void			ft_rotation(int keysym, t_data *data);

/*						End of process						*/
void			ft_free(void **ptr);
void			ft_free_map(char **str);
void			ft_end_process(t_data *data, int exit_code);

#endif