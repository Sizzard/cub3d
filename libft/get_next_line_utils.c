/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aciezadl <aciezadl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:41:20 by aciezadl          #+#    #+#             */
/*   Updated: 2024/06/10 15:36:08 by aciezadl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_realloc(char *line, int size)
{
	char	*temp;

	temp = malloc(size);
	if (!temp)
		return (NULL);
	ft_bzero(temp, size);
	ft_strlcpy(temp, line, size);
	free(line);
	return (temp);
}

void	gnl3(char *stash, char *line, char *buffer, int *tab)
{
	while (tab[5] < tab[1])
	{
		line[tab[2]] = buffer[tab[5]];
		if (buffer[tab[5]] == '\n')
		{
			while (tab[5] + 1 < tab[1])
			{
				tab[5]++;
				stash[tab[3]] = buffer[tab[5]];
				tab[3]++;
			}
			stash[tab[3]] = 0;
			tab[4]++;
		}
		tab[5]++;
		tab[2]++;
	}
}
