/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facarval <facarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:24:04 by facarval          #+#    #+#             */
/*   Updated: 2024/04/22 14:10:01 by facarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_check_side(int side, double ray_x, double ray_y)
{
	if (side == TRUE)
	{
		if (ray_y > 0)
			return (SOUTH);
		else
			return (NORTH);
	}
	else
	{
		if (ray_x > 0)
			return (EAST);
		else
			return (WEST);
	}
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

void	ft_raycasting(t_data *data)
{
	t_raycast	ray;

	ft_memset(&ray, 0, sizeof(t_raycast));
	ray.w = data->screen_size_x;
	ray.h = data->screen_size_y;
	while (ray.x < ray.w)
	{
		ray.side = 0;
		ray.camera_x = 2 * ray.x / ray.w - 1;
		ray.raydir_x = data->dir_x + data->plane_x * ray.camera_x;
		ray.raydir_y = data->dir_y + data->plane_y * ray.camera_x;
		ray.map_x = (int)data->player.pos_x;
		ray.map_y = (int)data->player.pos_y;
		if (ray.raydir_x == 0)
			ray.deltadist_x = 1e30;
		else
			ray.deltadist_x = fabs(1 / ray.raydir_x);
		if (ray.raydir_y == 0)
			ray.deltadist_y = 1e30;
		else
			ray.deltadist_y = fabs(1 / ray.raydir_y);
		ray.hit = 0;
		if (ray.raydir_x < 0)
		{
			ray.step_x = -1;
			ray.sidedist_x = (data->player.pos_x - ray.map_x) * ray.deltadist_x;
		}
		else
		{
			ray.step_x = 1;
			ray.sidedist_x = (ray.map_x + 1.0 - data->player.pos_x)
				* ray.deltadist_x;
		}
		if (ray.raydir_y < 0)
		{
			ray.step_y = -1;
			ray.sidedist_y = (data->player.pos_y - ray.map_y) * ray.deltadist_y;
		}
		else
		{
			ray.step_y = 1;
			ray.sidedist_y = (ray.map_y + 1.0 - data->player.pos_y)
				* ray.deltadist_y;
		}
		while (ray.hit == 0)
		{
			if (ray.sidedist_x < ray.sidedist_y)
			{
				ray.sidedist_x += ray.deltadist_x;
				ray.map_x += ray.step_x;
				ray.side = FALSE;
			}
			else
			{
				ray.sidedist_y += ray.deltadist_y;
				ray.map_y += ray.step_y;
				ray.side = TRUE;
			}
			if (data->map[ray.map_y][ray.map_x] == '1')
				ray.hit = 1;
		}
		if (ray.side == 0)
		{
			ray.perpwalldist = (ray.sidedist_x - ray.deltadist_x);
		}
		else
		{
			ray.perpwalldist = (ray.sidedist_y - ray.deltadist_y);
		}
		ray.lineheight = (int)(ray.h / ray.perpwalldist);
		ray.drawstart = -ray.lineheight / 2 + ray.h / 2;
		if (ray.drawstart < 0)
			ray.drawstart = 0;
		ray.drawend = ray.lineheight / 2 + ray.h / 2;
		if (ray.drawend >= ray.h)
			ray.drawend = ray.h - 1;
		if (ray.side == 0)
		{
			ray.wall_x = data->player.pos_y + ray.perpwalldist * ray.raydir_y;
		}
		else
		{
			ray.wall_x = data->player.pos_x + ray.perpwalldist * ray.raydir_x;
		}
		ray.wall_x -= floor(ray.wall_x);
		ray.tex_x = (int)(ray.wall_x * (double)TEXW);
		if (ray.side == 0 && ray.raydir_x > 0)
		{
			ray.tex_x = TEXW - ray.tex_x - 1;
		}
		if (ray.side == 1 && ray.raydir_y < 0)
		{
			ray.tex_x = TEXW - ray.tex_x - 1;
		}
		ray.step = 1.0 * TEXH / ray.lineheight;
		ray.texpos = (ray.drawstart - ray.h / 2 + ray.lineheight / 2)
			* ray.step;
		ray.side = ft_check_side(ray.side, ray.raydir_x, ray.raydir_y);
		ft_draw_line(data, &ray);
		ray.x++;
	}
}
