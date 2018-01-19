/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_bresenham.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 20:24:05 by pmiceli           #+#    #+#             */
/*   Updated: 2018/01/19 03:17:44 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int		ft_degraded(t_degrad degrad, double i)
{
	int		r;
	int		g;
	int		b;
	int		color;

	r = (degrad.c_r - degrad.b_r) * i + degrad.b_r;
	g = (degrad.c_g - degrad.b_g) * i + degrad.b_g;
	b = (degrad.c_b - degrad.b_b) * i + degrad.b_b;
	color = (r & 0xFF) << 16 | (g & 0xFF) << 8 | (b & 0xFF);
	return (color);
}

static t_put	ft_set_put_line(t_put put)
{
	put.dx = ft_abs(put.x1 - put.x0);
	put.dy = -ft_abs(put.y1 - put.y0);
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

void			bresenham_line(t_fdf fdf, t_put put)
{
	int		i;
	double	steap;
	int		color;

	i = 0;
	steap = sqrt(pow((put.x1 - put.x0), 2) + pow((put.y1 - put.y0), 2));
	put = ft_set_put_line(put);
	fdf.pos.degrad.b_r = (put.color >> 16) & 0xFF;
	fdf.pos.degrad.b_g = (put.color >> 8) & 0xFF;
	fdf.pos.degrad.b_b = (put.color) & 0xFF;
	fdf.pos.degrad.c_r = (put.color1 >> 16) & 0xFF;
	fdf.pos.degrad.c_g = (put.color1 >> 8) & 0xFF;
	fdf.pos.degrad.c_b = (put.color1) & 0xFF;
	while (1)
	{
		color = ft_degraded(fdf.pos.degrad, i++ / steap);
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
