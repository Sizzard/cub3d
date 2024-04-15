/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facarval <facarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 11:38:42 by facarval          #+#    #+#             */
/*   Updated: 2024/04/15 15:21:48 by facarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_move_up(t_data *data, double moveSpeed)
{
	if (data->map[(int)((data->player.pos_y + data->dirY
				* moveSpeed))][(int)(data->player.pos_x)] != '1')
	{
		data->player.pos_y += data->dirY * moveSpeed;
	}
	if (data->map[(int)(data->player.pos_y)][(int)((data->player.pos_x
				+ data->dirX * moveSpeed))] != '1')
	{
		data->player.pos_x += data->dirX * moveSpeed;
	}
}

void	ft_move_left(t_data *data, double moveSpeed)
{
	if (data->map[(int)((data->player.pos_y - data->planeY
				* moveSpeed))][(int)(data->player.pos_x)] != '1')
		data->player.pos_y -= data->planeY * moveSpeed;
	if (data->map[(int)(data->player.pos_y)][(int)((data->player.pos_x
				- data->planeX * moveSpeed))] != '1')
		data->player.pos_x -= data->planeX * moveSpeed;
}

void	ft_move_down(t_data *data, double moveSpeed)
{
	if (data->map[(int)(data->player.pos_y)][(int)((data->player.pos_x
				- data->dirX * moveSpeed))] != '1')
		data->player.pos_x -= data->dirX * moveSpeed;
	if (data->map[(int)((data->player.pos_y - data->dirY
				* moveSpeed))][(int)(data->player.pos_x)] != '1')
		data->player.pos_y -= data->dirY * moveSpeed;
}
void	ft_move_right(t_data *data, double moveSpeed)
{
	if (data->map[(int)((data->player.pos_y + data->planeY
				* moveSpeed))][(int)(data->player.pos_x)] != '1')
		data->player.pos_y += data->planeY * moveSpeed;
	if (data->map[(int)(data->player.pos_y)][(int)((data->player.pos_x
				+ data->planeX * moveSpeed))] != '1')
		data->player.pos_x += data->planeX * moveSpeed;
}

void	ft_look_left(t_data *data, double moveSpeed)
{
	double	OldDirX;
	double	oldPlaneX;

	OldDirX = data->dirX;
	data->dirX = data->dirX * cos(-moveSpeed) - data->dirY * sin(-moveSpeed);
	data->dirY = OldDirX * sin(-moveSpeed) + data->dirY * cos(-moveSpeed);
	oldPlaneX = data->planeX;
	data->planeX = data->planeX * cos(-moveSpeed) - data->planeY
		* sin(-moveSpeed);
	data->planeY = oldPlaneX * sin(-moveSpeed) + data->planeY * cos(-moveSpeed);
}

void	ft_look_right(t_data *data, double moveSpeed)
{
	double	OldDirX;
	double	oldPlaneX;

	OldDirX = data->dirX;
	data->dirX = data->dirX * cos(moveSpeed) - data->dirY * sin(moveSpeed);
	data->dirY = OldDirX * sin(moveSpeed) + data->dirY * cos(moveSpeed);
	oldPlaneX = data->planeX;
	data->planeX = data->planeX * cos(moveSpeed) - data->planeY
		* sin(moveSpeed);
	data->planeY = oldPlaneX * sin(moveSpeed) + data->planeY * cos(moveSpeed);
}

void	ft_move(int keysym, t_data *data)
{
	double	moveSpeed;

	moveSpeed = 0.2;
	if (keysym == XK_w)
	{
		ft_move_up(data, moveSpeed);
	}
	else if (keysym == XK_a)
	{
		ft_move_left(data, moveSpeed);
	}
	else if (keysym == XK_s)
	{
		ft_move_down(data, moveSpeed);
	}
	else if (keysym == XK_d)
	{
		ft_move_right(data, moveSpeed);
	}
	else if (keysym == XK_Left)
	{
		ft_look_left(data, moveSpeed);
	}
	else if (keysym == XK_Right)
	{
		ft_look_right(data, moveSpeed);
	}
	ft_draw_scene(data);
	ft_raycasting(data);
	ft_draw_minimap(data);
	// printf("y = %f x = %f\n dirX = %f dirY = %f", data->player.pos_y,
	// 	data->player.pos_x, data->dirX, data->dirY);
}
