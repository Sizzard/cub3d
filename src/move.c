/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facarval <facarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 11:38:42 by facarval          #+#    #+#             */
/*   Updated: 2024/04/12 15:22:59 by facarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_move_up(t_data *data)
{
	if (ft_is_colision(data, UP) == FALSE)
	{
		data->player.pos_y -= 0.2;
	}
}

void	ft_move_left(t_data *data)
{
	if (ft_is_colision(data, LEFT) == FALSE)
	{
		data->player.pos_x -= 0.2;
	}
}

void	ft_move_down(t_data *data)
{
	if (ft_is_colision(data, DOWN) == FALSE)
	{
		data->player.pos_y += 0.2;
	}
}
void	ft_move_right(t_data *data)
{
	if (ft_is_colision(data, RIGHT) == FALSE)
	{
		data->player.pos_x += 0.2;
	}
}

void	ft_look_left(t_data *data)
{
	double	rotSpeed;
	double	OldDirX;
	double	oldPlaneX;

	rotSpeed = 0.5;
	OldDirX = data->dirX;
	data->dirX = data->dirX * cos(rotSpeed) - data->dirY * sin(rotSpeed);
	data->dirY = OldDirX * sin(rotSpeed) + data->dirY * cos(rotSpeed);
	oldPlaneX = data->planeX;
	data->planeX = data->planeX * cos(rotSpeed) - data->planeY * sin(rotSpeed);
	data->planeY = oldPlaneX * sin(rotSpeed) + data->planeY * cos(rotSpeed);
	// if (data->dirX == -1)
	// {
	// 	data->dirX = 0;
	// 	data->dirY = 1;
	// }
	// else if (data->dirX == 1)
	// {
	// 	data->dirX = 0;
	// 	data->dirY = -1;
	// }
	// else if (data->dirX == 0 && data->dirY == -1)
	// {
	// 	data->dirX = -1;
	// 	data->dirY = 0;
	// }
	// else if (data->dirX == 0 && data->dirY == 1)
	// {
	// 	data->dirX = +1;
	// 	data->dirY = 0;
	// }
}

void	ft_look_right(t_data *data)
{
	double	rotSpeed;
	double	OldDirX;
	double	oldPlaneX;

	rotSpeed = 0.5;
	OldDirX = data->dirX;
	data->dirX = data->dirX * cos(-rotSpeed) - data->dirY * sin(-rotSpeed);
	data->dirY = OldDirX * sin(-rotSpeed) + data->dirY * cos(-rotSpeed);
	oldPlaneX = data->planeX;
	data->planeX = data->planeX * cos(-rotSpeed) - data->planeY
		* sin(-rotSpeed);
	data->planeY = oldPlaneX * sin(-rotSpeed) + data->planeY * cos(-rotSpeed);
	// if (data->dirX == -1)
	// {
	// 	data->dirX = 0;
	// 	data->dirY = -1;
	// }
	// else if (data->dirX == 1)
	// {
	// 	data->dirX = 0;
	// 	data->dirY = 1;
	// }
	// else if (data->dirX == 0 && data->dirY == -1)
	// {
	// 	data->dirX = +1;
	// 	data->dirY = 0;
	// }
	// else if (data->dirX == 0 && data->dirY == 1)
	// {
	// 	data->dirX = -1;
	// 	data->dirY = 0;
	// }
}

void	ft_move(int keysym, t_data *data)
{
	if (keysym == XK_w)
	{
		ft_move_up(data);
	}
	else if (keysym == XK_a)
	{
		ft_move_left(data);
	}
	else if (keysym == XK_s)
	{
		ft_move_down(data);
	}
	else if (keysym == XK_d)
	{
		ft_move_right(data);
	}
	else if (keysym == XK_Left)
	{
		ft_look_left(data);
	}
	else if (keysym == XK_Right)
	{
		ft_look_right(data);
	}
	// ft_clear_window(data);
	ft_draw_scene(data);
	ft_raycasting(data);
	ft_draw_minimap(data);
}
