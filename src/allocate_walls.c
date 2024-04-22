/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_walls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facarval <facarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:05:41 by facarval          #+#    #+#             */
/*   Updated: 2024/04/22 14:08:07 by facarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_create_img(t_data *data, void **img, char *path)
{
	*img = mlx_xpm_file_to_image(data->mlx_ptr, path, &data->pixel.x,
			&data->pixel.y);
	if (!(*img))
	{
		ft_printfd(2, "Error\nmlx_xpm_file_to_image failed\n");
		ft_end_process(data, FAILURE);
	}
}

void	ft_create_img_buffer(t_data *data, void *ptr, int **buffer)
{
	*buffer = (int *)mlx_get_data_addr(ptr, &data->img.bits,
			&data->img.size_line, &data->img.endian);
	if (!(*buffer))
	{
		ft_printfd(2, "Error\nmlx_get_data_addr failed\n");
		ft_end_process(data, FAILURE);
	}
}

void	ft_create_img_wall(t_data *data)
{
	ft_create_img(data, &data->wall.wall_n_img, "textures/North.xpm");
	ft_create_img_buffer(data, data->wall.wall_n_img, &data->wall.n_str);
	ft_create_img(data, &data->wall.wall_s_img, "textures/South.xpm");
	ft_create_img_buffer(data, data->wall.wall_s_img, &data->wall.s_str);
	ft_create_img(data, &data->wall.wall_e_img, "textures/East.xpm");
	ft_create_img_buffer(data, data->wall.wall_e_img, &data->wall.e_str);
	ft_create_img(data, &data->wall.wall_w_img, "textures/West.xpm");
	ft_create_img_buffer(data, data->wall.wall_w_img, &data->wall.w_str);
}
