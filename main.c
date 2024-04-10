/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facarval <facarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 10:19:35 by facarval          #+#    #+#             */
/*   Updated: 2024/04/10 15:42:17 by facarval         ###   ########.fr       */
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
	if (keysym == XK_w || keysym == XK_a || keysym == XK_s || keysym == XK_d)
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
	if (data->img.ptr)
		mlx_destroy_image(data->mlx_ptr, data->img.ptr);
	ft_free((void **)&data->img.ptr);
	ft_create_img(data);
	ft_create_buffer_img(data);
	ft_fill_image(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.ptr, 0, 0);
}

void	ft_print_block(t_data *data, int x, int y)
{
	int	i;
	int	j;

	i = x * 64;
	j = y * 64;
	while (j < (y + 1) * 64)
	{
		while (i < (x + 1) * 64)
		{
			if (data->map[y][x] == '1')
			{
				ft_put_pixel_in_image(data, 0x000000, i, j);
			}
			else if (data->map[y][x] == '0' || data->map[y][x] == 'P')
			{
				ft_put_pixel_in_image(data, 0x754131, i, j);
			}
			i++;
		}
		i = x * 64;
		j++;
	}
}

void	ft_draw_player(t_data *data)
{
	int			i;
	int			j;
	const int	i2 = data->player.x2 * 64;
	const int	j2 = data->player.y2 * 64;

	i = data->player.x1 * 64;
	j = data->player.y1 * 64;
	while (j < j2)
	{
		while (i < i2)
		{
			if (data)
				ft_put_pixel_in_image(data, 0xf6f916, i, j);
			i++;
		}
		i = data->player.x1 * 64;
		j++;
	}
}

void	ft_draw_minimap(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (data->map[y])
	{
		while (data->map[y][x])
		{
			ft_print_block(data, x, y);
			x++;
		}
		x = 0;
		y++;
	}
	ft_draw_player(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.ptr, 0, 0);
}

void	ft_draw_walls(t_data *data)
{
	(void)data;
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
	init_data(&data);
	create_map(&data);
	// print_map(data.map);
	ft_draw_scene(&data);
	ft_draw_minimap(&data);
	ft_draw_walls(&data);
	ft_raycasting(&data);
	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy,
		&data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &on_keypress, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
