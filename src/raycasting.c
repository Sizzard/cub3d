/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facarval <facarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:24:04 by facarval          #+#    #+#             */
/*   Updated: 2024/06/11 16:49:54 by facarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_dda(t_data *data, t_raycast *ray)
{
	while (ray->hit == 0)
	{
		if (ray->sidedist_x < ray->sidedist_y)
		{
			ray->sidedist_x += ray->deltadist_x;
			ray->map_x += ray->step_x;
			ray->side = FALSE;
		}
		else
		{
			ray->sidedist_y += ray->deltadist_y;
			ray->map_y += ray->step_y;
			ray->side = TRUE;
		}
		if (data->map[ray->map_y][ray->map_x] == '1')
			ray->hit = 1;
	}
	if (ray->side == 0)
	{
		ray->perpwalldist = (ray->sidedist_x - ray->deltadist_x);
	}
	else
	{
		ray->perpwalldist = (ray->sidedist_y - ray->deltadist_y);
	}
}

void	ft_find_texel_pos(t_data *data, t_raycast *ray)
{
	if (ray->side == 0)
	{
		ray->wall_x = data->player.pos_y + ray->perpwalldist * ray->raydir_y;
	}
	else
	{
		ray->wall_x = data->player.pos_x + ray->perpwalldist * ray->raydir_x;
	}
	ray->wall_x -= floor(ray->wall_x);
	ray->tex_x = (int)(ray->wall_x * (double)TEXW);
	if (ray->side == 0 && ray->raydir_x < 0)
	{
		ray->tex_x = TEXW - ray->tex_x - 1;
	}
	if (ray->side == 1 && ray->raydir_y > 0)
	{
		ray->tex_x = TEXW - ray->tex_x - 1;
	}
	ray->step = 1.0 * TEXH / ray->lineheight;
	ray->texpos = (ray->drawstart - ray->h / 2 + ray->lineheight / 2)
		* ray->step;
}

void	ft_find_to_draw(t_raycast *ray)
{
	ray->lineheight = (int)(ray->h / ray->perpwalldist);
	ray->drawstart = -ray->lineheight / 2 + ray->h / 2;
	if (ray->drawstart < 0)
		ray->drawstart = 0;
	ray->drawend = ray->lineheight / 2 + ray->h / 2;
	if (ray->drawend >= ray->h)
		ray->drawend = ray->h - 1;
}

void	ft_find_direction(t_data *data, t_raycast *ray)
{
	if (ray->raydir_x < 0)
	{
		ray->step_x = -1;
		ray->sidedist_x = (data->player.pos_x - ray->map_x) * ray->deltadist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->sidedist_x = (ray->map_x + 1.0 - data->player.pos_x)
			* ray->deltadist_x;
	}
	if (ray->raydir_y < 0)
	{
		ray->step_y = -1;
		ray->sidedist_y = (data->player.pos_y - ray->map_y) * ray->deltadist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->sidedist_y = (ray->map_y + 1.0 - data->player.pos_y)
			* ray->deltadist_y;
	}
}

void	ft_raycasting(t_data *data)
{
	t_raycast	ray;

	ft_memset(&ray, 0, sizeof(t_raycast));
	ray.w = data->screen_size_x;
	ray.h = data->screen_size_y;
	while (ray.x < ray.w)
	{
		ft_init_raycasting(data, &ray);
		ft_find_direction(data, &ray);
		ray.hit = 0;
		ft_dda(data, &ray);
		ft_find_to_draw(&ray);
		ft_find_texel_pos(data, &ray);
		ray.side = ft_check_side(ray.side, ray.raydir_x, ray.raydir_y,
				data->character);
		ft_draw_line(data, &ray);
		ray.x++;
	}
}
