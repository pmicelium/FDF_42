/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_fonc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 15:48:06 by pmiceli           #+#    #+#             */
/*   Updated: 2017/12/18 19:01:14 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		key_fonct(int keycode, t_key *key)
{
	ft_putnbr_endl(keycode);
	if (keycode == 53)
		exit(1);
	if (keycode == 69)
	{
		key->elev++;
		ft_putstr_color("elev : ", "yellow");
		ft_putnbr_endl(key->elev);
		return (1);
	}
	if (keycode == 78)
	{
		key->elev--;
		ft_putstr_color("elev : ", "yellow");
		ft_putnbr_endl(key->elev);
		return (1);
	}
	return (0);
}
