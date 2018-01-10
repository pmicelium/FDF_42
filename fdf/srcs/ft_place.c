/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 17:29:13 by pmiceli           #+#    #+#             */
/*   Updated: 2018/01/08 19:15:41 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	ft_place_calcul(t_fdf *fdf, int x, int y, int i)
{
	int tmp_px;
	int tmp_py;
	int tmp_pz;

	tmp_px = x * fdf->key.zoom;
	tmp_py = y * fdf->key.zoom;
	tmp_pz = fdf->pos.z[y][x] * fdf->key.elev;
	fdf->pos.placex[i] = tmp_px * cos(-fdf->key.rot_z * M_PI / 180)
		- tmp_py * sin(-fdf->key.rot_z * M_PI / 180);
	fdf->pos.placey[i] = tmp_py * cos(-fdf->key.rot_z * M_PI / 180)
		+ tmp_px * sin(-fdf->key.rot_z * M_PI / 180);
	tmp_px = fdf->pos.placex[i];
	tmp_py = fdf->pos.placey[i];
	fdf->pos.placey[i] = tmp_py * cos(fdf->key.rot_x * M_PI / 180)
		- tmp_pz * sin(fdf->key.rot_x * M_PI / 180);
	fdf->pos.placez[i] = tmp_py * sin(fdf->key.rot_x * M_PI / 180)
		+ tmp_pz * cos(fdf->key.rot_x * M_PI / 180);
	tmp_py = fdf->pos.placey[i];
	tmp_pz = fdf->pos.placez[i];
	fdf->pos.placex[i] = tmp_px * cos(fdf->key.rot_y * M_PI / 180)
		+ tmp_pz * sin(fdf->key.rot_y * M_PI / 180);
	fdf->pos.placex[i] += (((X_WIN_1 / 2) - (fdf->pos.x * fdf->key.zoom / 2))
			+ fdf->key.zoom / 10) + fdf->key.a;
	fdf->pos.placey[i] += (((Y_WIN_1 / 2) - (fdf->pos.y * fdf->key.zoom / 2))
			+ fdf->key.zoom / 10) + fdf->key.w;
}

static void	ft_place_malloc(t_fdf *fdf)
{
	if (!(fdf->pos.placex = (int*)malloc(sizeof(int) * (fdf->pos.x *
						(fdf->pos.y - 1)))))
		exit(1);
	if (!(fdf->pos.placey = (int*)malloc(sizeof(int) * (fdf->pos.x *
						(fdf->pos.y - 1)))))
		exit(1);
	if (!(fdf->pos.placez = (int*)malloc(sizeof(int) * (fdf->pos.x *
						(fdf->pos.y - 1)))))
		exit(1);
	if (!(fdf->pos.elev = (int*)malloc(sizeof(int) * (fdf->pos.x *
						(fdf->pos.y - 1)))))
		exit(1);
}

static void	ft_place_point(t_fdf *fdf)
{
	int x;
	int y;
	int i;

	i = 0;
	y = 0;
	ft_place_malloc(fdf);
	while (y < fdf->pos.y - 1)
	{
		x = 0;
		while (x < fdf->pos.x)
		{
			ft_place_calcul(fdf, x, y, i);
			fdf->pos.elev[i] = fdf->pos.z[y][x];
			i++;
			x++;
		}
		y++;
	}
	ft_link_point(*fdf);
}

void		ft_place(t_fdf fdf, t_key key)
{
	ft_place_point(&fdf);
}
