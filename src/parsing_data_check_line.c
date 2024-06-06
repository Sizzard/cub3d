/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_data_check_line.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aciezadl <aciezadl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:19:46 by aciezadl          #+#    #+#             */
/*   Updated: 2024/06/06 16:20:19 by aciezadl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// return 0 si data NO, 1 si data non valide ou doublon
int	ft_is_no(t_parse *p)
{
	if (p->line[0] == 'N' && p->line[1] == 'O' && p->line[2] == ' '
		&& p->no != NULL)
		return (ft_printfd(2, "Error\nDouble NO\n"), 1);
	if (p->line[0] == 'N' && p->line[1] == 'O' && p->line[2] == ' '
		&& p->no == NULL)
		return (p->no = ft_strdup(p->line), p->nb_data++, 0);
	else
		return (2);
}

// return 0 si data SO, 1 si data non valide ou doublon
int	ft_is_so(t_parse *p)
{
	if (p->line[0] == 'S' && p->line[1] == 'O' && p->line[2] == ' '
		&& p->so != NULL)
		return (ft_printfd(2, "Error\nDouble SO\n"), 1);
	if (p->line[0] == 'S' && p->line[1] == 'O' && p->line[2] == ' '
		&& p->so == NULL)
		return (p->so = ft_strdup(p->line), p->nb_data++, 0);
	else
		return (2);
}

// return 0 si data WE, 1 si data non valide ou doublon
int	ft_is_we(t_parse *p)
{
	if (p->line[0] == 'W' && p->line[1] == 'E' && p->line[2] == ' '
		&& p->we != NULL)
		return (ft_printfd(2, "Error\nDouble WE\n"), 1);
	if (p->line[0] == 'W' && p->line[1] == 'E' && p->line[2] == ' '
		&& p->we == NULL)
		return (p->we = ft_strdup(p->line), p->nb_data++, 0);
	else
		return (2);
}

// return 0 si data EA, 1 si data non valide ou doublon
int	ft_is_ea(t_parse *p)
{
	if (p->line[0] == 'E' && p->line[1] == 'A' && p->line[2] == ' '
		&& p->ea != NULL)
		return (ft_printfd(2, "Error\nDouble EA\n"), 1);
	if (p->line[0] == 'E' && p->line[1] == 'A' && p->line[2] == ' '
		&& p->ea == NULL)
		return (p->ea = ft_strdup(p->line), p->nb_data++, 0);
	else
		return (2);
}

// return 0 si data F, 1 si data non valide ou doublon
int	ft_is_f(t_parse *p)
{
	if (p->line[0] == 'F' && p->line[1] == ' ' && p->floor != NULL)
		return (ft_printfd(2, "Error\nDouble FLOOR\n"), 1);
	if (p->line[0] == 'F' && p->line[1] == ' ' && p->floor == NULL)
	{
		if (ft_check_coma(p->line) != 0 || ft_check_rgb(p->line) != 0)
			return (1);
		p->floor = ft_strdup(p->line);
		p->nb_data++;
		return (0);
	}
	else
		return (2);
}
