/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facarval <facarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 11:38:42 by facarval          #+#    #+#             */
/*   Updated: 2024/04/11 15:04:26 by facarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_move_up(t_data *data)
{
	if (ft_is_colision(data, UP) == FALSE)
	{
		// data->player.y1 -= 1;
		// data->player.y2 -= 1;
		data->player.pos_y--;
	}
}

void	ft_move_left(t_data *data)
{
	if (ft_is_colision(data, LEFT) == FALSE)
	{
		// data->player.x1 -= 1;
		// data->player.x2 -= 1;
		data->player.pos_x--;
	}
}

void	ft_move_down(t_data *data)
{
	if (ft_is_colision(data, DOWN) == FALSE)
	{
		// data->player.y1 += 1;
		// data->player.y2 += 1;
		data->player.pos_y++;
	}
}
void	ft_move_right(t_data *data)
{
	if (ft_is_colision(data, RIGHT) == FALSE)
	{
		// data->player.x1 += 1;
		// data->player.x2 += 1;
		data->player.pos_x++;
	}
}

void	ft_look_left(t_data *data)
{
	(void)data;
}

void	ft_look_right(t_data *data)
{
	(void)data;
}

void	ft_move(int keysym, t_data *data)
{
	if (keysym == XK_w)
	{
		ft_move_up(data);
	}
	else if (keysym == XK_a)
	{
		ft_move_left(data);
	}
	else if (keysym == XK_s)
	{
		ft_move_down(data);
	}
	else if (keysym == XK_d)
	{
		ft_move_right(data);
	}
	else if (keysym == XK_Left)
	{
		ft_look_left(data);
	}
	else if (keysym == XK_Right)
	{
		ft_look_right(data);
	}
	// ft_clear_window(data);
	ft_draw_scene(data);
	ft_raycasting(data);
	ft_draw_minimap(data);
}
