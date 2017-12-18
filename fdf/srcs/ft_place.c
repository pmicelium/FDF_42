/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 19:02:04 by pmiceli           #+#    #+#             */
/*   Updated: 2017/12/18 19:07:04 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
//remouve stdio.h//
//#include <stdio.h>

void	ft_link_point(t_fdf fdf, t_pos pos, t_put put)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (j < pos.y)
	{
		while (i < pos.x * j)
		{
			put.x0 = pos.placex[i];
			put.y0 = pos.placey[i];
			if (i + 1 != pos.x * j)
			{
				put.x1 = pos.placex[i + 1];
				put.y1 = pos.placey[i + 1];
				bresenham_line(fdf, put, 0x80FFFFFF);
			}
			if (j != pos.y - 1)
			{
				put.x1 = pos.placex[i + pos.x];
				put.y1 = pos.placey[i + pos.x];
				bresenham_line(fdf, put, 0x80FFFFFF);
			}
			i++;
		}
		j++;
	}
}

void	ft_place_point(t_fdf *fdf, t_pos *pos, t_key key)
{
	int x;
	int y;
	int place_x;
	int place_y;
	int color;
	int i;

	i = 0;
	y = 0;
	if (!(pos->placex = (int*)malloc(sizeof(int) * (pos->x * (pos->y - 1)))))
		exit(1);
	if (!(pos->placey = (int*)malloc(sizeof(int) * (pos->x * (pos->y - 1)))))
		exit(1);
	while (y < pos->y - 1)
	{
		x = 0;
		while (x < pos->x)
		{
			if (pos->z[y][x] != 0)
				color = 0x00FF0000;
			else
				color = 0x000000FF;
			pos->placex[i] = (x * 50) + X_WIN_1 / 4 + (pos->z[y][x] * key.elev);
			pos->placey[i] = (y * 50) + Y_WIN_1 / 4 - (pos->z[y][x] * key.elev);
			fdf->img_data[pos->placey[i] * X_WIN_1 + pos->placex[i]] = color;
			i++;
			x++;
		}
		y++;
	}
}

void	ft_place(t_fdf fdf, t_pos pos, t_key key)
{
	t_put put;

	key.elev = 2;
	ft_place_point(&fdf, &pos, key);
	ft_link_point(fdf, pos, put);
	ft_place_point(&fdf, &pos, key);
	ft_putendl_color("DONE !!", "green");
}
