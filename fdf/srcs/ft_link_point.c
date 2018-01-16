/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_link_point.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 22:25:54 by pmiceli           #+#    #+#             */
/*   Updated: 2018/01/16 01:46:36 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	ft_set_color(t_fdf fdf, int i)
{
	int		color;
	int		r;
	int		g;
	int		b;

	if (fdf.pos.elev[i] == 0)
		return (fdf.pos.low_color);
	r = (fdf.degrad.h_r - fdf.degrad.l_r) * ((float)fdf.pos.elev[i] /
			(float)(fdf.pos.high_nb - fdf.pos.low_nb)) + fdf.degrad.l_r;
	g = (fdf.degrad.h_g - fdf.degrad.l_g) * ((float)fdf.pos.elev[i] /
			(float)(fdf.pos.high_nb - fdf.pos.low_nb)) + fdf.degrad.l_g;
	b = (fdf.degrad.h_b - fdf.degrad.l_b) * ((float)fdf.pos.elev[i] /
			(float)(fdf.pos.high_nb - fdf.pos.low_nb)) + fdf.degrad.l_b;
	color = (r & 0xFF) << 16 | (g & 0xFF) << 8 | (b & 0xFF);
	return (color);
}

static void	ft_place_pre_bresenham_i(t_fdf fdf, t_put *put, int i, int j)
{
	if (i + 1 != fdf.pos.x * j)
	{
		put->x1 = fdf.pos.placex[i + 1];
		put->y1 = fdf.pos.placey[i + 1];
		put->color = ft_set_color(fdf, i);
		if (fdf.pos.elev[i] != 0 && fdf.pos.elev[i + 1] == 0)
			bresenham_line(fdf, *put, put->color, 2);
		else if (fdf.pos.elev[i] == 0 && fdf.pos.elev[i + 1] == fdf.pos.high_nb)
			bresenham_line(fdf, *put, put->color, 1);
		else
			bresenham_line(fdf, *put, put->color, 0);
	}
}

static void	ft_place_pre_bresenham_j(t_fdf fdf, t_put *put, int i, int j)
{
	if (j != fdf.pos.y - 1)
	{
		put->x1 = fdf.pos.placex[i + fdf.pos.x];
		put->y1 = fdf.pos.placey[i + fdf.pos.x];
		put->color = ft_set_color(fdf, i);
		if (fdf.pos.elev[i] != 0 && fdf.pos.elev[i + fdf.pos.x] == 0)
			bresenham_line(fdf, *put, put->color, 2);
		else if (fdf.pos.elev[i] == 0
				&& fdf.pos.elev[i + fdf.pos.x] == fdf.pos.high_nb)
			bresenham_line(fdf, *put, put->color, 1);
		else
			bresenham_line(fdf, *put, put->color, 0);
	}
}

void		ft_link_point(t_fdf fdf)
{
	t_put	put;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (j < fdf.pos.y)
	{
		while (i < fdf.pos.x * j)
		{
			put.x0 = fdf.pos.placex[i];
			put.y0 = fdf.pos.placey[i];
			ft_place_pre_bresenham_i(fdf, &put, i, j);
			ft_place_pre_bresenham_j(fdf, &put, i, j);
			i++;
		}
		j++;
	}
	free(fdf.pos.placex);
	free(fdf.pos.placey);
	free(fdf.pos.placez);
	free(fdf.pos.elev);
}
