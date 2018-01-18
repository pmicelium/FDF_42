/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 17:29:13 by pmiceli           #+#    #+#             */
/*   Updated: 2018/01/18 21:52:46 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	ft_place_calcul(t_fdf *fdf, int x, int y, int i)
{
	int		tmp_px;
	int		tmp_py;
	int		tmp_pz;
	double	pi;

	pi = M_PI / 180;
	tmp_pz = fdf->pos.point[y][x].z * ((fdf->key.elev) * (fdf->key.zoom)) / 10;
	fdf->pos.placex[i] = X_CEN + ((x * fdf->key.zoom) - X_CEN) *
		cos(-fdf->key.rot_z * pi) - ((y * fdf->key.zoom) - Y_CEN) *
		sin(-fdf->key.rot_z * pi);
	fdf->pos.placey[i] = Y_CEN + ((y * fdf->key.zoom) - Y_CEN) *
		cos(-fdf->key.rot_z * pi) + ((x * fdf->key.zoom) - X_CEN) *
		sin(-fdf->key.rot_z * pi);
	tmp_px = fdf->pos.placex[i];
	tmp_py = fdf->pos.placey[i];
	fdf->pos.placey[i] = Y_CEN + (tmp_py - Y_CEN) *
		cos(fdf->key.rot_x * pi) - (tmp_pz - Z_CEN) * sin(fdf->key.rot_x * pi);
	fdf->pos.placez[i] = Z_CEN + (tmp_py - Y_CEN) *
		sin(fdf->key.rot_x * pi) + (tmp_pz - Z_CEN) * cos(fdf->key.rot_x * pi);
	tmp_py = fdf->pos.placey[i];
	tmp_pz = fdf->pos.placez[i];
	fdf->pos.placex[i] = (X_CEN) + (tmp_px - X_CEN) * cos(fdf->key.rot_y * pi)
		- (tmp_pz - Z_CEN) * sin(fdf->key.rot_y * pi);
	fdf->pos.placez[i] = (Z_CEN) + (tmp_px - X_CEN) * cos(fdf->key.rot_y * pi)
		+ (tmp_pz - Z_CEN) * sin(fdf->key.rot_y * pi);
}

static void	ft_place_malloc(t_fdf *fdf)
{
	if (!(fdf->pos.placex = (int*)malloc(sizeof(int) * (fdf->pos.x *
						(fdf->pos.y)))))
		exit(1);
	if (!(fdf->pos.placey = (int*)malloc(sizeof(int) * (fdf->pos.x *
						(fdf->pos.y)))))
		exit(1);
	if (!(fdf->pos.placez = (int*)malloc(sizeof(int) * (fdf->pos.x *
						(fdf->pos.y)))))
		exit(1);
	if (!(fdf->pos.elev = (int*)malloc(sizeof(int) * (fdf->pos.x *
						(fdf->pos.y)))))
		exit(1);
	if (!(fdf->pos.color = (int*)malloc(sizeof(int) * (fdf->pos.x *
						(fdf->pos.y)))))
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
	while (y < fdf->pos.y)
	{
		x = 0;
		while (x < fdf->pos.x)
		{
			ft_place_calcul(fdf, x, y, i);
			fdf->pos.placex[i] += (((X_WIN_1 / 2) - X_CEN) + fdf->key.zoom
					/ 10) + fdf->key.a * 2;
			fdf->pos.placey[i] += (((Y_WIN_1 / 2) - Y_CEN) + fdf->key.zoom
					/ 10) + fdf->key.w * 2;
			fdf->pos.elev[i] = fdf->pos.point[y][x].z;
			fdf->pos.color[i] = fdf->pos.point[y][x].color;
			i++;
			x++;
		}
		y++;
	}
	ft_link_point(*fdf);
}

void		ft_place(t_fdf fdf)
{
	ft_place_point(&fdf);
}
