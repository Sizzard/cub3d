/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facarval <facarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:24:04 by facarval          #+#    #+#             */
/*   Updated: 2024/04/10 16:37:07 by facarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// void	draw_rays(t_data *data)
// {
// 	float	ray_length;
// 	float	end_x;
// 	float	end_y;
// 	int		x0;
// 	int		y0;
// 	int		x1;
// 	int		y1;

// 	ray_length = 100.0;
// 	// Longueur maximale des rayons
// 	end_x = data->player.pos_x + ray_length * cos(PI / 4);
// 	end_y = data->player.pos_y + ray_length * sin(PI / 4);
// 	x0 = (int)data->player.pos_x;
// 	y0 = (int)data->player.pos_y;
// 	x1 = (int)end_x;
// 	y1 = (int)end_y;
// 	// Dessiner la ligne représentant le rayon
// 	mlx_pixel_put(data->mlx_ptr, data->win_ptr, x0, y0, 0xFFFFFF);
// 	// Dessiner le point de départ du rayon
// 	mlx_pixel_put(data->mlx_ptr, data->win_ptr, x1, y1, 0xFFFFFF);
// 	// Dessiner le point d'arrivée du rayon
// }

// void	ft_raycasting(t_data *data)
// {
// 	int		dof;
// 	float	rx;
// 	float	ry;
// 	float	ra;
// 	float	xo;
// 	float	yo;
// 	int		i;
// 	float	aTan;
// 	int		mx;
// 	int		my;
// 	int		mp;

// 	// int		r;
// 	data->player.pos_y = data->player.y2 - 0.25;
// 	data->player.pos_x = data->player.x2 - 0.25;
// 	printf("%f %f\n", data->player.y1, data->player.y2);
// 	printf("%f %f\n", data->player.pos_y, data->player.pos_x);
// 	i = 0;
// 	ra = 1;
// 	while (i < 1)
// 	{
// 		dof = 0;
// 		aTan = -1 / tan(ra);
// 		if (ra > PI)
// 		{
// 			ry = (((int)data->player.pos_y >> 6) << 6) - 0.0001;
// 			rx = (data->player.pos_y - ry) * aTan + data->player.pos_x;
// 			yo = -64;
// 			xo = -yo * aTan;
// 		}
// 		if (ra < PI)
// 		{
// 			ry = (((int)data->player.pos_y >> 6) << 6) + 64;
// 			rx = (data->player.pos_y - ry) * aTan + data->player.pos_x;
// 			yo = 64;
// 			xo = -yo * aTan;
// 		}
// 		if (ra == 0 || ra == PI)
// 		{
// 			rx = data->player.pos_x;
// 			ry = data->player.pos_y;
// 			dof = 8;
// 		}
// 		while (dof < 8)
// 		{
// 			mx = (int)(rx) >> 6;
// 			my = (int)(ry) >> 6;
// 			mp = my * data->x_len + mx;
// 			if (mp < data->x_len * data->y_len && data->map[mp
// 				/ data->x_len][mp] == '1')
// 			{
// 				dof = 8;
// 			}
// 			else
// 			{
// 				rx += xo;
// 				ry += yo;
// 				dof += 1;
// 			}
// 		}
// 		i++;
// 	}
// 	draw_rays(data);
// }

void	ft_raycasting(t_data *data)
{
	double		dirX;
	double		dirY;
	double		planeX;
	double		planeY;
	int			x;
	double		cameraX;
	double		rayDirX;
	double		rayDirY;
	int			mapX;
	int			mapY;
	double		sideDistX;
	double		sideDistY;
	double		deltaDistX;
	double		deltaDistY;
	double		perpWallDist;
	int			stepX;
	int			stepY;
	int			lineHeight;
	int			drawStart;
	int			drawEnd;
	int			h;

	h = 1;
	dirX = -1;
	dirY = 0;
	planeX = 0;
	planeY = 0.66;
	x = 0;
	while (x < data->x_len)
	{
		cameraX = 2 * x / (double)data->x_len - 1;
		rayDirX = dirX + planeX * cameraX;
		rayDirY = dirY + planeY * cameraX;
		mapX = (int)data->player.pos_x;
		mapY = (int)data->player.pos_y;
		deltaDistX = (rayDirX == 0) ? 1e30 : abs(1 / rayDirX);
		deltaDistY = (rayDirY == 0) ? 1e30 : abs(1 / rayDirY);
		// what direction to step in x or y-direction (either +1 or -1)
		int hit = 0; // was there a wall hit?
		int side;    // was a NS or a EW wall hit?
		// calculate step and initial sideDist
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
		// perform DDA
		while (hit == 0)
		{
			// jump to next map square, either in x-direction, or in y-direction
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
			// Check if ray has hit a wall
			if (data->map[mapX][mapY] > 0)
				hit = 1;
		}
		// Calculate distance projected on camera direction (Euclidean distance would give fisheye effect!)
		if (side == 0)
			perpWallDist = (sideDistX - deltaDistX);
		else
			perpWallDist = (sideDistY - deltaDistY);
		// Calculate height of line to draw on screen
		lineHeight = (int)(h / perpWallDist);
		// calculate lowest and highest pixel to fill in current stripe
		drawStart = -lineHeight / 2 + h / 2;
		if (drawStart < 0)
			drawStart = 0;
		drawEnd = lineHeight / 2 + h / 2;
		if (drawEnd >= h)
			drawEnd = h - 1;
		switch (data->map[mapX][mapY])
		{
		case 1:
			color = 0xdd1212;
			break ; // red
		case 2:
			color = 0x40dd12;
			break ; // green
		case 3:
			color = 0x1237dd;
			break ; // blue
		case 4:
			color = 0xffffff;
			break ; // white
		default:
			color = 0xf1e81d;
			break ; // yellow
		}
		// give x and y sides different brightness
		if (side == 1)
		{
			color = color / 2;
		}
		// draw the pixels of the stripe as a vertical line
		verLine(x, drawStart, drawEnd, color);
	}
}

// data->player.pos_x = cos(0.2) - sin(0.2);
// data->player.pos_y = sin(0.2) * cos(0.2);