/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_data_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aciezadl <aciezadl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 10:48:07 by aciezadl          #+#    #+#             */
/*   Updated: 2024/06/11 11:12:57 by aciezadl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// return le nombre de nombre, il en faut 3
int	ft_count_nb_rgb(char *str)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 1 && (str[i + 1] == ',' || str[i + 1] == ' '
				|| str[i + 1] == '\0' || str[i + 1] == '\n'))
			count++;
		i++;
	}
	return (count);
}

int	ft_check_rgb(char *str)
{
	int		i;
	int		nb_nike;
	char	*str_cpy;
	char	**rgb;

	i = 0;
	nb_nike = 0;
	str_cpy = ft_strdup(str);
	if (!str_cpy)
		return (1);
	ft_remove_begin(str_cpy);
	if (ft_count_nb_rgb(str_cpy) != 3)
		return (free(str_cpy), ft_printfd(2, "Error\nRGB NUMBERS != 3\n"), 1);
	rgb = ft_split(str_cpy, ',');
	if (!rgb)
		return (ft_printfd(2, "Error\nMALLOC IN CHECK RGB\n"), free(str_cpy),
			1);
	if (ft_atorgb(rgb[0]) == -1 || ft_atorgb(rgb[1]) == -1
		|| ft_atorgb(rgb[2]) == -1)
		return (free(str_cpy), ft_free_tabtab(rgb), 1);
	free(str_cpy);
	ft_free_tabtab(rgb);
	return (0);
}

/*renvoi 0 si ligne vide ou 2 mots
return 0 si la ligne est le C ou le F sans compter le nb d'espaces*/
int	ft_count_words_parse(const char *s, char c, t_parse *p)
{
	int	i;
	int	compteur;

	i = 0;
	compteur = 0;
	while (s[i] == c)
		i++;
	if (s[i] == '\n' || s[i] == '\0')
		return (0);
	if (s[i] == 'C' || s[i] == 'F')
		return (0);
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == 0))
			compteur++;
		i++;
	}
	if (compteur == 2)
		return (0);
	else
		return (ft_printfd(2, "Error\nWRONG DATA: %s\n", p->line), 1);
}

// return 0 si ligne remplie d'espaces ou commence par '\n' ou '\0'
int	ft_empty_line(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (1);
	while (str[i] != '\n' && str[i] != '\0')
	{
		if (str[i] != ' ')
			return (1);
		i++;
	}
	if (str[i] == '\n' || str[i] != '\0')
		return (0);
	else
		return (1);
}

// return 0 si ligne remplie d'espaces ou commence par '\n' ou '\0'
int	ft_empty_line_end(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '\n' || str[i] == '\0')
		return (0);
	else
		return (1);
}
