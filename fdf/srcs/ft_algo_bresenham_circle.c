/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_bresenham_circle.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 11:36:07 by pmiceli           #+#    #+#             */
/*   Updated: 2017/12/09 18:45:39 by pmiceli          ###   ########.fr       */
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
