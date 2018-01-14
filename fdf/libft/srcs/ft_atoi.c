/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:29:36 by pmiceli           #+#    #+#             */
/*   Updated: 2017/11/09 10:11:55 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(char const *str)
{
	int		val;
	int		i;
	int		sign;

	i = 0;
	val = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\f' || str[i] == '\t'
			|| str[i] == '\v' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && (str[i] >= 48 && str[i] <= 57))
		val = val * 10 + (str[i++] - '0');
	return (sign * val);
}
