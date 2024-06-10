/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aciezadl <aciezadl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:08:55 by facarval          #+#    #+#             */
/*   Updated: 2024/06/10 12:02:45 by aciezadl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*ft_strndup(char *str, int begin, int end)
{
	char	*res;
	size_t	size;

	size = end - begin + 2;
	if (!str)
		return (NULL);
	res = malloc((size) * sizeof(char));
	if (!res)
		return (NULL);
	ft_strlcpy(res, &str[begin], size);
	return (res);
}
