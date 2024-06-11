/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fabio_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facarval <facarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 12:35:17 by facarval          #+#    #+#             */
/*   Updated: 2024/06/11 13:52:58 by facarval         ###   ########.fr       */
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

void	print_map2(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		printf("%s\n", str[i]);
		i++;
	}
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
	// printf("data : %c",data->character);
}
