/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aciezadl <aciezadl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 10:44:46 by aciezadl          #+#    #+#             */
/*   Updated: 2024/06/06 16:25:47 by aciezadl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_atorgb(char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	if (!str || !str[i])
		return (printf("manque un nombre dans rgb\n"), -1);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (ft_printfd(2, "Error\nRGB WRONG FORMAT\n"), -1);
		if (str[i] >= '0' && str[i] <= '9')
		{
			res = res * 10 + (str[i] - 48);
			if (res > 255)
				return (ft_printfd(2, "Error\nRGB OVERFLOW\n"), -1);
			i++;
		}
		if (str[i] == '\n')
			return (res);
	}
	return (res);
}

void	ft_free_tabtab(char **str)
{
	int	i;

	if (str == NULL)
		return ;
	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

// renvoi le nb de virgules, renvoi 0 s'il y a bien les 2 virgules
int	ft_check_coma(char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (str[i])
	{
		if (str[i] == ',')
			res++;
		i++;
	}
	if (res == 2)
		return (0);
	else
	{
		ft_printfd(2, "Error\nWRONG COMA NB IN RGB\n");
		return (1);
	}
}

// check le format du p, doit etre en .cub
int	ft_check_fd(char *str)
{
	size_t	i;

	if (!str)
		return (printf("Error\npath = %s\n", str), 0);
	i = ft_strlen(str);
	if (str[i - 1] != 'b' || str[i - 2] != 'u' || str[i - 3] != 'c'
		|| str[i - 4] != '.')
	{
		ft_printfd(2, "Error\nMAUVAIS FORMAT DU p\n");
		return (1);
	}
	return (0);
}
