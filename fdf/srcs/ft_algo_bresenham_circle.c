/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_bresenham_circle.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 11:36:07 by pmiceli           #+#    #+#             */
/*   Updated: 2017/12/05 14:51:45 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		bresenham_circle(t_fdf fdf, t_pos pos, t_put put)
{
	int		x;
	int		y;
	double	d;

	x = 0;
	y = put.r;
	d = 5.0 - 4.0 * put.r;
	while (x <= y)
	{
		mlx_pixel_put(fdf.mlx, fdf.win1, x + put.o_x, y + put.o_y, 0x00FFFFFF);
		mlx_pixel_put(fdf.mlx, fdf.win1, y + put.o_x, x + put.o_y, 0x00FFFFFF);
		mlx_pixel_put(fdf.mlx, fdf.win1, -x + put.o_x, y + put.o_y, 0x00FFFFFF);
		mlx_pixel_put(fdf.mlx, fdf.win1, -y + put.o_x, x + put.o_y, 0x00FFFFFF);
//		mlx_pixel_put(fdf.mlx, fdf.win1, x + put.o_x, -y + put.o_y, 0x00FFFFFF);
//		mlx_pixel_put(fdf.mlx, fdf.win1, y + put.o_x, -x + put.o_y, 0x00FFFFFF);
//		mlx_pixel_put(fdf.mlx, fdf.win1, -x + put.o_x, -y + put.o_y, 0x00FFFFFF);
//		mlx_pixel_put(fdf.mlx, fdf.win1, -y + put.o_x, -x + put.o_y, 0x00FFFFFF);
		if (d > 0)
		{
			y--;
			d = d - 8 * y;
		}
		x++;
		d = d + 8 * x + 4;
	}
}
