/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_bresenham.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 18:42:13 by pmiceli           #+#    #+#             */
/*   Updated: 2017/12/05 17:16:29 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		algo_bresenham_2(t_fdf fdf, t_pos pos, t_put put, int color)
{
	int dx;
	int dy;
	int inc_ne;
	int inc_e;
	int e;

	dx = put.x1 - put.x0;
	dy = put.y0 - put.y1;
	inc_e = 2 * dy;
	inc_ne = 2 * (dy - dx);
	e = 2 * (dy - dx);
	while (put.x1 >= put.x0)
	{
		mlx_pixel_put(fdf.mlx, fdf.win1, put.x0++, put.y0, color);
		if (e >= 0)
		{
			put.y0--;
			e = e + inc_ne;
		}
		else
			e = e + inc_e;
	}
}

static void		algo_bresenham_4(t_fdf fdf, t_pos pos, t_put put, int color)
{
	int dx;
	int dy;
	int inc_o;
	int inc_so;
	int e;

	dx = put.x0 - put.x1;
	dy = put.y1 - put.y0;
	inc_o = 2 * dy;
	inc_so = 2 * (dy - dx);
	e = 2 * (dy - dx);
	if (put.x0 == put.x1)
		while (put.y0 <= put.y1)
			mlx_pixel_put(fdf.mlx, fdf.win1, put.x0, put.y0++, color);
	while (put.x0 >= put.x1)
	{
		mlx_pixel_put(fdf.mlx, fdf.win1, put.x0--, put.y0, color);
	if (e >= 0)
	{
		put.y0++;
		e = e + inc_so;
	}
	else
		e = e + inc_o;
	}
}

static void		algo_bresenham_3(t_fdf fdf, t_pos pos, t_put put, int color)
{
	int		dx;
	int		dy;
	int		inc_o;
	int		inc_no;
	int		e;

	dx = put.x0 - put.x1;
	dy = put.y0 - put.y1;
	inc_o = 2 * dy;
	inc_no = 2 * (dy - dx);
	e = 2 * (dy - dx);
	if (put.x0 == put.x1)
		while (put.y0 >= put.y1)
			mlx_pixel_put(fdf.mlx, fdf.win1, put.x0, put.y0--, color);
	while (put.x0 >= put.x1)
	{
		mlx_pixel_put(fdf.mlx, fdf.win1, put.x0--, put.y0, color);
		if (e >= 0)
		{
			put.y0--;
			e = e + inc_no;
		}
		else
			e = e + inc_o;
	}
}

static void		algo_bresenham_1(t_fdf fdf, t_pos pos, t_put put, int color)
{
	int		dx;
	int		dy;
	int		inc_e;
	int		inc_se;
	int		e;

	dx = put.x1 - put.x0;
	dy = put.y1 - put.y0;
	inc_e = 2 * dy;
	inc_se = 2 * (dy - dx);
	e = 2 * (dy - dx);
	if (put.x0 == put.x1)
		while (put.y0 >= put.y1)
			mlx_pixel_put(fdf.mlx, fdf.win1, put.x0, put.y0--, color);
	while (put.x0 <= put.x1)
	{
		mlx_pixel_put(fdf.mlx, fdf.win1, put.x0++, put.y0, color);
		if (e >= 0)
		{
			put.y0 += 1;
			e += inc_se;
		}
		else
			e += inc_e;
	}
}

void		bresenham_line(t_fdf fdf, t_pos pos, t_put put, int color)
{
	int		dx;
	int		dy;
	int		inc_x;
	int		inc_y;

	dx = put.x1 - put.x0;
	dy = put.y1 - put.y0;
	if (dx <= 0 && dy <= 0)
	{
		algo_bresenham_3(fdf, pos, put, color);
	}
	else if (dx >= 0 && dy <= 0)
	{
		algo_bresenham_2(fdf, pos, put, color);
	}
	else if (dx <= 0 && dy >= 0)
	{
		algo_bresenham_4(fdf, pos, put, color);
	}
	else if (dx >= 0 && dy >= 0)
	{
		algo_bresenham_1(fdf, pos, put, color);
	}
}
