/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aciezadl <aciezadl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:04:47 by aciezadl          #+#    #+#             */
/*   Updated: 2024/06/03 17:22:29 by aciezadl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

//free la struct du parsing
void    ft_error_parse(t_parse *fichier)
{
    if(fichier->line)
        free(fichier->line);
    if(fichier->no)
        free(fichier->no);
    if(fichier->we)
        free(fichier->we);
    if(fichier->so)
        free(fichier->so);
    if(fichier->ea)
        free(fichier->ea);
    if(fichier->floor)
        free(fichier->floor);
    if(fichier->ceiling)
        free(fichier->ceiling);
    if(fichier->map)
        ft_free_tabtab(fichier->map);
}
