/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_xiaolin_wu_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 04:02:25 by pmiceli           #+#    #+#             */
/*   Updated: 2018/01/19 06:45:08 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/xiaolin_wu.h"

t_degrad		set_degrad(t_put put, t_degrad degrad)
{
	degrad.b_r = (put.color >> 16) & 0xFF;
	degrad.b_g = (put.color >> 8) & 0xFF;
	degrad.b_b = (put.color) & 0xFF;
	degrad.c_r = (put.color1 >> 16) & 0xFF;
	degrad.c_g = (put.color1 >> 8) & 0xFF;
	degrad.c_b = (put.color1) & 0xFF;
	return (degrad);
}

void		print_xiao(int x, int y, float br, t_fdf fdf, int color)
{
	fdf.img_data[y * X_WIN_1 + x] = set_brightness(color, br);
}

static t_wu		set_wu(t_wu wu, t_put put, int i)
{
	if (i == 1)
	{
		wu.gradient = (double)put.dx / (double)put.dy;
		wu.yend = ROUND_(put.y0);
		wu.xend = put.x0 + wu.gradient * (wu.yend - put.y0);
		wu.ygap = RFPART_(put.y0 + 0.5);
		wu.ypx11 = wu.yend;
		wu.xpx11 = IPART_(wu.xend);
	}
	if (i == 2)
	{
		wu.interx = wu.xend + wu.gradient;
		wu.yend = ROUND_(put.y1);
		wu.xend = put.x1 + wu.gradient * (wu.yend - put.y1);
		wu.ygap = FPART_(put.y1 + 0.5);
		wu.ypx12 = wu.yend;
		wu.xpx12 = IPART_(wu.xend);
	}
	return (wu);
}

void			xiaolin_wu_3(t_fdf fdf, t_put put, t_wu wu)
{
	int			y;
	int			i;
	double		steap;

	i = 0;
	steap = sqrt(pow((put.x1 - put.x0), 2) + pow((put.y1 - put.y0), 2));
	wu = set_wu(wu, put, 1);
	if (check_print(wu.xpx11, wu.ypx11 + 1) == 1)
	{
		print_xiao(wu.xpx11, wu.ypx11, RFPART_(wu.yend) * wu.xgap,
				fdf, put.color);
		print_xiao(wu.xpx11, wu.ypx11 + 1, FPART_(wu.yend) * wu.xgap,
				fdf, put.color);
	}
	wu = set_wu(wu, put, 2);
	if (check_print(wu.xpx12, wu.ypx12 + 1) == 1)
	{
		print_xiao(wu.xpx12, wu.ypx12, RFPART_(wu.yend) * wu.xgap,
				fdf, put.color1);
		print_xiao(wu.xpx12, wu.ypx12 + 1, FPART_(wu.yend) * wu.xgap,
				fdf, put.color1);
	}
	y = wu.ypx11;
	while (y <= (wu.ypx12 - 1))
	{
		if (check_print(IPART_(wu.interx + 1), y) == 1)
		{
			print_xiao(IPART_(wu.interx), y, RFPART_(wu.interx), fdf,
					ft_degraded(fdf.pos.degrad, i / steap));
			print_xiao(IPART_(wu.interx) + 1, y, FPART_(wu.interx), fdf,
					ft_degraded(fdf.pos.degrad, i++ /steap));
		}
		wu.interx += wu.gradient;
		y++;
	}
}
