/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facarval <facarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:24:04 by facarval          #+#    #+#             */
/*   Updated: 2024/04/11 16:46:26 by facarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_put_line(t_data *data, int x, int drawStart, int drawEnd, int side)
{
	// printf("%d %d %d \n", x, drawStart, drawEnd);
	drawStart += 472;
	drawEnd += 472;
	x = ft_inverse(data, x);
	while (drawStart < drawEnd)
	{
		// 0xAD2D2D
		if (side > 0)
			ft_put_pixel_in_image(data, 0xAD2D2D, x, drawStart);
		else
			ft_put_pixel_in_image(data, data->color, x, drawStart);
		drawStart++;
	}
}

void	ft_raycasting(t_data *data)
{
	int		x;
	int		mapX;
	int		mapY;
	double	cameraX;
	double	time;
	double	oldTime;
	double	rayDirX;
	double	rayDirY;
	double	sideDistX;
	double	sideDistY;
	double	deltaDistX;
	double	deltaDistY;
	double	perpWallDist;
	int		stepX;
	int		stepY;
	int		hit;
	int		side;
	int		h;
	int		lineHeight;
	int		drawStart;
	int		drawEnd;
	int		prev_side;

	data->color = 0xd93939;
	h = 500;
	time = 0;
	oldTime = 0;
	data->planeX = 0;
	data->planeY = 0.66;
	data->dirX = -1;
	data->dirY = 0;
	x = 0;
	side = 0;
	// mlx_clear_window(data->mlx_ptr, data->win_ptr);
	// if (data->img.ptr)
	// 	mlx_destroy_image(data->mlx_ptr, data->img.ptr);
	// ft_free((void **)&data->img.ptr);
	// ft_create_img(data);
	// ft_create_buffer_img(data);
	while (x < data->screen_size_x)
	{
		cameraX = 2 * x / (double)data->screen_size_x - 1;
		rayDirX = data->dirX + data->planeX * cameraX;
		rayDirY = data->dirY + data->planeY * cameraX;
		mapX = (int)data->player.pos_x;
		mapY = (int)data->player.pos_y;
		deltaDistX = (rayDirX == 0) ? 1e30 : ft_abs(1 / rayDirX);
		deltaDistY = (rayDirY == 0) ? 1e30 : ft_abs(1 / rayDirY);
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
				prev_side++;
			}
			if (data->map[mapY][mapX] == '1')
				hit = 1;
		}
		if (side == 0)
		{
			prev_side = 0;
			perpWallDist = (sideDistX - deltaDistX);
		}
		else
			perpWallDist = (sideDistY - deltaDistY);
		lineHeight = (int)(h / perpWallDist);
		drawStart = -lineHeight / 2 + h / 2;
		if (drawStart < 0)
			drawStart = 0;
		drawEnd = lineHeight / 2 + h / 2;
		if (drawEnd >= h)
			drawEnd = h - 1;
		ft_put_line(data, x, drawStart, drawEnd, prev_side);
		x++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.ptr, 0, 0);
}
