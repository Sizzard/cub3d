/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facarval <facarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 12:35:17 by facarval          #+#    #+#             */
/*   Updated: 2024/04/22 10:20:44 by facarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_find_player(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (data->map[y])
	{
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'P')
			{
				data->map[y][x] = '0';
				data->player.pos_x = x + 0.5;
				data->player.pos_y = y + 0.5;
			}
			x++;
		}
		x = 0;
		y++;
	}
}

void	create_map(t_data *data)
{
	int	i;

	data->map = malloc(sizeof(char *) * 11);
	data->map[0] = ft_strdup("111111111111111111111");
	data->map[1] = ft_strdup("100001000000000000001");
	data->map[2] = ft_strdup("100111000010100000011");
	data->map[3] = ft_strdup("100000001110111000001");
	data->map[4] = ft_strdup("10011100000P000000001");
	data->map[5] = ft_strdup("100001001110111000011");
	data->map[6] = ft_strdup("100001000010100000001");
	data->map[7] = ft_strdup("100001000010100000011");
	data->map[8] = ft_strdup("100001000000000000001");
	data->map[9] = ft_strdup("111111111111111111111");
	data->map[10] = NULL;
	ft_find_player(data);
	data->x_len = ft_strlen(data->map[0]);
	i = 0;
	while (data->map[i])
		i++;
	data->y_len = i;
}
