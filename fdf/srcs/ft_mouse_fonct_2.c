/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_fonct_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 21:31:17 by pmiceli           #+#    #+#             */
/*   Updated: 2017/12/25 21:31:55 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_red_upper(t_fdf *fdf, int button, int x)
{
	if (x > 160 && x < 170 && button == 1 && fdf->degrad.h_r >= 5)
		fdf->degrad.h_r -= 5;
	if (x > 220 && x < 230 && button == 1 && fdf->degrad.h_r <= 250)
		fdf->degrad.h_r += 5;
	if (x > 185 && x < 205 && (button == 5 || button == 4))
	{
		if (button == 4 && fdf->degrad.h_r < 255)
			fdf->degrad.h_r++;
		else if (fdf->degrad.h_r > 0)
			fdf->degrad.h_r--;
	}
}

void	ft_green_upper(t_fdf *fdf, int button, int x)
{
	if (x > 245 && x < 255 && button == 1 && fdf->degrad.h_g >= 5)
		fdf->degrad.h_g -= 5;
	if (x > 305 && x < 315 && button == 1 && fdf->degrad.h_g <= 250)
		fdf->degrad.h_g += 5;
	if (x > 270 && x < 290 && (button == 5 || button == 4))
	{
		if (button == 4 && fdf->degrad.h_g < 255)
			fdf->degrad.h_g++;
		else if (fdf->degrad.h_g > 0)
			fdf->degrad.h_g--;
	}
}
