/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facarval <facarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 10:13:39 by facarval          #+#    #+#             */
/*   Updated: 2024/06/07 01:37:29 by facarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_free(void **ptr)
{
	if (*ptr)
	{
		free(*ptr);
	}
	*ptr = NULL;
}

void	ft_free_map(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_free((void **)&(str[i]));
		i++;
	}
	ft_free((void **)&str);
}

void	ft_end_process(t_data *data, int exit_code)
{
	if (data->map)
		ft_free_map(data->map);
	ft_free((void **)&data->no);
	ft_free((void **)&data->so);
	ft_free((void **)&data->we);
	ft_free((void **)&data->ea);
	if (data->img.ptr)
		mlx_destroy_image(data->mlx_ptr, data->img.ptr);
	if (data->wall.wall_n_img)
		mlx_destroy_image(data->mlx_ptr, data->wall.wall_n_img);
	if (data->wall.wall_s_img)
		mlx_destroy_image(data->mlx_ptr, data->wall.wall_s_img);
	if (data->wall.wall_e_img)
		mlx_destroy_image(data->mlx_ptr, data->wall.wall_e_img);
	if (data->wall.wall_w_img)
		mlx_destroy_image(data->mlx_ptr, data->wall.wall_w_img);
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->mlx_ptr)
		mlx_destroy_display(data->mlx_ptr);
	ft_free((void **)&data->mlx_ptr);
	exit(exit_code);
}
