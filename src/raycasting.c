/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facarval <facarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:24:04 by facarval          #+#    #+#             */
/*   Updated: 2024/04/19 15:23:08 by facarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_check_side(t_data *data, int side)
{
	if (side == FALSE)
	{
		if (data->dirX > 0)
			return (NORTH);
		else
			return (SOUTH);
	}
	else
	{
		if (data->dirY > 0)
			return (EAST);
		else
			return (WEST);
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
	double			wallX;
	int				texX;
	double			step;
	double			texPos;
	int				texY;
	int				color;

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
			deltaDistX = fabs(1 / rayDirX);
		if (rayDirY == 0)
			deltaDistY = 1e30;
		else
			deltaDistY = fabs(1 / rayDirY);
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
				side = FALSE;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = TRUE;
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
		if (side == 0)
		{
			wallX = data->player.pos_y + perpWallDist * rayDirY;
		}
		else
		{
			wallX = data->player.pos_x + perpWallDist * rayDirX;
		}
		wallX -= floor(wallX);
		texX = (int)(wallX * (double)texW);
		if (side == 0 && rayDirX > 0)
		{
			texX = texW - texX - 1;
		}
		if (side == 1 && rayDirY < 0)
		{
			texX = texW - texX - 1;
		}
		step = 1.0 * texH / lineHeight;
		texPos = (drawStart - h / 2 + lineHeight / 2) * step;
		side = ft_check_side(data, side);
		while (drawStart < drawEnd)
		{
			texY = (int)texPos & (texH - 1);
			texPos += step;
			if (side == NORTH)
				color = data->wall.n_str[(texH * texY + texX)];
			else if (side == SOUTH)
				color = data->wall.s_str[(texH * texY + texX)];
			else if (side == WEST)
				color = data->wall.w_str[(texH * texY + texX)];
			else if (side == EAST)
				color = data->wall.e_str[(texH * texY + texX)];
			ft_put_pixel_in_image(data, color, x, drawStart);
			drawStart++;
		}
		x++;
	}
}
