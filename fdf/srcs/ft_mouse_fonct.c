/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_fonct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 22:22:28 by pmiceli           #+#    #+#             */
/*   Updated: 2018/01/16 03:42:11 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	ft_bleu_upper(t_fdf *fdf, int button, int x)
{
	if (x > 335 && x < 345 && button == 1 && fdf->pos.degrad.h_b >= 5)
		fdf->pos.degrad.h_b -= 5;
	if (x > 395 && x < 410 && button == 1 && fdf->pos.degrad.h_b <= 250)
		fdf->pos.degrad.h_b += 5;
	if (x > 365 && x < 385 && (button == 5 || button == 4))
	{
		if (button == 4 && fdf->pos.degrad.h_b < 255)
			fdf->pos.degrad.h_b++;
		else if (fdf->pos.degrad.h_b > 0)
			fdf->pos.degrad.h_b--;
	}
}

static void	ft_red_lower(t_fdf *fdf, int button, int x)
{
	if (x > 160 && x < 170 && button == 1 && fdf->pos.degrad.l_r >= 5)
		fdf->pos.degrad.l_r -= 5;
	if (x > 220 && x < 230 && button == 1 && fdf->pos.degrad.l_r <= 250)
		fdf->pos.degrad.l_r += 5;
	if (x > 185 && x < 205 && (button == 5 || button == 4))
	{
		if (button == 4 && fdf->pos.degrad.l_r < 255)
			fdf->pos.degrad.l_r++;
		else if (fdf->pos.degrad.l_r > 0)
			fdf->pos.degrad.l_r--;
	}
}

static void	ft_green_lower(t_fdf *fdf, int button, int x)
{
	if (x > 245 && x < 255 && button == 1 && fdf->pos.degrad.l_g >= 5)
		fdf->pos.degrad.l_g -= 5;
	if (x > 305 && x < 315 && button == 1 && fdf->pos.degrad.l_g <= 250)
		fdf->pos.degrad.l_g += 5;
	if (x > 270 && x < 290 && (button == 5 || button == 4))
	{
		if (button == 4 && fdf->pos.degrad.l_g < 255)
			fdf->pos.degrad.l_g++;
		else if (fdf->pos.degrad.l_g > 0)
			fdf->pos.degrad.l_g--;
	}
}

static void	ft_bleu_lower(t_fdf *fdf, int button, int x)
{
	if (x > 335 && x < 345 && button == 1 && fdf->pos.degrad.l_b >= 5)
		fdf->pos.degrad.l_b -= 5;
	if (x > 395 && x < 410 && button == 1 && fdf->pos.degrad.l_b <= 250)
		fdf->pos.degrad.l_b += 5;
	if (x > 365 && x < 385 && (button == 5 || button == 4))
	{
		if (button == 4 && fdf->pos.degrad.l_b < 255)
			fdf->pos.degrad.l_b++;
		else if (fdf->pos.degrad.l_b > 0)
			fdf->pos.degrad.l_b--;
	}
}

int			mouse_fonct(int button, int x, int y, t_fdf *fdf)
{
	if (y > 910 && y < 920)
	{
		if (x > 160 && x < 230)
			ft_red_upper(fdf, button, x);
		if (x > 245 && x < 315)
			ft_green_upper(fdf, button, x);
		if (x > 335 && x < 410)
			ft_bleu_upper(fdf, button, x);
		fdf->pos.high_color = (fdf->pos.degrad.h_r & 0xFF) << 16 |
			(fdf->pos.degrad.h_g & 0xFF) << 8 | (fdf->pos.degrad.h_b & 0xFF);
	}
	if (y > 930 && y < 945)
	{
		if (x > 160 && x < 230)
			ft_red_lower(fdf, button, x);
		if (x > 245 && x < 315)
			ft_green_lower(fdf, button, x);
		if (x > 335 && x < 410)
			ft_bleu_lower(fdf, button, x);
		fdf->pos.low_color = (fdf->pos.degrad.l_r & 0xFF) << 16 |
			(fdf->pos.degrad.l_g & 0xFF) << 8 | (fdf->pos.degrad.l_b & 0xFF);
	}
	fdf->repaint = 1;
	return (0);
}
