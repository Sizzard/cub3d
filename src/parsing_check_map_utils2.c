/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_check_map_utils2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aciezadl <aciezadl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 10:59:36 by aciezadl          #+#    #+#             */
/*   Updated: 2024/06/11 09:53:04 by aciezadl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// return 0 si le char de la map n'est pas ok
int	ft_char_is_wrong(char c)
{
	if (c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'E' || c == 'W'
		|| c == '\n' || c == '\0' || c == ' ')
		return (1);
	else
		return (0);
}

void    ft_lst_print(t_list *list)
{
    while(list)
    {
        printf("lst %s\n", list->content);
        // if(list->next == NULL)
        //     return ;
        list = list->next;
    }
}

// return 0 si on est sur une ligne map
int	ft_is_map(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (ft_char_is_ok(str[i]) == 0)
		return (0);
	return (1);
}

// copie le fichier dans une liste chainee
int	ft_cp_fd(t_parse *p, char *str, t_list  *list)
{
	int		fd;
	char	*line;
    // t_list  *tmp;

    (void)list;
    p->nb_line_map = 0;
	line = NULL;
	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (ft_printfd(2, "Error\nOPEN ERROR CP MAP\n"), 1);
	line = get_next_line(fd);
	if (!line)
		return (ft_printfd(2, "Error\nMALLOC ERROR CP MAP\n"), 1);
	while (line)
	{
        // printf("line %s\n", line);
        if(ft_is_map(line) == 0)
            p->nb_line_map++;
        // tmp = ft_lstnew((char *)line);
        // ft_lstadd_back(&list, tmp);
		free(line);
		line = get_next_line(fd);
		if (!line)
			break ;
	}
	return (close(fd), free(line), 0);
}
