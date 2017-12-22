/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_bresenham.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 20:24:05 by pmiceli           #+#    #+#             */
/*   Updated: 2017/12/22 21:44:24 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		bresenham_circle(t_fdf fdf, t_put put, int color)
{
	int		x;
	int		y;
	double	d;

	x = 0;
	y = put.r;
	d = 5.0 - 4.0 * put.r;
	while (x <= y)
	{
		fdf.img_data[(y + put.o_y) * X_WIN_1 + (x + put.o_x)] = color;
		fdf.img_data[(x + put.o_y) * X_WIN_1 + (y + put.o_x)] = color;
		fdf.img_data[(y + put.o_y) * X_WIN_1 + (-x + put.o_x)] = color;
		fdf.img_data[(x + put.o_y) * X_WIN_1 + (-y + put.o_x)] = color;
		fdf.img_data[(-y + put.o_y) * X_WIN_1 + (x + put.o_x)] = color;
		fdf.img_data[(-x + put.o_y) * X_WIN_1 + (y + put.o_x)] = color;
		fdf.img_data[(-y + put.o_y) * X_WIN_1 + (-x + put.o_x)] = color;
		fdf.img_data[(-x + put.o_y) * X_WIN_1 + (-y + put.o_x)] = color;
		if (d > 0)
		{
			y--;
			d = d - 8 * y;
		}
		x++;
		d = d + 8 * x + 4;
	}
}

static int	ft_degraded(t_fdf fdf, double i, t_put put, int degrad)
{
	int r;
	int g;
	int b;
	int color;

	if (degrad == 1)
	{
		r = (fdf.degrad.h_r - fdf.degrad.l_r) * i + fdf.degrad.l_r;
		g = (fdf.degrad.h_g - fdf.degrad.l_g) * i + fdf.degrad.l_g;
		b = (fdf.degrad.h_b - fdf.degrad.l_b) * i + fdf.degrad.l_b;
		color = (r & 0xFF) << 16 | (g & 0xFF) << 8 | (b & 0xFF);
	}
	else
	{
		r = (fdf.degrad.l_r - fdf.degrad.h_r) * i + fdf.degrad.h_r;
		g = (fdf.degrad.l_g - fdf.degrad.h_g) * i + fdf.degrad.h_g;
		b = (fdf.degrad.l_b - fdf.degrad.h_b) * i + fdf.degrad.h_b;
		color = (r & 0xFF) << 16 | (g & 0xFF) << 8 | (b & 0xFF);
	}
//	printf("%X,%d, %d, %d\n", color, r, g, b);
	return (color);
}

void		bresenham_line(t_fdf fdf, t_put put, int color, int degrad)
{
	int i;
	double steap;

	steap = sqrt(pow((put.x1 - put.x0), 2) + pow((put.y1 - put.y0), 2));
	i = 0;
	put.dx = abs (put.x1 - put.x0);
	put.dy = -abs (put.y1 - put.y0);
	put.inc_x = put.x0 < put.x1 ? 1 : -1;
	put.inc_y = put.y0 < put.y1 ? 1 : -1;
	put.err = put.dx + put.dy;
	while (1)
	{
		if (degrad != 0)
			color = ft_degraded(fdf, i++ / steap, put, degrad);
		fdf.img_data[put.y0 * X_WIN_1 + put.x0] = color;
		if (put.x0 == put.x1 && put.y0 == put.y1)
			break;
		put.e2 = 2 * put.err;
		if (put.e2 >= put.dy) 
		{
			put.err += put.dy;
			put.x0 += put.inc_x;
		}
		if (put.e2 <= put.dx)
		{
			put.err += put.dx; 
			put.y0 += put.inc_y; 
		}
	}
}
