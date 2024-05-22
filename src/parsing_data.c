/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aciezadl <aciezadl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:53:15 by aciezadl          #+#    #+#             */
/*   Updated: 2024/05/22 15:38:22 by aciezadl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// check le format du fichier, doit etre en .cub
int	ft_check_fd(char *str)
{
	size_t	i;

	if (!str)
		return (printf("Error\npath = %s\n", str), 0);
	i = ft_strlen(str);
	if (str[i - 1] != 'b' || str[i - 2] != 'u' || str[i - 3] != 'c' || str[i
		- 4] != '.')
	{
		ft_printfd(2, "Error\nMAUVAIS FORMAT DU FICHIER\n");
		return (1);
	}
	return (0);
}

int	ft_atorgb(char *str)
{
	int				i;
	int				sign;
	unsigned char	res;

	i = 0;
	sign = 1;
	res = 0;
	if (str[i] == 0)
		return (0);
	while (str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		return (ft_printfd(2, "Error\n RGB WRONG FORMAT\n"), -1);
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - 48);
		if (res < 0)
			return (ft_printfd(2, "Error\n RGB OVERFLOW\n"), -1);
		i++;
	}
	return (res * sign);
}

int	ft_check_line(t_parse *fichier)
{
	if (fichier->line[0] == 'N' && fichier->line[1] == 'O'
		&& fichier->no != NULL)
		return (ft_printfd(2, "Error\nDouble NO\n"), 1);
	if (fichier->line[0] == 'N' && fichier->line[1] == 'O'
		&& fichier->no == NULL)
		return (fichier->no = ft_strdup(fichier->line), fichier->nb_data++, 0);
	if (fichier->line[0] == 'S' && fichier->line[1] == 'O'
		&& fichier->so != NULL)
		return (ft_printfd(2, "Error\nDouble SO\n"), 1);
	if (fichier->line[0] == 'S' && fichier->line[1] == 'O'
		&& fichier->so == NULL)
		return (fichier->so = ft_strdup(fichier->line), fichier->nb_data++, 0);
	if (fichier->line[0] == 'W' && fichier->line[1] == 'E'
		&& fichier->we != NULL)
		return (ft_printfd(2, "Error\nDouble WE\n"), 1);
	if (fichier->line[0] == 'W' && fichier->line[1] == 'E'
		&& fichier->we == NULL)
		return (fichier->we = ft_strdup(fichier->line), fichier->nb_data++, 0);
	if (fichier->line[0] == 'E' && fichier->line[1] == 'A'
		&& fichier->ea != NULL)
		return (ft_printfd(2, "Error\nDouble NO\n"), 1);
	if (fichier->line[0] == 'E' && fichier->line[1] == 'A'
		&& fichier->ea == NULL)
		return (fichier->ea = ft_strdup(fichier->line), fichier->nb_data++, 0);
	if (fichier->line[0] == 'F' && fichier->floor != NULL)
		return (ft_printfd(2, "Error\nDouble FLOOR\n"), 1);
	if (fichier->line[0] == 'F' && fichier->floor == NULL)
	{
		if (ft_atorgb(fichier->line) == 1)
			return (ft_printfd(2, "Error\nRGB OVERFLOW\n"), 1);
		return (fichier->floor = ft_strdup(fichier->line), fichier->nb_data++, 0);
	}
	if (fichier->line[0] == 'C' && fichier->ceiling != NULL)
		return (ft_printfd(2, "Error\nDouble CEILING\n"), 1);
	if (fichier->line[0] == 'C' && fichier->ceiling == NULL)
		return (fichier->ceiling = ft_strdup(fichier->line), fichier->nb_data++, 0);
	if (fichier->line[0] == '\n')
		return (0);
	if (fichier->line[0] == '\0')
		return (1);
	else
		return (printf("Error\nMAUVAISE DATA : %s\n", fichier->line), 1);
	return (0);
}

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
		j++;
	}
	str[j] = 0;
}

int	ft_parse_data_file(t_parse *fichier, char *str)
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
		fichier->line = get_next_line(fd);
		if (!fichier->line)
			break;
		ft_epur_str(fichier->line);
		if (ft_check_line(fichier) == 1)
			return (1);
		free(fichier->line);
	}
	if(fichier->nb_data != 6)
		return(free(fichier->line), ft_printfd(2, "Error\nDATA MANQUE\n"), 1);
	return (close(fd), 0);
}

void	ft_init_parse(t_parse *fichier)
{
	fichier->nb_data = 0;
	fichier->ceiling = NULL;
	fichier->floor = NULL;
	fichier->no = NULL;
	fichier->ea = NULL;
	fichier->so = NULL;
	fichier->we = NULL;
}
