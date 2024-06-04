/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_clean_data.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aciezadl <aciezadl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:48:25 by aciezadl          #+#    #+#             */
/*   Updated: 2024/06/04 14:58:50 by aciezadl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

//supprime le ou les permiers characteres de la data
void	ft_remove_begin(char *str)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while(ft_isalpha(str[i]) == 1)
			i++;
	i++;
	while(str[i])
	{
		str[j] = str[i];
		i++;
		j++;
	}
	str[j] = 0;
}

//supprime les espaces en trop
void	ft_epur_str(char *str)
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
			str[j] = str[i];
			i++;
			j++;
			if (str[i] == 0)
			{
				str[j] = 0;
				return ;
			}
		}
		while (str[i] == ' ')
		{
			i++;
			if (str[i] == 0)
			{
				str[j] = 0;
				return ;
			}
			if (str[i] == '\n')
			{
				str[j] = '\n';
				str[j + 1] = 0;
				return ;
			}
		}
		str[j] = ' ';
		j++;
	}
	str[j] = 0;
}
