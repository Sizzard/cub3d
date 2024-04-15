/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colision.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facarval <facarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:19:47 by facarval          #+#    #+#             */
/*   Updated: 2024/04/15 12:14:08 by facarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_is_colision(t_data *data, int direction)
{
	double moveSpeed = 0.2;
	if (direction == UP)
	{
		if (data->map[(int)(data->player.pos_y + data->dirY
				* moveSpeed)][(int)(data->player.pos_x)] == '1')
		{
			return (TRUE);
		}
		if (data->map[(int)(data->player.pos_y)][(int)(data->player.pos_x
				+ data->dirX * moveSpeed)] == '1')
		{
			return (TRUE);
		}
	}
	else if (direction == LEFT)
	{
		if (data->map[(int)(data->player.pos_y - data->planeY
				* moveSpeed)][(int)(data->player.pos_x)] == '1')
			return (TRUE);
		if (data->map[(int)(data->player.pos_y)][(int)(data->player.pos_x
				- data->planeX * moveSpeed)] == '1')
			return (TRUE);
	}
	else if (direction == DOWN)
	{
		if (data->map[(int)(data->player.pos_y)][(int)(data->player.pos_x
				+ data->dirX * moveSpeed)] == '1')
			return (TRUE);
		if (data->map[(int)(data->player.pos_y + data->dirY
				* moveSpeed)][(int)(data->player.pos_x)] == '1')
			return (TRUE);
	}
	else if (direction == RIGHT)
	{
		if (data->map[(int)(data->player.pos_y + data->planeY
				* moveSpeed)][(int)(data->player.pos_x)] == '1')
			return (TRUE);
		if (data->map[(int)(data->player.pos_y)][(int)(data->player.pos_x
				+ data->planeX * moveSpeed)] == '1')
			return (TRUE);
	}
	return (FALSE);
}