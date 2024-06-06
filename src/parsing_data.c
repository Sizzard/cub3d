/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aciezadl <aciezadl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:53:15 by aciezadl          #+#    #+#             */
/*   Updated: 2024/06/06 16:21:03 by aciezadl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// return 0 si data C, 1 si data non valide ou doublon
int	ft_is_c(t_parse *p)
{
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
	else
		return (2);
}

// return 0 si la ligne correspond a une data
int	ft_check_line(t_parse *p)
{
	int	res;

	res = ft_is_no(p);
	if (res == 0 || res == 1)
		return (res);
	res = ft_is_so(p);
	if (res == 0 || res == 1)
		return (res);
	res = ft_is_we(p);
	if (res == 0 || res == 1)
		return (res);
	res = ft_is_ea(p);
	if (res == 0 || res == 1)
		return (res);
	res = ft_is_f(p);
	if (res == 0 || res == 1)
		return (res);
	res = ft_is_c(p);
	if (res == 0 || res == 1)
		return (res);
	if (p->line[0] == '\n')
		return (0);
	else
		return (printf("Error\nWRONG DATA ARG : %s\n", p->line), 1);
	return (0);
}

int	ft_parse_data_file(t_parse *p, char *str)
{
	int	fd;

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
		return (ft_error_parse_begin(p), ft_printfd(2, "Error\nDATA MISS\n"),
			1);
	if (ft_create_map(fd, p) == 1 || ft_check_map(p->map, p) == 1)
		return (ft_printfd(2, "Error\nMAP\n"), ft_error_parse(p), close(fd), 1);
	return (close(fd), 0);
}
