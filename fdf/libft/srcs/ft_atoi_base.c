/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 02:00:04 by pmiceli           #+#    #+#             */
/*   Updated: 2018/01/19 22:08:57 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	clear(char const *str)
{
	int			i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\f' || str[i] == '\t'
			|| str[i] == '\v' || str[i] == '\r')
		i++;
	if (str[i] == '0' && str[i + 1] == 'x')
		i += 2;
	return (i);
}

int			ft_atoi_base(char const *str, char *base)
{
	int		val;
	int		i;
	int		sign;
	int		base_len;
	int		digit;

	val = 0;
	sign = 1;
	base_len = ft_strlen(base);
	i = clear(str);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && ft_strchr(base, ft_toupper(str[i])) != NULL)
	{
		digit = ft_toupper(str[i]);
		digit = (str[i] >= 'A') ? digit - 'A' + 10 : digit - '0';
		if (digit >= 0 && digit < base_len)
			val = val * base_len + digit;
		i++;
	}
	return (sign * val);
}
