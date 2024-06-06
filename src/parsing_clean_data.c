/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_clean_data.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aciezadl <aciezadl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:48:25 by aciezadl          #+#    #+#             */
/*   Updated: 2024/06/06 16:47:31 by aciezadl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// supprime le ou les permiers characteres de la ligne data
void	ft_remove_begin(char *str)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (ft_isalpha(str[i]) == 1)
		i++;
	i++;
	while (str[i])
	{
		str[j] = str[i];
		i++;
		j++;
	}
	str[j] = 0;
}

// supprime les espaces en trop, laisse un espace entre les mots
int	ft_epur_str(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] == ' ')
		i++;
	while (str[i])
	{
		while (str[i] && str[i] != ' ')
		{
			str[j++] = str[i++];
			if (str[i] == 0)
				return (str[j] = 0);
		}
		while (str[i] == ' ')
		{
			if (str[++i] == 0)
				return (str[j] = 0);
			if (str[i] == '\n')
				return (str[j] = '\n', str[j + 1] = 0);
		}
		str[j++] = ' ';
	}
	return (str[j] = 0);
}
