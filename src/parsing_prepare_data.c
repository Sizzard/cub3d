/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_prepare_data.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aciezadl <aciezadl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 17:24:03 by aciezadl          #+#    #+#             */
/*   Updated: 2024/06/06 18:00:55 by aciezadl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

unsigned long	ft_convert(int r, int g, int b)
{
	return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

int	ft_rgbtohex(t_parse *p)
{
	char	**ceiling;
	char	**floor;

	ceiling = ft_split(p->ceiling, ',');
	if (!ceiling)
		return (1);
	floor = ft_split(p->floor, ',');
	if (!floor)
		return (ft_free_tabtab(ceiling), 1);
	p->ceiling_hexa = ft_convert(ft_atoi(ceiling[0]), ft_atoi(ceiling[1]), ft_atoi(ceiling[2]));
    p->floor_hexa = ft_convert(ft_atoi(floor[0]), ft_atoi(floor[1]), ft_atoi(floor[2]));
	ft_free_tabtab(ceiling);
	ft_free_tabtab(floor);
	return(0);
}
void	ft_prepare_data(t_parse *p)
{
	ft_clean_struct(p);
	ft_rgbtohex(p);
}

// supprime le 1er mot des data de la struct
void	ft_clean_struct(t_parse *p)
{
	ft_remove_begin(p->no);
	ft_remove_begin(p->so);
	ft_remove_begin(p->we);
	ft_remove_begin(p->ea);
	ft_remove_begin(p->floor);
	ft_remove_begin(p->ceiling);
}
