/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_bresenham.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 18:42:13 by pmiceli           #+#    #+#             */
/*   Updated: 2017/12/18 19:59:59 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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
