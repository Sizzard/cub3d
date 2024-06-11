/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facarval <facarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:54:49 by facarval          #+#    #+#             */
/*   Updated: 2024/06/11 14:54:57 by facarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*ft_strrev(char *str)
{
	int		i;
	int		length;
	char	temporary;

	i = -1;
	length = 0;
	while (str[length])
		length++;
	while (++i < length / 2)
	{
		temporary = str[i];
		str[i] = str[length - 1 - i];
		str[length - 1 - i] = temporary;
	}
	return (str);
}

void	rev_map_x(t_data *data)
{
	int	y;

	y = 0;
	while (data->map[y])
	{
		data->map[y] = ft_strrev(data->map[y]);
		y++;
	}
}

void	rev_map_y(t_data *data, t_parse *p)
{
	int		y;
	int		end;
	char	*temp;

	y = 0;
	end = p->nb_line_map - 5;
	while (y < end)
	{
		temp = data->map[y];
		data->map[y] = data->map[end];
		data->map[end] = temp;
		y++;
		end--;
	}
}
