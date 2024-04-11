/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facarval <facarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 12:35:17 by facarval          #+#    #+#             */
/*   Updated: 2024/04/11 15:04:00 by facarval         ###   ########.fr       */
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
				data->player.pos_x = x;
				data->player.pos_y = y;
				// data->player.x1 = x;
				// data->player.y1 = y;
				// data->player.x2 = x + 0.5;
				// data->player.y2 = y + 0.5;
			}
			x++;
		}
		x = 0;
		y++;
	}
	// printf("%f %f %f %f\n", data->player.x1, data->player.x2, data->player.y1,
	// 	data->player.y2);
}

void	create_map(t_data *data)
{
	int	i;

	data->map = malloc(sizeof(char *) * 11);
	data->map[0] = ft_strdup("111111111111111111111");
	data->map[1] = ft_strdup("100000000000000000001");
	data->map[2] = ft_strdup("100000000000000000001");
	data->map[3] = ft_strdup("100000000000000000P01");
	data->map[4] = ft_strdup("100000000000000000001");
	data->map[5] = ft_strdup("100000000000000000001");
	data->map[6] = ft_strdup("100000000000000000001");
	data->map[7] = ft_strdup("100000000000000000001");
	data->map[8] = ft_strdup("100000000000000000001");
	data->map[9] = ft_strdup("111111111111111111111");
	data->map[10] = NULL;
	ft_find_player(data);
	data->x_len = ft_strlen(data->map[0]);
	i = 0;
	while (data->map[i])
		i++;
	data->y_len = i;
}
