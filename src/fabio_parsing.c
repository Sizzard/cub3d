/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fabio_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facarval <facarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 12:35:17 by facarval          #+#    #+#             */
/*   Updated: 2024/06/11 14:55:54 by facarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_horizontal_plane(t_data *data, char c)
{
	if (c == 'W')
	{
		data->dir_x = 1;
		data->dir_y = 0;
		data->plane_x = 0;
		data->plane_y = -0.66;
	}
	else
	{
		data->dir_x = -1;
		data->dir_y = 0;
		data->plane_x = 0;
		data->plane_y = 0.66;
	}
}

void	ft_vertical_plane(t_data *data, char c)
{
	if (c == 'N')
	{
		data->dir_x = 0;
		data->dir_y = 1;
		data->plane_x = 0.66;
		data->plane_y = 0;
	}
	else
	{
		data->dir_x = 0;
		data->dir_y = -1;
		data->plane_x = -0.66;
		data->plane_y = 0;
	}
}

void	find_plane(t_data *data, char c)
{
	if (c == 'W' || c == 'E')
		ft_horizontal_plane(data, c);
	else if (c == 'N' || c == 'S')
		ft_vertical_plane(data, c);
}

char	ft_find_player(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (data->map[y])
	{
		while (data->map[y][x])
		{
			if (ft_char_is_start(data->map[y][x]) == 0)
			{
				data->character = data->map[y][x];
				find_plane(data, data->character);
				data->player.pos_x = x + 0.5;
				data->player.pos_y = y + 0.5;
				return (data->character);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

void	create_map(t_data *data, t_parse *p)
{
	data->map = p->map;
	if (ft_find_player(data) == 'N' || ft_find_player(data) == 'S')
		rev_map_y(data, p);
	else
		rev_map_x(data);
	ft_find_player(data);
	data->map[(int)data->player.pos_y][(int)data->player.pos_x] = '0';
}
