/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_check_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aciezadl <aciezadl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 10:40:48 by aciezadl          #+#    #+#             */
/*   Updated: 2024/06/04 15:04:48 by aciezadl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// return 0 si le char est entoure de valides char
int	ft_char_is_surrounded(char **map, int i, int j) {
  if (ft_char_is_checkable(map[i][j]) == 0 && j > 0 &&
      (int)ft_strlen(map[i - 1]) >= j && ft_char_is_ok(map[i - 1][j]) == 0 &&
      (int)ft_strlen(map[i + 1]) >= j && ft_char_is_ok(map[i + 1][j]) == 0 &&
      ft_char_is_ok(map[i][j + 1]) == 0 && ft_char_is_ok(map[i][j - 1]) == 0)
    return (0);
  else
    return (1);
}

// return 0 si le char n'est pas entoure de valides char
int	ft_char_is_not_surrounded(char **map, int i, int j) {
  if (ft_char_is_checkable(map[i][j]) == 0 &&
      (j == 0 || (int)ft_strlen(map[i - 1]) < j ||
       ft_char_is_ok(map[i - 1][j]) == 1 || (int)ft_strlen(map[i - 1]) < j ||
       ft_char_is_ok(map[i + 1][j]) == 1 || ft_char_is_ok(map[i][j + 1]) == 1 ||
       ft_char_is_ok(map[i][j - 1]) == 1))
    return (0);
  else
    return (1);
}

// check si les 0 ou directions sont entoures par un char ok
int	ft_middle_line(char **map, int i, t_parse *p) {
  int j;

  j = 0;
  while (map[i][j] && map[i][j] == ' ')
    j++;
  while (map[i][j] && map[i + 1]) {
    if (ft_char_is_surrounded(map, i, j) == 0) {
      if (ft_char_is_start(map[i][j]) == 0)
        p->nb_start++;
      if (p->nb_start > 1)
        return (ft_printfd(2, "Error\nSeveral START\n"), 1);
      j++;
    }
    if (ft_char_is_not_surrounded(map, i, j) == 0)
      return (ft_printfd(2, "Error\nPB MAP\n"), 1);
    if (map[i][j] == ' ' || map[i][j] == '1')
      j++;
    if (map[i][j] == '\n')
      break ;
  }
  return (0);
}

// return 2 quand on arrive sur la derniere ligne, incremente pas le nb_data
int	ft_middle_line_nonb(char **map, int i) {
  int j;

  j = 0;
  while (map[i][j] && map[i][j] == ' ')
    j++;
  while (map[i][j] && map[i + 1]) {
    if (ft_char_is_surrounded(map, i, j) == 0)
      j++;
    if (ft_char_is_not_surrounded(map, i, j) == 0)
      return (ft_printfd(2, "Error\nPB MAP\n"), 1);
    if (map[i][j] == ' ' || map[i][j] == '1')
      j++;
    if (map[i][j] == '\n')
      break ;
  }
  if (!map[i + 1])
    return (2);
  return (0);
}

// renvoi 1 si erreur de map
int	ft_check_map(char **map, t_parse *p) {
  int i;

  i = 0;
  if (ft_first_line(map, i) == 1)
    return (ft_printfd(2, "Error\nINVALID FIRST LINE\n"), 1);
  i++;
  while (map[i]) {
    if (ft_middle_line(map, i, p) == 1)
      return (ft_printfd(2, "Error\nINVALID MAP\n"), 1);
    if (ft_middle_line_nonb(map, i) == 2)
      break ;
    i++;
  }
  if (ft_last_line(map, i) == 1)
    return (ft_printfd(2, "Error\nINVALID LAST LINE\n"), 1);
  if (p->nb_start != 1)
    return (ft_printfd(2, "Error\nStarting position != 1\n"), 1);
  return (0);
}
