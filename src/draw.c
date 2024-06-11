/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facarval <facarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:13:09 by facarval          #+#    #+#             */
/*   Updated: 2024/06/11 17:00:34 by facarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_put_pixel_in_image(t_data *data, int color, int x, int y)
{
	const int	x_len = data->screen_size_x;

	data->img.str[x + (x_len * y)] = color;
}

void	ft_draw_scene(t_data *data)
{
	while (data->pixel.y < data->screen_size_y / 2)
	{
		while (data->pixel.x < data->screen_size_x)
		{
			ft_put_pixel_in_image(data, data->c, data->pixel.x, data->pixel.y);
			data->pixel.x++;
		}
		data->pixel.x = 0;
		data->pixel.y++;
	}
	while (data->pixel.y < data->screen_size_y)
	{
		while (data->pixel.x < data->screen_size_x)
		{
			ft_put_pixel_in_image(data, data->f, data->pixel.x, data->pixel.y);
			data->pixel.x++;
		}
		data->pixel.x = 0;
		data->pixel.y++;
	}
	data->pixel.y = 0;
}

void	ft_draw_line(t_data *data, t_raycast *ray)
{
	while (ray->drawstart < ray->drawend)
	{
		ray->tex_y = (int)ray->texpos & (TEXH - 1);
		ray->texpos += ray->step;
		if (ray->side == NORTH)
			ray->color = data->wall.n_str[(TEXH * ray->tex_y + ray->tex_x)];
		else if (ray->side == SOUTH)
			ray->color = data->wall.s_str[(TEXH * ray->tex_y + ray->tex_x)];
		else if (ray->side == WEST)
			ray->color = data->wall.w_str[(TEXH * ray->tex_y + ray->tex_x)];
		else if (ray->side == EAST)
			ray->color = data->wall.e_str[(TEXH * ray->tex_y + ray->tex_x)];
		ft_put_pixel_in_image(data, ray->color, ray->x, ray->drawstart);
		ray->drawstart++;
	}
}
