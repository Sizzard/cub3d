/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facarval <facarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 10:28:41 by facarval          #+#    #+#             */
/*   Updated: 2024/04/22 14:16:54 by facarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_put_pixel_in_image(t_data *data, int color, int x, int y)
{
	const int	x_len = data->screen_size_x;

	data->img.str[x + (x_len * y)] = color;
}

int	on_destroy(t_data *data)
{
	ft_end_process(data, SUCCESS);
	return (SUCCESS);
}

int	on_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		on_destroy(data);
	}
	if (keysym == XK_w || keysym == XK_a || keysym == XK_s || keysym == XK_d)
	{
		ft_move(keysym, data);
	}
	if (keysym == XK_Left || keysym == XK_Right)
	{
		ft_rotation(keysym, data);
	}
	ft_draw_scene(data);
	ft_raycasting(data);
	ft_draw_minimap(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.ptr, 0, 0);
	return (SUCCESS);
}
