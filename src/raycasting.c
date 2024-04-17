/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facarval <facarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:24:04 by facarval          #+#    #+#             */
/*   Updated: 2024/04/17 11:10:14 by facarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_put_line(t_data *data, int x, int drawStart, int drawEnd, int side)
{
	// printf("%d %d %d \n", x, drawStart, drawEnd);
	// x = ft_inverse(data, x);
	while (drawStart < drawEnd)
	{
		// 0xAD2D2D
		if (side == 1)
		{
			ft_put_pixel_in_image(data, 0xAD2D2D, x, drawStart);
		}
		else
		{
			ft_put_pixel_in_image(data, data->color, x, drawStart);
		}
		drawStart++;
	}
}

void	ft_raycasting(t_data *data)
{
	int				x;
	int				mapX;
	int				mapY;
	double			cameraX;
	double			rayDirX;
	double			rayDirY;
	double			sideDistX;
	double			sideDistY;
	double			deltaDistX;
	double			deltaDistY;
	double			perpWallDist;
	int				stepX;
	int				stepY;
	int				hit;
	int				side;
	int				lineHeight;
	int				drawStart;
	int				drawEnd;
	const double	w = (int)data->screen_size_x;
	const double	h = (int)data->screen_size_y;

	data->color = 0xd93939;
	x = 0;
	while (x < w)
	{
		side = 0;
		cameraX = 2 * x / w - 1;
		rayDirX = data->dirX + data->planeX * cameraX;
		rayDirY = data->dirY + data->planeY * cameraX;
		mapX = (int)data->player.pos_x;
		mapY = (int)data->player.pos_y;
		if (rayDirX == 0)
			deltaDistX = 1e30;
		else
			deltaDistX = ft_abs(1 / rayDirX);
		if (rayDirY == 0)
			deltaDistY = 1e30;
		else
			deltaDistY = ft_abs(1 / rayDirY);
		hit = 0;
		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (data->player.pos_x - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - data->player.pos_x) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (data->player.pos_y - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - data->player.pos_y) * deltaDistY;
		}
		while (hit == 0)
		{
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			if (data->map[mapY][mapX] == '1')
				hit = 1;
		}
		if (side == 0)
		{
			perpWallDist = (sideDistX - deltaDistX);
		}
		else
		{
			perpWallDist = (sideDistY - deltaDistY);
		}
		lineHeight = (int)(h / perpWallDist);
		drawStart = -lineHeight / 2 + h / 2;
		if (drawStart < 0)
			drawStart = 0;
		drawEnd = lineHeight / 2 + h / 2;
		if (drawEnd >= h)
			drawEnd = h - 1;
		ft_put_line(data, x, drawStart, drawEnd, side);
		x++;
	}
}
