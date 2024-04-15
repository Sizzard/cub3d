/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facarval <facarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:08:55 by facarval          #+#    #+#             */
/*   Updated: 2024/04/15 09:55:33 by facarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double	ft_abs(double nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

int	ft_inverse(t_data *data, int nb)
{
	return (data->screen_size_x - nb);
}