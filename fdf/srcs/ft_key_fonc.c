/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_fonc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 15:48:06 by pmiceli           #+#    #+#             */
/*   Updated: 2017/12/09 15:54:16 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		key_fonct(int keycode, void *param)
{
	ft_putnbr_endl(keycode);
	if (keycode == 53)
		exit(1);
	return (0);
}
