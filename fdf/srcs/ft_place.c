/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 19:02:04 by pmiceli           #+#    #+#             */
/*   Updated: 2017/12/22 23:43:29 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

//
//
//
//FAIRE DU CLIPING de la taille de la fenetre !!/
//
//
//

static void	ft_link_point(t_fdf fdf, t_pos pos)
{
	t_put	put;
	int		i;
	int		j;
	int		color;

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
				color = pos.elev[i] == 1 && pos.elev[i + 1] == 1 ? pos.high_color : pos.low_color;
				if (pos.elev [i] != 1 && pos.elev[i + 1] == 1)
					bresenham_line(fdf, put, color, 1);
				else if (pos.elev[i] == 1 && pos.elev[i + 1] != 1)
					bresenham_line(fdf, put, color, 2);
				else
					bresenham_line(fdf, put, color, 0);
			}
			if (j != pos.y - 1)
			{
				put.x1 = pos.placex[i + pos.x];
				put.y1 = pos.placey[i + pos.x];
				color = pos.elev[i] == 1 && pos.elev[i + pos.x] == 1 ? pos.high_color : pos.low_color;
				if (pos.elev [i] != 1 && pos.elev[i + pos.x] == 1)
					bresenham_line(fdf, put, color, 1);
				else if  (pos.elev[i] == 1 && pos.elev[i + pos.x] != 1)
					bresenham_line(fdf, put, color, 2);
				else
					bresenham_line(fdf, put, color, 0);
			}
			i++;
		}
		j++;
	}
}

static void	ft_place_point(t_fdf *fdf, t_pos *pos, t_key key)
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
	if (!(pos->elev = (int*)malloc(sizeof(int) * (pos->x * (pos->y - 1)))))
		exit(1);
	while (y < pos->y - 1)
	{
		x = 0;
		while (x < pos->x)
		{
			pos->placex[i] = (x * fdf->key.zoom) + (X_WIN_1 / (fdf->key.zoom / 10) + key.a) - ((pos->z[y][x] * key.elev) * key.x_deriv);
			pos->placey[i] = (y * fdf->key.zoom) + (Y_WIN_1 / (fdf->key.zoom / 10) + key.w) - ((pos->z[y][x] * key.elev) * key.y_deriv);
			pos->elev[i] = pos->z[y][x] != 0 ? 1 : 0;
			i++;
			x++;
		}
		y++;
	}
	ft_link_point(*fdf, *pos);
}

void	ft_place(t_fdf fdf, t_pos pos, t_key key)
{
	clock_t time;
	static clock_t start;
	static unsigned int fps;
	static unsigned int tmp = 0;

	key.x_deriv = 0;
	key.y_deriv = 1;

	time = clock();
	ft_place_point(&fdf, &pos, key);
	mlx_put_image_to_window(fdf.mlx, fdf.win1, fdf.img, 0, 0);
	if (key.hud == 1)
	{
		ft_feature_print(fdf);

		fps++;
		time = clock() - time;
		start += time;
		if (((float)start/CLOCKS_PER_SEC) >= 0.25)
		{
			mlx_string_put(fdf.mlx, fdf.win1, X_WIN_1 -40, 25, 0x00c1c1c1, ft_itoa(fps * 4));
			tmp = fps * 4;
			fps = 0;
			start = 0;
		}
		else
			mlx_string_put(fdf.mlx, fdf.win1, X_WIN_1 -40, 25, 0x00c1c1c1, ft_itoa(tmp));
	}
}
