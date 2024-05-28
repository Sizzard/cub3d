/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aciezadl <aciezadl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:53:15 by aciezadl          #+#    #+#             */
/*   Updated: 2024/05/28 12:27:38 by aciezadl         ###   ########.fr       */
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

int	ft_check_rgb(char *str)
{
	int		i;
	int		nb_nike;
	char	*str_cpy;
	char	**rgb;

	i = 0;
	nb_nike = 0;
	str_cpy = ft_strdup(str);
	ft_remove_begin(str_cpy);
	rgb = ft_split(str_cpy, ',');
	if (!rgb)
		return (printf("erreur malloc\n"), 1);
	if (ft_atorgb(rgb[0]) == -1 || ft_atorgb(rgb[1]) == -1
		|| ft_atorgb(rgb[2]) == -1)
		return (free(str_cpy), ft_free_tabtab(rgb), 1);
	free(str_cpy);
	ft_free_tabtab(rgb);
	return (0);
}

int	ft_check_line(t_parse *fichier)
{
	if (fichier->line[0] == 'N' && fichier->line[1] == 'O'
		&& fichier->line[2] == ' ' && fichier->no != NULL)
		return (ft_printfd(2, "Error\nDouble NO\n"), 1);
	if (fichier->line[0] == 'N' && fichier->line[1] == 'O'
		&& fichier->line[2] == ' ' && fichier->no == NULL)
		return (fichier->no = ft_strdup(fichier->line), fichier->nb_data++, 0);
	if (fichier->line[0] == 'S' && fichier->line[1] == 'O'
		&& fichier->line[2] == ' ' && fichier->so != NULL)
		return (ft_printfd(2, "Error\nDouble SO\n"), 1);
	if (fichier->line[0] == 'S' && fichier->line[1] == 'O'
		&& fichier->line[2] == ' ' && fichier->so == NULL)
		return (fichier->so = ft_strdup(fichier->line), fichier->nb_data++, 0);
	if (fichier->line[0] == 'W' && fichier->line[1] == 'E'
		&& fichier->line[2] == ' ' && fichier->we != NULL)
		return (ft_printfd(2, "Error\nDouble WE\n"), 1);
	if (fichier->line[0] == 'W' && fichier->line[1] == 'E'
		&& fichier->line[2] == ' ' && fichier->we == NULL)
		return (fichier->we = ft_strdup(fichier->line), fichier->nb_data++, 0);
	if (fichier->line[0] == 'E' && fichier->line[1] == 'A'
		&& fichier->line[2] == ' ' && fichier->ea != NULL)
		return (ft_printfd(2, "Error\nDouble NO\n"), 1);
	if (fichier->line[0] == 'E' && fichier->line[1] == 'A'
		&& fichier->line[2] == ' ' && fichier->ea == NULL)
		return (fichier->ea = ft_strdup(fichier->line), fichier->nb_data++, 0);
	if (fichier->line[0] == 'F' && fichier->line[1] == ' '
		&& fichier->floor != NULL)
		return (ft_printfd(2, "Error\nDouble FLOOR\n"), 1);
	if (fichier->line[0] == 'F' && fichier->line[1] == ' '
		&& fichier->floor == NULL)
	{
		if (ft_check_coma(fichier->line) != 0
			|| ft_check_rgb(fichier->line) != 0)
			return (1);
		fichier->floor = ft_strdup(fichier->line);
		fichier->nb_data++;
		return (0);
	}
	if (fichier->line[0] == 'C' && fichier->line[1] == ' '
		&& fichier->ceiling != NULL)
		return (ft_printfd(2, "Error\nDouble CEILING\n"), 1);
	if (fichier->line[0] == 'C' && fichier->line[1] == ' '
		&& fichier->ceiling == NULL)
	{
		if (ft_check_coma(fichier->line) != 0
			|| ft_check_rgb(fichier->line) != 0)
			return (1);
		fichier->ceiling = ft_strdup(fichier->line);
		fichier->nb_data++;
		return (0);
	}
	if (fichier->line[0] == '\n')
		return (0);
	if (fichier->line[0] == '\0')
		return (1);
	else
		return (printf("Error\nWRONG DATA ARG : %s\n", fichier->line), 1);
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

// renvoi 0 si ligne vide ou 2 mots
int	ft_count_words_parse(const char *s, char c, t_parse *fichier)
{
	int	i;
	int	compteur;

	i = 0;
	compteur = 0;
	while (s[i] == c)
		i++;
	if (s[i] == '\n' || s[i] == '\0')
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
		return (ft_printfd(2, "Error\nWRONG DATA: %s\n", fichier->line), 1);
}

//renvoi 0 si c'est une ligne de map
int	ft_line_is_map(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if(str[i] == ' ' || str[i] == '1' || str[i] == '\n')
			i++;
		else
			return(1);
		if(str[i] == 0)
			return(0);
	}
	return(0);
}

//rempli la map, renvoi 1 si le premier strdup loupe
int	ft_create_map(int fd, t_parse *fichier)
{
	int i;
	i = 0;
	fichier->map[i] = ft_strdup(fichier->line);
		return(1);
	i++;
	while(1)
	{
		fichier->map[i] = get_next_line(fd);
		if(!fichier->map[i])
			return(0);
		i++;
	}
	return(0);
}

int	ft_first_line(char *str)
{
	int i;
	i = 0;

	while(str[i])
	{
		if(str[i] == '1' || str[i] == ' ' || str[i] == '\n')
			i++;
		else
		{
			ft_printfd(2, "Error\nWRONG CHAR 1ST LINE MAP\n");
			return(1);
		}
	}
	return(0);
}

//remvoi 1 si erreur de map
int	ft_check_map(char **map, int nb_start)
{
	int i;
	i = 0;
	if(ft_first_line(map[i]) == 1)
		return(ft_printfd(2, "Error\nINVALID MAP\n"), 1);
	i++;
	if(ft_empty_line(map[i]) == 1)
		return(ft_printfd(2, "Error\nINVALID MAP\n"), 1);
	while(map[i])
	{
		if(ft_empty_line(map[i]) == 1 || map[i+1][0] == '\0')
			break;
		if(ft_middle_line(map[i], nb_start) == 1)
			return(ft_printfd(2, "Error\nINVALID MAP\n"), 1);
		i++;
	}
	if(ft_last_line(map[i]) == 1)
		return(1);
	if(nb_start != 1)
		return(ft_printfd(2, "Error\nStarting position != 1\n"), 1);
	return(0);
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
		if (!fichier->line || ft_line_is_map(fichier->line) == 0)
			break ;
		ft_epur_str(fichier->line);
		if (ft_count_words_parse(fichier->line, ' ', fichier) == 1)
			return (1);
		if (ft_check_line(fichier) == 1)
			return (1);
		free(fichier->line);
	}
	if (fichier->nb_data != 6)
		return (free(fichier->line), ft_printfd(2, "Error\nDATA MANQUE\n"), 1);
	if(ft_create_map(fd, fichier) == 1 || ft_check_map(fichier->map, fichier->nb_start) == 1)
		return(close(fd), 1);
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
	fichier->map = NULL;
	fichier->nb_start = 0;
}
