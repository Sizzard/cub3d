/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aciezadl <aciezadl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:53:15 by aciezadl          #+#    #+#             */
/*   Updated: 2024/06/04 15:56:19 by aciezadl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// check si la ligne correspond a une data
int	ft_check_line(t_parse *p)
{
	if (p->line[0] == 'N' && p->line[1] == 'O' && p->line[2] == ' '
		&& p->no != NULL)
		return (ft_printfd(2, "Error\nDouble NO\n"), 1);
	if (p->line[0] == 'N' && p->line[1] == 'O' && p->line[2] == ' '
		&& p->no == NULL)
		return (p->no = ft_strdup(p->line), p->nb_data++, 0);
	if (p->line[0] == 'S' && p->line[1] == 'O' && p->line[2] == ' '
		&& p->so != NULL)
		return (ft_printfd(2, "Error\nDouble SO\n"), 1);
	if (p->line[0] == 'S' && p->line[1] == 'O' && p->line[2] == ' '
		&& p->so == NULL)
		return (p->so = ft_strdup(p->line), p->nb_data++, 0);
	if (p->line[0] == 'W' && p->line[1] == 'E' && p->line[2] == ' '
		&& p->we != NULL)
		return (ft_printfd(2, "Error\nDouble WE\n"), 1);
	if (p->line[0] == 'W' && p->line[1] == 'E' && p->line[2] == ' '
		&& p->we == NULL)
		return (p->we = ft_strdup(p->line), p->nb_data++, 0);
	if (p->line[0] == 'E' && p->line[1] == 'A' && p->line[2] == ' '
		&& p->ea != NULL)
		return (ft_printfd(2, "Error\nDouble NO\n"), 1);
	if (p->line[0] == 'E' && p->line[1] == 'A' && p->line[2] == ' '
		&& p->ea == NULL)
		return (p->ea = ft_strdup(p->line), p->nb_data++, 0);
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
	if (p->line[0] == 'C' && p->line[1] == ' ' && p->ceiling != NULL)
		return (ft_printfd(2, "Error\nDouble CEILING\n"), 1);
	if (p->line[0] == 'C' && p->line[1] == ' ' && p->ceiling == NULL)
	{
		if (ft_check_coma(p->line) != 0 || ft_check_rgb(p->line) != 0)
			return (1);
		p->ceiling = ft_strdup(p->line);
		p->nb_data++;
		return (0);
	}
	if (p->line[0] == '\n')
		return (0);
	if (p->line[0] == '\0')
		return (1);
	else
		return (printf("Error\nWRONG DATA ARG : %s\n", p->line), 1);
	return (0);
}

int	ft_parse_data_file(t_parse *p, char *str)
{
	int	i;
	int	fd;

	i = 0;
	if (ft_check_fd(str) == 1)
		return (1);
	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (ft_printfd(2, "Error\nOPEN ERROR\n"), 1);
	while (1)
	{
		p->line = get_next_line(fd);
		if (!p->line)
			break ;
		ft_epur_str(p->line);
		if (ft_count_words_parse(p->line, ' ', p) == 1 || ft_check_line(p) == 1)
			return (ft_error_parse_begin(p), 1);
		free(p->line);
		if (p->nb_data == 6)
			break ;
	}
	if (p->nb_data != 6)
		return (ft_error_parse(p), ft_printfd(2, "Error\nDATA MANQUE\n"), 1);
	if (ft_create_map(fd, p) == 1 || ft_check_map(p->map, p) == 1)
		return (ft_printfd(2, "Error\nMAP\n"), ft_error_parse(p), close(fd), 1);
	return (close(fd), 0);
}
