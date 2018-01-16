/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_bresenham.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 20:24:05 by pmiceli           #+#    #+#             */
/*   Updated: 2018/01/16 05:57:34 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int		ft_degraded(t_fdf fdf, double i, int color0, int color1)
{
	int		r;
	int		g;
	int		b;
	int		color;

	fdf.pos.degrad.b_r = (color0 >> 16) & 0xFF;
	fdf.pos.degrad.b_g = (color0 >> 8) & 0xFF;
	fdf.pos.degrad.b_b = (color0) & 0xFF;
	fdf.pos.degrad.c_r = (color1 >> 16) & 0xFF;
	fdf.pos.degrad.c_g = (color1 >> 8) & 0xFF;
	fdf.pos.degrad.c_b = (color1) & 0xFF;
	r = abs(fdf.pos.degrad.b_r - fdf.pos.degrad.c_r) * i +
		ft_nbrmin(fdf.pos.degrad.b_r, fdf.pos.degrad.c_r);
	g = abs(fdf.pos.degrad.b_g - fdf.pos.degrad.c_g) * i +
		ft_nbrmin(fdf.pos.degrad.b_g, fdf.pos.degrad.c_g);
	b = abs(fdf.pos.degrad.b_b - fdf.pos.degrad.c_b) * i +
		ft_nbrmin(fdf.pos.degrad.b_b, fdf.pos.degrad.c_b);
	color = (r & 0xFF) << 16 | (g & 0xFF) << 8 | (b & 0xFF);
	return (color);
}


static t_put	ft_set_put_line(t_put put)
{
	put.dx = abs(put.x1 - put.x0);
	put.dy = -abs(put.y1 - put.y0);
	put.inc_x = put.x0 < put.x1 ? 1 : -1;
	put.inc_y = put.y0 < put.y1 ? 1 : -1;
	put.err = put.dx + put.dy;
	return (put);
}

static t_put	bresenham_line_2(t_put put)
{
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
	return (put);
}

void			bresenham_line(t_fdf fdf, t_put put, int color, int degrad)
{
	int		i;
	double	steap;

	degrad = 0;
	i = 0;
	steap = sqrt(pow((put.x1 - put.x0), 2) + pow((put.y1 - put.y0), 2));
	put = ft_set_put_line(put);
	while (1)
	{
	//	if (degrad != 0)
		color = ft_degraded(fdf, i++ / steap, put.color, put.color1);
		if (put.y0 * X_WIN_1 + put.x0 < X_WIN_1 * Y_WIN_1
				&& put.y0 >= 0 && put.x0 >= 0
				&& put.y0 < Y_WIN_1 && put.x0 < X_WIN_1)
			fdf.img_data[put.y0 * X_WIN_1 + put.x0] = color;
		if (put.x0 == put.x1 && put.y0 == put.y1)
			break ;
		put.e2 = 2 * put.err;
		put = bresenham_line_2(put);
	}
}
