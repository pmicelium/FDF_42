/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_bresenham.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 18:42:13 by pmiceli           #+#    #+#             */
/*   Updated: 2017/12/04 23:35:52 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		algo_bresenham_2(t_fdf fdf, t_pos pos, t_put put)
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
		mlx_pixel_put(fdf.mlx, fdf.win1, put.x0++, put.y0, 0x000000FF);
		if (e >= 0)
		{
			put.y0--;
			e = e + inc_ne;
		}
		else
			e = e + inc_e;
	}
}

static void		algo_bresenham_4(t_fdf fdf, t_pos pos, t_put put)
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
			mlx_pixel_put(fdf.mlx, fdf.win1, put.x0, put.y0++, 0x00FF0000);
	while (put.x0 >= put.x1)
	{
	mlx_pixel_put(fdf.mlx, fdf.win1, put.x0--, put.y0, 0x00FF0000);
	if (e >= 0)
	{
		put.y0++;
		e = e + inc_so;
	}
	else
		e = e + inc_o;
	}
}

static void		algo_bresenham_3(t_fdf fdf, t_pos pos, t_put put)
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
			mlx_pixel_put(fdf.mlx, fdf.win1, put.x0, put.y0--, 0x0000FF00);
	while (put.x0 >= put.x1)
	{
		mlx_pixel_put(fdf.mlx, fdf.win1, put.x0--, put.y0, 0x0000FF00);
		if (e >= 0)
		{
			put.y0--;
			e = e + inc_no;
		}
		else
			e = e + inc_o;
	}
}

static void		algo_bresenham_1(t_fdf fdf, t_pos pos, t_put put)
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
			mlx_pixel_put(fdf.mlx, fdf.win1, put.x0, put.y0--, 0x00FFFF00);
	while (put.x0 <= put.x1)
	{
		mlx_pixel_put(fdf.mlx, fdf.win1, put.x0++, put.y0, 0x00FFFF00);
		if (e >= 0)
		{
			put.y0 += 1;
			e += inc_se;
		}
		else
			e += inc_e;
	}
}

void		bresenham(t_fdf fdf, t_pos pos, t_put put)
{
	int		dx;
	int		dy;
	int		inc_x;
	int		inc_y;

	dx = put.x1 - put.x0;
	dy = put.y1 - put.y0;
	if (dx <= 0 && dy <= 0)
	{
		ft_putendl_color("passe dans 3", "green");
		algo_bresenham_3(fdf, pos, put);
		return ;
	}
	else if (dx >= 0 && dy <= 0)
	{
		ft_putendl_color("passe dans 2", "green");
		algo_bresenham_2(fdf, pos, put);
	}
	else if (dx <= 0 && dy >= 0)
	{
		ft_putendl_color("passe dans 4", "green");
		algo_bresenham_4(fdf, pos, put);
	}
	else if (dx >= 0 && dy >= 0)
	{
		ft_putendl_color("passe dans 1", "green");
		algo_bresenham_1(fdf, pos, put);
		return ;
	}
}
