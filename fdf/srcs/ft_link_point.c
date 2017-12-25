/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_link_point.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 22:25:54 by pmiceli           #+#    #+#             */
/*   Updated: 2017/12/25 22:32:40 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	ft_place_pre_bresenham_i(t_fdf fdf, t_put *put, int i, int j)
{
	if (i + 1 != fdf.pos.x * j)
	{
		put->x1 = fdf.pos.placex[i + 1];
		put->y1 = fdf.pos.placey[i + 1];
		put->color = fdf.pos.elev[i] == 1 && fdf.pos.elev[i + 1] == 1 ?
			fdf.pos.high_color : fdf.pos.low_color;
		if (fdf.pos.elev[i] != 1 && fdf.pos.elev[i + 1] == 1)
			bresenham_line(fdf, *put, put->color, 1);
		else if (fdf.pos.elev[i] == 1 && fdf.pos.elev[i + 1] != 1)
			bresenham_line(fdf, *put, put->color, 2);
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
		put->color = fdf.pos.elev[i] == 1 && fdf.pos.elev[i + fdf.pos.x] == 1 ?
			fdf.pos.high_color : fdf.pos.low_color;
		if (fdf.pos.elev[i] != 1 && fdf.pos.elev[i + fdf.pos.x] == 1)
			bresenham_line(fdf, *put, put->color, 1);
		else if (fdf.pos.elev[i] == 1 && fdf.pos.elev[i + fdf.pos.x] != 1)
			bresenham_line(fdf, *put, put->color, 2);
		else
			bresenham_line(fdf, *put, put->color, 0);
	}
}

void		ft_link_point(t_fdf fdf, t_pos pos)
{
	t_put	put;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (j < pos.y)
	{
		while (i < pos.x * j)
		{
			put.x0 = pos.placex[i];
			put.y0 = pos.placey[i];
			ft_place_pre_bresenham_i(fdf, &put, i, j);
			ft_place_pre_bresenham_j(fdf, &put, i, j);
			i++;
		}
		j++;
	}
}
