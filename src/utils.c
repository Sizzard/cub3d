/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facarval <facarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:08:55 by facarval          #+#    #+#             */
/*   Updated: 2024/06/07 01:24:24 by facarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*ft_strndup(char *str, int begin, int end)
{
	char *res;
	size_t size;

	size = end - begin + 2;
	if (!str)
		return (NULL);
	res = malloc((size) * sizeof(char));
	if (!res)
		return (NULL);
	ft_strlcpy(res, &str[begin], size);
	return (res);
}