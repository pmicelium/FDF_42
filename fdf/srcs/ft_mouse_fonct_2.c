/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_fonct_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 21:31:17 by pmiceli           #+#    #+#             */
/*   Updated: 2018/01/19 05:30:39 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_red_upper(t_fdf *fdf, int button, int x)
{
	if (x > 160 && x < 170 && button == 1 && fdf->pos.degrad.h_r >= 5)
		fdf->pos.degrad.h_r--;
	if (x > 220 && x < 230 && button == 1 && fdf->pos.degrad.h_r <= 250)
		fdf->pos.degrad.h_r++;
	if (x > 185 && x < 205 && (button == 5 || button == 4))
	{
		if (button == 4 && fdf->pos.degrad.h_r < 255)
			fdf->pos.degrad.h_r += 5;
		else if (fdf->pos.degrad.h_r > 0)
			fdf->pos.degrad.h_r -= 5;
	}
}

void	ft_green_upper(t_fdf *fdf, int button, int x)
{
	if (x > 245 && x < 255 && button == 1 && fdf->pos.degrad.h_g >= 5)
		fdf->pos.degrad.h_g--;
	if (x > 305 && x < 315 && button == 1 && fdf->pos.degrad.h_g <= 250)
		fdf->pos.degrad.h_g++;
	if (x > 270 && x < 290 && (button == 5 || button == 4))
	{
		if (button == 4 && fdf->pos.degrad.h_g < 255)
			fdf->pos.degrad.h_g += 5;
		else if (fdf->pos.degrad.h_g > 0)
			fdf->pos.degrad.h_g -= 5;
	}
}

void	mouse_fonct_zoom(int button, t_fdf *fdf)
{
	if (button == 4)
		fdf->key.zoom += 3;
	if (button == 5)
		fdf->key.zoom -= 3;
}
