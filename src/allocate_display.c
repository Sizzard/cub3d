/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_display.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facarval <facarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:13:49 by facarval          #+#    #+#             */
/*   Updated: 2024/06/07 01:39:54 by facarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_create_img_display(t_data *data, t_parse *p)
{
	data->img.ptr = mlx_new_image(data->mlx_ptr, data->screen_size_x,
			data->screen_size_y);
	if (!data->img.ptr)
	{
		ft_free_map(p->map);
		ft_end_process(data, FAILURE);
	}
}

void	ft_create_buffer_img(t_data *data, t_parse *p)
{
	data->img.str = (int *)mlx_get_data_addr(data->img.ptr, &data->img.bits,
			&data->img.size_line, &data->img.endian);
	if (!data->img.str)
	{
		ft_free_map(p->map);
		ft_end_process(data, FAILURE);
	}
}

void	ft_init_img(t_data *data, t_parse *p)
{
	data->no = ft_strndup(p->no, 0, ft_strlen(p->no) - 2);
	ft_free((void **)&p->no);
	if (!data->no)
	{
		ft_error_parse(p);
		ft_end_process(data, FAILURE);
	}
	data->so = ft_strndup(p->so, 0, ft_strlen(p->so) - 2);
	ft_free((void **)&p->so);
	if (!data->so)
	{
		ft_error_parse(p);
		ft_end_process(data, FAILURE);
	}
	data->we = ft_strndup(p->we, 0, ft_strlen(p->we) - 2);
	ft_free((void **)&p->we);
	if (!data->we)
	{
		ft_error_parse(p);
		ft_end_process(data, FAILURE);
	}
	data->ea = ft_strndup(p->ea, 0, ft_strlen(p->ea) - 2);
	ft_free((void **)&p->ea);
	if (!data->ea)
	{
		ft_error_parse(p);
		ft_end_process(data, FAILURE);
	}
	data->c = p->ceiling_hexa;
	ft_free((void **)&p->ceiling);
	data->f = p->floor_hexa;
	ft_free((void **)&p->floor);
	ft_create_img_display(data, p);
	ft_create_buffer_img(data, p);
}
