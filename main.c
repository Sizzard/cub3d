/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aciezadl <aciezadl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 10:19:35 by facarval          #+#    #+#             */
/*   Updated: 2024/05/30 12:02:25 by aciezadl         ###   ########.fr       */
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

void	ft_print_parse(t_parse *fichier)
{
	printf("nb data : %d\n", fichier->nb_data);
	printf("C : %s", fichier->ceiling);
	printf("F : %s", fichier->floor);
	printf("N : %s", fichier->no);
	printf("E : %s", fichier->ea);
	printf("S : %s", fichier->so);
	printf("W : %s", fichier->we);
	printf("line : %s\n", fichier->line);
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_parse fichier;

	if (argc != 2)
	{
		ft_printfd(2, "Error\nArgs\n");
		return (FAILURE);
	}
	ft_init_parse(&fichier);
	if(ft_parse_data_file(&fichier, argv[1]) == 1)
		return(1);
	ft_print_parse(&fichier);
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
