/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aciezadl <aciezadl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:04:47 by aciezadl          #+#    #+#             */
/*   Updated: 2024/06/04 16:02:18 by aciezadl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

//free la struct du parsing avant d'arriver a la map
void    ft_error_parse_begin(t_parse *p)
{
    if(p->line)
        free(p->line);
    if(p->no)
        free(p->no);
    if(p->we)
        free(p->we);
    if(p->so)
        free(p->so);
    if(p->ea)
        free(p->ea);
    if(p->floor)
        free(p->floor);
    if(p->ceiling)
        free(p->ceiling);
    if(p->map)
        free(p->map);
}

//free la struct du parsing
void    ft_error_parse(t_parse *p)
{
    if(p->line)
        free(p->line);
    if(p->no)
        free(p->no);
    if(p->we)
        free(p->we);
    if(p->so)
        free(p->so);
    if(p->ea)
        free(p->ea);
    if(p->floor)
        free(p->floor);
    if(p->ceiling)
        free(p->ceiling);
    if(p->map)
        ft_free_tabtab(p->map);
}
