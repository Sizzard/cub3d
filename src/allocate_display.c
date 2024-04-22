/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_display.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facarval <facarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:13:49 by facarval          #+#    #+#             */
/*   Updated: 2024/04/22 15:14:53 by facarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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

void	ft_init_img(t_data *data)
{
	ft_create_img_display(data);
	ft_create_buffer_img(data);
}
