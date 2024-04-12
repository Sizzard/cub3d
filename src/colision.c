/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colision.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facarval <facarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:19:47 by facarval          #+#    #+#             */
/*   Updated: 2024/04/12 11:30:05 by facarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_is_colision(t_data *data, int direction)
{
	if (direction == UP)
	{
		if (data->map[(int)(data->player.pos_y
				- 0.2)][(int)(data->player.pos_x)] == '1')
			return (TRUE);
	}
	if (direction == LEFT)
	{
		if (data->map[(int)(data->player.pos_y
				- 0.2)][(int)(data->player.pos_x)] == '1')
			return (TRUE);
	}
	if (direction == DOWN)
	{
		if (data->map[(int)(data->player.pos_y
				+ 0.2)][(int)(data->player.pos_x)] == '1')
			return (TRUE);
	}
	if (direction == RIGHT)
	{
		if (data->map[(int)(data->player.pos_y)][(int)(data->player.pos_x
				+ 0.2)] == '1')
			return (TRUE);
	}
	return (FALSE);
}