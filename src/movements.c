/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facarval <facarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 11:38:42 by facarval          #+#    #+#             */
/*   Updated: 2024/06/11 16:45:39 by facarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_move_up(t_data *data, double move_speed)
{
	if (data->map[(int)((data->player.pos_y + data->dir_y
				* move_speed))][(int)(data->player.pos_x)] != '1')
	{
		data->player.pos_y += data->dir_y * move_speed;
	}
	if (data->map[(int)(data->player.pos_y)][(int)((data->player.pos_x
				+ data->dir_x * move_speed))] != '1')
	{
		data->player.pos_x += data->dir_x * move_speed;
	}
}

void	ft_move_left(t_data *data, double move_speed)
{
	if (data->map[(int)((data->player.pos_y + data->plane_y
				* move_speed))][(int)(data->player.pos_x)] != '1')
		data->player.pos_y += data->plane_y * move_speed;
	if (data->map[(int)(data->player.pos_y)][(int)((data->player.pos_x
				+ data->plane_x * move_speed))] != '1')
		data->player.pos_x += data->plane_x * move_speed;
}

void	ft_move_down(t_data *data, double move_speed)
{
	if (data->map[(int)(data->player.pos_y)][(int)((data->player.pos_x
				- data->dir_x * move_speed))] != '1')
		data->player.pos_x -= data->dir_x * move_speed;
	if (data->map[(int)((data->player.pos_y - data->dir_y
				* move_speed))][(int)(data->player.pos_x)] != '1')
		data->player.pos_y -= data->dir_y * move_speed;
}

void	ft_move_right(t_data *data, double move_speed)
{
	if (data->map[(int)((data->player.pos_y - data->plane_y
				* move_speed))][(int)(data->player.pos_x)] != '1')
		data->player.pos_y -= data->plane_y * move_speed;
	if (data->map[(int)(data->player.pos_y)][(int)((data->player.pos_x
				- data->plane_x * move_speed))] != '1')
		data->player.pos_x -= data->plane_x * move_speed;
}

void	ft_move(int keysym, t_data *data)
{
	double	move_speed;

	move_speed = 0.2;
	if (keysym == XK_w)
	{
		ft_move_up(data, move_speed);
	}
	else if (keysym == XK_a)
	{
		ft_move_left(data, move_speed);
	}
	else if (keysym == XK_s)
	{
		ft_move_down(data, move_speed);
	}
	else if (keysym == XK_d)
	{
		ft_move_right(data, move_speed);
	}
}
