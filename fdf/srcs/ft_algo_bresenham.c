/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_bresenham_circle.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 11:36:07 by pmiceli           #+#    #+#             */
/*   Updated: 2017/12/19 12:34:38 by pmiceli          ###   ########.fr       */
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

void		bresenham_line(t_fdf fdf, t_put put, int color)
{
	put.dx = abs (put.x1 - put.x0);
	put.dy = -abs (put.y1 - put.y0);
	put.inc_x = put.x0 < put.x1 ? 1 : -1;
	put.inc_y = put.y0 < put.y1 ? 1 : -1;
	put.err = put.dx + put.dy;
	while (1)
	{
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
