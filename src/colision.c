/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colision.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facarval <facarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:19:47 by facarval          #+#    #+#             */
/*   Updated: 2024/04/10 15:14:40 by facarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_is_colision(t_data *data, int direction)
{
	if (direction == UP)
	{
		if (data->map[ft_convert(data->player.y1
				- 0.6)][ft_convert(data->player.x1)] == '1'
			&& data->map[ft_convert(data->player.y2
				- 0.6)][ft_convert(data->player.x2)] == '1')
			return (TRUE);
	}
	if (direction == LEFT)
	{
		if (data->map[ft_convert(data->player.y1)][ft_convert(data->player.x1
				- 0.6)] == '1'
			&& data->map[ft_convert(data->player.y2)][ft_convert(data->player.x2
				- 0.6)] == '1')
			return (TRUE);
	}
	if (direction == DOWN)
	{
		if (data->map[ft_convert(data->player.y1
				+ 0.7)][ft_convert(data->player.x1)] == '1'
			&& data->map[ft_convert(data->player.y2
				+ 0.7)][ft_convert(data->player.x2)] == '1')
			return (TRUE);
	}
	if (direction == RIGHT)
	{
		if (data->map[ft_convert(data->player.y1)][ft_convert(data->player.x1
				+ 0.6)] == '1'
			&& data->map[ft_convert(data->player.y2)][ft_convert(data->player.x2
				+ 0.6)] == '1')
			return (TRUE);
	}
	return (FALSE);
}