/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facarval <facarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 10:19:35 by facarval          #+#    #+#             */
/*   Updated: 2024/04/17 15:41:23 by facarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free(void **ptr)
{
	if (*ptr)
	{
		free(*ptr);
	}
	*ptr = NULL;
}

void	ft_free_map(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_free((void **)&(str[i]));
		i++;
	}
	ft_free((void **)&str);
}

void	ft_end_process(t_data *data, int exit_code)
{
	ft_free_map(data->map);
	if (data->img.ptr)
		mlx_destroy_image(data->mlx_ptr, data->img.ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	ft_free((void **)&data->mlx_ptr);
	exit(exit_code);
}

int	on_destroy(t_data *data)
{
	ft_end_process(data, SUCCESS);
	return (0);
}

int	on_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		on_destroy(data);
	if (keysym == XK_w || keysym == XK_a || keysym == XK_s || keysym == XK_d
		|| keysym == XK_Left || keysym == XK_Right)
		ft_move(keysym, data);
	return (0);
}

void	init_data(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
	{
		ft_printfd(2, "Error\nMlx pointer creation failed");
		ft_end_process(data, FAILURE);
	}
	mlx_get_screen_size(data->mlx_ptr, &data->screen_size_x,
		&data->screen_size_y);
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->screen_size_x,
			data->screen_size_y, "Cub3d");
	if (!data->win_ptr)
	{
		ft_printfd(2, "Error\nMlx window creation failed");
		ft_end_process(data, FAILURE);
	}
}

void	ft_put_pixel_in_image(t_data *data, int color, int x, int y)
{
	const int	x_len = data->screen_size_x;

	((int *)data->img.str)[x + (x_len * y)] = color;
}

void	ft_create_img(t_data *data)
{
	data->img.ptr = mlx_new_image(data->mlx_ptr, data->screen_size_x,
			data->screen_size_y);
	if (!data->img.ptr)
	{
		ft_end_process(data, FAILURE);
	}
}

void	ft_create_buffer_img(t_data *data)
{
	data->img.str = mlx_get_data_addr(data->img.ptr, &data->img.bits,
			&data->img.size_line, &data->img.endian);
	if (!data->img.str)
	{
		ft_end_process(data, FAILURE);
	}
}

void	ft_fill_image(t_data *data)
{
	while (data->pixel.y < data->screen_size_y / 2)
	{
		while (data->pixel.x < data->screen_size_x)
		{
			ft_put_pixel_in_image(data, 0x33c1ff, data->pixel.x, data->pixel.y);
			data->pixel.x++;
		}
		data->pixel.x = 0;
		data->pixel.y++;
	}
	while (data->pixel.y < data->screen_size_y)
	{
		while (data->pixel.x < data->screen_size_x)
		{
			ft_put_pixel_in_image(data, 0xdb7820, data->pixel.x, data->pixel.y);
			data->pixel.x++;
		}
		data->pixel.x = 0;
		data->pixel.y++;
	}
	data->pixel.y = 0;
}

void	ft_draw_scene(t_data *data)
{
	ft_fill_image(data);
	// mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.ptr,0,0);
}

void	ft_print_block(t_data *data, t_mini mini, int counter_x, int counter_y)
{
	int			i;
	int			j;
	const int	screen_len = data->screen_size_x / 50;

	i = counter_x * screen_len;
	j = counter_y * screen_len;
	while (j < screen_len * counter_y + screen_len - 1)
	{
		while (i < screen_len * counter_x + screen_len - 1)
		{
			if (mini.y < 0 || mini.x < 0)
				return ;
			else if (data->map[mini.y]
				&& (int)ft_strlen(data->map[mini.y]) > mini.x
				&& data->map[mini.y][mini.x] == '1')
			{
				ft_put_pixel_in_image(data, 0x000000, i, j);
			}
			else if (data->map[mini.y]
				&& (int)ft_strlen(data->map[mini.y]) > mini.x
				&& data->map[mini.y][mini.x] == '0')
			{
				ft_put_pixel_in_image(data, 0x754131, i, j);
			}
			i++;
		}
		i = counter_x * screen_len;
		j++;
	}
}

void	ft_draw_player(t_data *data)
{
	int			i;
	int			j;
	const int	screen_len = data->screen_size_x / 50;

	i = screen_len * 3;
	j = screen_len * 3;
	while (j < screen_len * 3 + screen_len - 1)
	{
		while (i < screen_len * 3 + screen_len - 1)
		{
			if (data)
				ft_put_pixel_in_image(data, 0xf6f916, i, j);
			i++;
		}
		i = screen_len * 3;
		j++;
	}
}

void	ft_draw_minimap(t_data *data)
{
	t_mini	mini;
	int		counter_x;
	int		counter_y;

	counter_y = 1;
	counter_x = 1;
	mini.start_x = (int)data->player.pos_x - 2;
	mini.start_y = (int)data->player.pos_y - 2;
	mini.x = mini.start_x;
	mini.y = mini.start_y;
	while (mini.y < mini.start_y + 5)
	{
		while (mini.x < mini.start_x + 5)
		{
			ft_print_block(data, mini, counter_x, counter_y);
			mini.x++;
			counter_x++;
		}
		mini.x = mini.start_x;
		counter_x = 1;
		counter_y++;
		mini.y++;
	}
	ft_draw_player(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.ptr, 0, 0);
}

void	ft_draw_walls(t_data *data)
{
	(void)data;
	// data->wall.wall_e = mlx_xpm_file_to_image(data->mlx_ptr,
	// 		"textures/Mousse_sombre.xpm", &data->pixel.x, &data->pixel.y);
	// data->wall.wall_w = mlx_xpm_file_to_image(data->mlx_ptr,
	// 		"textures/Mur_sombre.xpm", &data->pixel.x, &data->pixel.y);
	// data->wall.wall_n = mlx_xpm_file_to_image(data->mlx_ptr,
	// 		"textures/Mousse_claire.xpm", &data->pixel.x, &data->pixel.y);
	// data->wall.wall_s = mlx_xpm_file_to_image(data->mlx_ptr,
	// 		"textures/Mur_clair.xpm", &data->pixel.x, &data->pixel.y);
}

void	print_map(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		printf("%s\n", str[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 1)
	{
		(void)argv;
		ft_printfd(2, "Error\nArgs\n");
		return (1);
	}
	ft_memset(&data, 0, sizeof(t_data));
	data.dirX = 1;
	data.planeY = 0.66;
	init_data(&data);
	create_map(&data);
	ft_create_img(&data);
	ft_create_buffer_img(&data);
	ft_draw_scene(&data);
	ft_draw_walls(&data);
	ft_raycasting(&data);
	ft_draw_minimap(&data);
	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy,
		&data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &on_keypress, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
