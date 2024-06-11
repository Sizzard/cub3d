/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facarval <facarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 17:19:47 by facarval          #+#    #+#             */
/*   Updated: 2024/06/11 16:51:52 by facarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_init_raycasting(t_data *data, t_raycast *ray)
{
	ray->side = 0;
	ray->camera_x = 2 * (ray->w - ray->x) / (double)ray->w - 1;
	ray->raydir_x = data->dir_x + data->plane_x * ray->camera_x;
	ray->raydir_y = data->dir_y + data->plane_y * ray->camera_x;
	ray->map_x = (int)data->player.pos_x;
	ray->map_y = (int)data->player.pos_y;
	if (ray->raydir_x == 0)
		ray->deltadist_x = 1e30;
	else
		ray->deltadist_x = fabs(1 / ray->raydir_x);
	if (ray->raydir_y == 0)
		ray->deltadist_y = 1e30;
	else
		ray->deltadist_y = fabs(1 / ray->raydir_y);
}

char	ft_side_true(double ray_y, char c)
{
	if (c == 'E' || c == 'W')
	{
		if (ray_y > 0)
			return (SOUTH);
		else
			return (NORTH);
	}
	else
	{
		if (ray_y > 0)
			return (NORTH);
		else
			return (SOUTH);
	}
}

char	ft_side_false(double ray_x, char c)
{
	if (c == 'N' || c == 'S')
	{
		if (ray_x > 0)
			return (WEST);
		else
			return (EAST);
	}
	else
	{
		if (ray_x > 0)
			return (EAST);
		else
			return (WEST);
	}
}

int	ft_check_side(int side, double ray_x, double ray_y, char c)
{
	if (side == TRUE)
	{
		return (ft_side_true(ray_y, c));
	}
	else
	{
		return (ft_side_false(ray_x, c));
	}
}
