/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_check_map_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aciezadl <aciezadl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 10:43:06 by aciezadl          #+#    #+#             */
/*   Updated: 2024/06/04 11:59:52 by aciezadl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// return 0 si char est un vide '0', ou le start
int	ft_char_is_checkable(char c)
{
	if (!c || c == '\0')
		return (1);
	if (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (0);
	else
		return (1);
}

// return 0 si char est un mur '1', un vide '0', ou le start
int	ft_char_is_ok(char c)
{
	if (!c || c == '\0')
		return (1);
	if (c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (0);
	else
		return (1);
}

// return 0 si char est le start
int	ft_char_is_start(char c)
{
	if (!c || c == '\0')
		return (1);
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (0);
	else
		return (1);
}

// return 0 si la 1ere ligne contient que des 1, ' ' et '\n'
int	ft_first_line(char **map, int i)
{
	int	j;

	j = 0;
	while (map[i][j])
	{
		if (map[i][j] == '\0' || map[i][j] == '\n')
			return (0);
		if (map[i][j] == '1' || map[i][j] == ' ')
			j++;
		else
			return (1);
	}
	return (0);
}

int	ft_last_line(char **map, int i)
{
	int	j;

	j = 0;
	while (map[i][j])
	{
		if (map[i][j] == '\0' || map[i][j] == '\n')
			return (0);
		if (map[i][j] == '1' || map[i][j] == ' ')
			j++;
		else
			return (1);
	}
	return (0);
}
