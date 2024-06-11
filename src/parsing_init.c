/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aciezadl <aciezadl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 10:23:25 by aciezadl          #+#    #+#             */
/*   Updated: 2024/06/11 11:16:31 by aciezadl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_init_parse(t_parse *p)
{
	p->map = ft_calloc(p->nb_line_map + 1, sizeof(char *));
	if (!p->map)
		return (ft_printfd(2, "Error\nMALLOC MAP\n"), 1);
	p->line = 0;
	p->nb_data = 0;
	p->ceiling = NULL;
	p->floor = NULL;
	p->no = NULL;
	p->ea = NULL;
	p->so = NULL;
	p->we = NULL;
	p->nb_start = 0;
	p->ceiling_hexa = 0;
	p->floor_hexa = 0;
	return (0);
}
