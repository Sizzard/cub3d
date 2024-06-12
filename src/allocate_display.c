/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_display.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facarval <facarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:13:49 by facarval          #+#    #+#             */
/*   Updated: 2024/06/12 10:34:48 by facarval         ###   ########.fr       */
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

void	ft_error_dup_newline(t_data *data, t_parse *p)
{
	ft_error_parse(p);
	ft_end_process(data, FAILURE);
}

void	ft_remove_newline(t_data *data, t_parse *p)
{
	data->no = p->no;
	data->no[ft_strlen(data->no) - 1] = 0;
	data->so = p->so;
	data->so[ft_strlen(data->so) - 1] = 0;
	data->we = p->we;
	data->we[ft_strlen(data->we) - 1] = 0;
	data->ea = p->ea;
	data->ea[ft_strlen(data->ea) - 1] = 0;
}

void	ft_init_img(t_data *data, t_parse *p)
{
	ft_remove_newline(data, p);
	data->c = p->ceiling_hexa;
	ft_free((void **)&p->ceiling);
	data->f = p->floor_hexa;
	ft_free((void **)&p->floor);
	ft_create_img_display(data, p);
	ft_create_buffer_img(data, p);
}
