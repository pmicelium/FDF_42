/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_link_point.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 22:25:54 by pmiceli           #+#    #+#             */
/*   Updated: 2018/01/16 05:43:15 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	ft_place_pre_bresenham_i(t_fdf fdf, t_put *put, int i, int j)
{
	if (i + 1 != fdf.pos.x * j)
	{
		put->x1 = fdf.pos.placex[i + 1];
		put->y1 = fdf.pos.placey[i + 1];
		put->color = fdf.pos.color[i];
		put->color1 = fdf.pos.color[i + 1];
	//	if (fdf.pos.elev[i] != 0 && fdf.pos.elev[i + 1] == 0)
	//		bresenham_line(fdf, *put, put->color, 2);
	//	else if (fdf.pos.elev[i] == 0 && fdf.pos.elev[i + 1] == fdf.pos.high_nb)
	//		bresenham_line(fdf, *put, put->color, 1);
	//	else
			bresenham_line(fdf, *put, put->color, 0);
	}
}

static void	ft_place_pre_bresenham_j(t_fdf fdf, t_put *put, int i, int j)
{
	if (j != fdf.pos.y - 1)
	{
		put->x1 = fdf.pos.placex[i + fdf.pos.x];
		put->y1 = fdf.pos.placey[i + fdf.pos.x];
		put->color = fdf.pos.color[i];
		put->color1 = fdf.pos.color[i + fdf.pos.x];
//		if (fdf.pos.elev[i] != 0 && fdf.pos.elev[i + fdf.pos.x] == 0)
//			bresenham_line(fdf, *put, put->color, 2);
//		else if (fdf.pos.elev[i] == 0
//				&& fdf.pos.elev[i + fdf.pos.x] == fdf.pos.high_nb)
//			bresenham_line(fdf, *put, put->color, 1);
//		else
			bresenham_line(fdf, *put, put->color, 0);
	}
}

void		ft_link_point(t_fdf fdf)
{
	t_put	put;
	int		i;
	int		y;
	int		x;

	i = 0;
	y = 0;
	while (y < fdf.pos.y)
	{
		x = 0;
		while (i < fdf.pos.x * y)
		{
			put.x0 = fdf.pos.placex[i];
			put.y0 = fdf.pos.placey[i];
			ft_place_pre_bresenham_i(fdf, &put, i, y);
			ft_place_pre_bresenham_j(fdf, &put, i, y);
			i++;
			x++;
		}
		y++;
	}
	free(fdf.pos.placex);
	free(fdf.pos.placey);
	free(fdf.pos.placez);
	free(fdf.pos.elev);
}
