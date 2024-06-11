/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facarval <facarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 10:12:39 by facarval          #+#    #+#             */
/*   Updated: 2024/06/11 13:53:47 by facarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "./libft/libft.h"
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
	int				x;
	int				y;
}					t_pixel;

typedef struct s_img
{
	void			*ptr;
	int				*str;
	int				bits;
	int				size_line;
	int				endian;
}					t_img;

typedef struct s_wall
{
	void			*wall_n_img;
	int				*n_str;
	void			*wall_s_img;
	int				*s_str;
	void			*wall_e_img;
	int				*e_str;
	void			*wall_w_img;
	int				*w_str;
}					t_wall;

typedef struct s_mini
{
	int				x;
	int				y;
	int				start_x;
	int				start_y;
}					t_mini;

typedef struct s_player
{
	double			pos_x;
	double			pos_y;
	double			plane_x;
	double			plane_y;
	double			time;
	double			old_time;
}					t_player;

typedef struct s_raycast
{
	int				x;
	int				map_x;
	int				map_y;
	double			camera_x;
	double			raydir_x;
	double			raydir_y;
	double			sidedist_x;
	double			sidedist_y;
	double			deltadist_x;
	double			deltadist_y;
	double			perpwalldist;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
	int				lineheight;
	int				drawstart;
	int				drawend;
	double			w;
	double			h;
	double			wall_x;
	int				tex_x;
	double			step;
	double			texpos;
	int				tex_y;
	int				color;
}					t_raycast;

typedef struct s_data
{
	t_player		player;
	t_pixel			pixel;
	t_wall			wall;
	t_img			img;
	int				color;
	void			*mlx_ptr;
	void			*win_ptr;
	char			**map;
	int				screen_size_x;
	int				screen_size_y;
	int				x_len;
	int				y_len;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	char			*no;
	char			*so;
	char			*ea;
	char			*we;
	char			character;
	unsigned long	c;
	unsigned long	f;
}					t_data;

typedef struct s_parse
{
	int				nb_data;
	int				nb_line_map;
	char			*line;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*floor;
	char			*ceiling;
	char			**map;
	unsigned long	ceiling_hexa;
	unsigned long	floor_hexa;
	int				nb_start;
}					t_parse;

/*						Parsing data
 */
void				create_map(t_data *data, t_parse *p);
int					ft_count_line_map(t_parse *p, char *str);
int					ft_init_parse(t_parse *p);
int					ft_parse_data_file(t_parse *p, char *str);
int					ft_check_line(t_parse *p);
int					ft_is_no(t_parse *p);
int					ft_is_so(t_parse *p);
int					ft_is_we(t_parse *p);
int					ft_is_ea(t_parse *p);
int					ft_is_f(t_parse *p);
int					ft_is_c(t_parse *p);
int					ft_empty_line(char *str);
int					ft_empty_line_end(char *str);

/*						Parsing	map create
 */
int					ft_create_map(int fd, t_parse *p);
int					ft_check_map(char **map, t_parse *p);
int					ft_char_is_checkable(char c);
int					ft_char_is_ok(char c);
int					ft_char_is_wrong(char c);
int					ft_char_is_start(char c);
int					ft_first_line(char **map, int i);
int					ft_last_line(char **map, int i);

/*						Parsing utils
 */
int					ft_atorgb(char *str);
void				ft_free_tabtab(char **str);
int					ft_check_coma(char *str);
int					ft_check_fd(char *str);
int					ft_check_rgb(char *str);
int					ft_count_words_parse(const char *s, char c, t_parse *p);
int					ft_count_nb_rgb(char *str);
void				ft_prepare_data(t_parse *p);
void				ft_clean_struct(t_parse *p);
void				ft_remove_begin(char *str);
int					ft_epur_str(char *str);
void				ft_print_parse(t_parse *p);
void				ft_error_parse(t_parse *p);
void				ft_error_parse_begin(t_parse *p);
char				*ft_strndup(char *str, int begin, int end);

/*						Allocations
 */
void				ft_init_img(t_data *data, t_parse *p);
void				ft_create_img_wall(t_data *data);

/*						Draw
 */
void				ft_create_buffer_img(t_data *data, t_parse *p);
void				ft_put_pixel_in_image(t_data *data, int color, int x,
						int y);
void				ft_draw_minimap(t_data *data);
void				ft_draw_scene(t_data *data);
void				ft_draw_line(t_data *data, t_raycast *ray);

/*						MLX
 */
int					on_destroy(t_data *data);
int					on_keypress(int keysym, t_data *data);

/*						Raycasting
 */
void				ft_raycasting(t_data *data);
void				ft_init_raycasting(t_data *data, t_raycast *ray);
int					ft_check_side(int side, double ray_x, double ray_y, char c);

/*						Movements
 */
void				ft_move(int keysym, t_data *data);
int					ft_is_colision(t_data *data, int direction);
void				ft_rotation(int keysym, t_data *data);

/*						End of process
 */
void				ft_free(void **ptr);
void				ft_free_map(char **str);
void				ft_end_process(t_data *data, int exit_code);

#endif