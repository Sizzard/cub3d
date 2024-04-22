/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facarval <facarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 10:19:35 by facarval          #+#    #+#             */
/*   Updated: 2024/04/22 14:16:36 by facarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_data(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
	{
		ft_printfd(2, "Error\nMlx pointer creation failed\n");
		ft_end_process(data, FAILURE);
	}
	mlx_get_screen_size(data->mlx_ptr, &data->screen_size_x,
		&data->screen_size_y);
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->screen_size_x,
			data->screen_size_y, "Cub3d");
	if (!data->win_ptr)
	{
		ft_printfd(2, "Error\nMlx window creation failed\n");
		ft_end_process(data, FAILURE);
	}
}

void	ft_create_img_display(t_data *data)
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
	data->img.str = (int *)mlx_get_data_addr(data->img.ptr, &data->img.bits,
			&data->img.size_line, &data->img.endian);
	if (!data->img.str)
	{
		ft_end_process(data, FAILURE);
	}
}

void	ft_draw_scene(t_data *data)
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

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 1)
	{
		(void)argv;
		ft_printfd(2, "Error\nArgs\n");
		return (FAILURE);
	}
	ft_memset(&data, 0, sizeof(t_data));
	data.dir_x = 1;
	data.plane_y = 0.66;
	init_data(&data);
	create_map(&data);
	ft_create_img_display(&data);
	ft_create_buffer_img(&data);
	ft_draw_scene(&data);
	ft_create_img_wall(&data);
	ft_raycasting(&data);
	ft_draw_minimap(&data);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img.ptr, 0, 0);
	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy,
		&data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &on_keypress, &data);
	mlx_loop(data.mlx_ptr);
	return (SUCCESS);
}
