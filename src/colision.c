/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colision.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facarval <facarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:19:47 by facarval          #+#    #+#             */
/*   Updated: 2024/04/22 13:28:02 by facarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_colision_up(t_data *data, double move_speed)
{
	if (data->map[(int)(data->player.pos_y + data->dir_y
			* move_speed)][(int)(data->player.pos_x)] == '1')
	{
		return (TRUE);
	}
	if (data->map[(int)(data->player.pos_y)][(int)(data->player.pos_x
			+ data->dir_x * move_speed)] == '1')
	{
		return (TRUE);
	}
	return (FALSE);
}

int	ft_colision_left(t_data *data, double move_speed)
{
	if (data->map[(int)(data->player.pos_y - data->plane_y
			* move_speed)][(int)(data->player.pos_x)] == '1')
		return (TRUE);
	if (data->map[(int)(data->player.pos_y)][(int)(data->player.pos_x
			- data->plane_x * move_speed)] == '1')
		return (TRUE);
	return (FALSE);
}

int	ft_colision_down(t_data *data, double move_speed)
{
	if (data->map[(int)(data->player.pos_y)][(int)(data->player.pos_x
			+ data->dir_x * move_speed)] == '1')
		return (TRUE);
	if (data->map[(int)(data->player.pos_y + data->dir_y
			* move_speed)][(int)(data->player.pos_x)] == '1')
		return (TRUE);
	return (FALSE);
}

int	ft_colision_right(t_data *data, double move_speed)
{
	if (data->map[(int)(data->player.pos_y + data->plane_y
			* move_speed)][(int)(data->player.pos_x)] == '1')
		return (TRUE);
	if (data->map[(int)(data->player.pos_y)][(int)(data->player.pos_x
			+ data->plane_x * move_speed)] == '1')
		return (TRUE);
	return (FALSE);
}

int	ft_is_colision(t_data *data, int direction)
{
	double	move_speed;

	move_speed = 0.2;
	if (direction == UP)
	{
		return (ft_colision_up(data, move_speed));
	}
	else if (direction == LEFT)
	{
		return (ft_colision_left(data, move_speed));
	}
	else if (direction == DOWN)
	{
		return (ft_colision_down(data, move_speed));
	}
	else if (direction == RIGHT)
	{
		return (ft_colision_right(data, move_speed));
	}
	return (FALSE);
}
