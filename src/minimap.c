/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facarval <facarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:10:55 by facarval          #+#    #+#             */
/*   Updated: 2024/06/11 16:56:12 by facarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_draw_blocks(t_data *data, t_mini mini, int i, int j)
{
	if (data->map[mini.y] && (int)ft_strlen(data->map[mini.y]) > mini.x
		&& data->map[mini.y][mini.x] == '1')
	{
		ft_put_pixel_in_image(data, 0x000000, i, j);
	}
	else if (data->map[mini.y] && (int)ft_strlen(data->map[mini.y]) > mini.x
		&& data->map[mini.y][mini.x] == '0')
	{
		ft_put_pixel_in_image(data, 0x754131, i, j);
	}
}

void	ft_print_block(t_data *data, t_mini mini, int counter_x, int counter_y)
{
	int			i;
	int			j;
	const int	screen_len = data->screen_size_x / 50;

	i = counter_x * screen_len;
	j = counter_y * screen_len;
	while (j < screen_len * counter_y + screen_len - 1)
	{
		while (i < screen_len * counter_x + screen_len - 1)
		{
			if (mini.y < 0 || mini.x < 0)
				return ;
			ft_draw_blocks(data, mini, i, j);
			i++;
		}
		i = counter_x * screen_len;
		j++;
	}
}

void	ft_draw_player(t_data *data)
{
	int			i;
	int			j;
	const int	screen_len = data->screen_size_x / 50;

	i = screen_len * 3;
	j = screen_len * 3;
	while (j < screen_len * 3 + screen_len - 1)
	{
		while (i < screen_len * 3 + screen_len - 1)
		{
			if (data)
				ft_put_pixel_in_image(data, 0xf6f916, i, j);
			i++;
		}
		i = screen_len * 3;
		j++;
	}
}

void	ft_draw_minimap(t_data *data)
{
	t_mini	mini;
	int		counter_x;
	int		counter_y;

	counter_y = 1;
	mini.start_x = (int)data->player.pos_x - 2;
	mini.start_y = (int)data->player.pos_y - 2;
	mini.y = mini.start_y;
	while (mini.y < mini.start_y + 5)
	{
		counter_x = 1;
		mini.x = mini.start_x;
		while (mini.x <= mini.start_x + 4)
		{
			ft_print_block(data, mini, counter_x, counter_y);
			mini.x++;
			counter_x++;
		}
		counter_y++;
		mini.y++;
	}
	ft_draw_player(data);
}

void	print_map(char **str)
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
