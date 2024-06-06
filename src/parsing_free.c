/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aciezadl <aciezadl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:04:47 by aciezadl          #+#    #+#             */
/*   Updated: 2024/06/06 16:23:58 by aciezadl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// free la struct du parsing avant d'arriver a la map
void	ft_error_parse_begin(t_parse *p)
{
	if (p->line)
		free(p->line);
	if (p->no)
		ft_free((void **)&p->no);
	if (p->we)
		ft_free((void **)&p->we);
	if (p->so)
		ft_free((void **)&p->so);
	if (p->ea)
		ft_free((void **)&p->ea);
	if (p->floor)
		ft_free((void **)&p->floor);
	if (p->ceiling)
		ft_free((void **)&p->ceiling);
	if (p->map)
		ft_free((void **)&p->map);
}

// free la struct du parsing
void	ft_error_parse(t_parse *p)
{
	if (p->line)
		free(p->line);
	if (p->no)
		ft_free((void **)&p->no);
	if (p->we)
		ft_free((void **)&p->we);
	if (p->so)
		ft_free((void **)&p->so);
	if (p->ea)
		ft_free((void **)&p->ea);
	if (p->floor)
		ft_free((void **)&p->floor);
	if (p->ceiling)
		ft_free((void **)&p->ceiling);
	if (p->map)
		ft_free_map(p->map);
}
