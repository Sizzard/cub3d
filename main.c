/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aciezadl <aciezadl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 10:19:35 by facarval          #+#    #+#             */
/*   Updated: 2024/06/04 15:23:03 by aciezadl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_data(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
	{
		ft_printfd(2, "Error\nMlx pointer creation failed\n");
		ft_end_process(data, FAILURE);
	}
	mlx_get_screen_size(data->mlx_ptr, &data->screen_size_x,
		&data->screen_size_y);
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->screen_size_x,
			data->screen_size_y, "Cub3d");
	if (!data->win_ptr)
	{
		ft_printfd(2, "Error\nMlx window creation failed\n");
		ft_end_process(data, FAILURE);
	}
}

void	ft_print_parse(t_parse *p)
{
	printf("nb data : %d\n", p->nb_data);
	printf("C : %s", p->ceiling);
	printf("F : %s", p->floor);
	printf("N : %s", p->no);
	printf("E : %s", p->ea);
	printf("S : %s", p->so);
	printf("W : %s", p->we);
	// printf("line : %s\n", p->line);
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_parse p;

	if (argc != 2)
	{
		ft_printfd(2, "Error\nArgs\n");
		return (FAILURE);
	}
	if(ft_init_parse(&p) || ft_parse_data_file(&p, argv[1]) == 1)
		return(FAILURE);
	ft_print_parse(&p);
	ft_error_parse(&p);
	return(printf("parsing ok\n"), 1);
	ft_memset(&data, 0, sizeof(t_data));
	data.dir_x = 1;
	data.plane_y = 0.66;
	init_data(&data);
	ft_init_img(&data);
	create_map(&data);
	ft_create_img_wall(&data);
	ft_draw_scene(&data);
	ft_raycasting(&data);
	ft_draw_minimap(&data);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img.ptr, 0, 0);
	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy,
		&data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &on_keypress, &data);
	mlx_loop(data.mlx_ptr);
	return (SUCCESS);
}
