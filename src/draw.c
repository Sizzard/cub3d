/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facarval <facarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:13:09 by facarval          #+#    #+#             */
/*   Updated: 2024/04/22 13:30:04 by facarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_clear_window(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->screen_size_x * data->screen_size_y)
	{
		ft_put_pixel_in_image(data, 0x000000, i, 1);
		i++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.ptr, 0, 0);
}
