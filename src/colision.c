/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colision.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facarval <facarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:19:47 by facarval          #+#    #+#             */
/*   Updated: 2024/04/11 15:06:09 by facarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_is_colision(t_data *data, int direction)
{
	if (direction == UP)
	{
		if (data->map[ft_convert(data->player.pos_y
				- 1)][ft_convert(data->player.pos_x)] == '1')
			return (TRUE);
	}
	if (direction == LEFT)
	{
		if (data->map[ft_convert(data->player.pos_y
				- 1)][ft_convert(data->player.pos_x)] == '1')
			return (TRUE);
	}
	if (direction == DOWN)
	{
		if (data->map[ft_convert(data->player.pos_y
				+ 1)][ft_convert(data->player.pos_x)] == '1')
			return (TRUE);
	}
	if (direction == RIGHT)
	{
		if (data->map[ft_convert(data->player.pos_y)][ft_convert(data->player.pos_x
				+ 1)] == '1')
			return (TRUE);
	}
	return (FALSE);
}