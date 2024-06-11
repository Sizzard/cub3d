/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facarval <facarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 10:31:57 by facarval          #+#    #+#             */
/*   Updated: 2024/06/11 16:46:09 by facarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_look_right(t_data *data, double move_speed)
{
	double	old_dir_x;
	double	old_planex;

	old_dir_x = data->dir_x;
	data->dir_x = data->dir_x * cos(move_speed) - data->dir_y * sin(move_speed);
	data->dir_y = old_dir_x * sin(move_speed) + data->dir_y * cos(move_speed);
	old_planex = data->plane_x;
	data->plane_x = data->plane_x * cos(move_speed) - data->plane_y
		* sin(move_speed);
	data->plane_y = old_planex * sin(move_speed) + data->plane_y
		* cos(move_speed);
}

void	ft_look_left(t_data *data, double move_speed)
{
	double	old_dir_x;
	double	old_planex;

	old_dir_x = data->dir_x;
	data->dir_x = data->dir_x * cos(-move_speed) - data->dir_y
		* sin(-move_speed);
	data->dir_y = old_dir_x * sin(-move_speed) + data->dir_y * cos(-move_speed);
	old_planex = data->plane_x;
	data->plane_x = data->plane_x * cos(-move_speed) - data->plane_y
		* sin(-move_speed);
	data->plane_y = old_planex * sin(-move_speed) + data->plane_y
		* cos(-move_speed);
}

void	ft_rotation(int keysym, t_data *data)
{
	double	move_speed;

	move_speed = 0.2;
	if (keysym == XK_Left)
	{
		ft_look_left(data, move_speed);
	}
	else if (keysym == XK_Right)
	{
		ft_look_right(data, move_speed);
	}
}
