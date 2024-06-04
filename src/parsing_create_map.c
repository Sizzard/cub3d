/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_create_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aciezadl <aciezadl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 10:36:57 by aciezadl          #+#    #+#             */
/*   Updated: 2024/06/04 15:04:48 by aciezadl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_skip_line(int fd, t_parse *p)
{
	free(p->line);
	p->line = get_next_line(fd);
	if (!p->line)
		return (ft_printfd(2, "Error\nMALLOC\n"), ft_error_parse(p), 1);
	return (0);
}

int	ft_fill_map(int fd, t_parse *p, int *i)
{
	if (!p->line)
		return (p->map[*i] = NULL, 0);
	p->map[*i] = ft_strdup(p->line);
	if (!p->map[*i])
		return (p->map[*i] = NULL, 0);
	(*i)++;
	free(p->line);
	p->line = get_next_line(fd);
	if (!p->line)
		return (p->map[*i] = NULL, 0);
	return (1);
}

/*return 0 si on arrive a la fin de map
return 1 si ya du contenu sous la map
return 2 pour continuer a checker la ligne suivante du p*/
int	ft_check_under_map(int fd, t_parse *p, int *i)
{
	free(p->line);
	p->line = get_next_line(fd);
	if (!p->line)
		return (p->map[*i] = NULL, 0);
	if (ft_empty_line_end(p->line) == 1)
		return (p->map[*i] = NULL, ft_printfd(2,
				"Error\nCONTENT UNDER MAP\n"), 1);
	return (2);
}

// rempli la map, renvoi 1 si pb
int	ft_create_map(int fd, t_parse *p)
{
	int	i;
	int	umap;

	i = 0;
	umap = 0;
	p->line = get_next_line(fd);
	while (ft_empty_line(p->line) == 0)
	{
		if (ft_skip_line(fd, p) == 1)
			return (1);
	}
	while (ft_empty_line(p->line) == 1)
	{
		if (ft_fill_map(fd, p, &i) == 0)
			return (0);
	}
	while (1)
	{
		umap = ft_check_under_map(fd, p, &i);
		if (umap == 0)
			return (0);
		if (umap == 1)
			return (1);
	}
	return (0);
}
