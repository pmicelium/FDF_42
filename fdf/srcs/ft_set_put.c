/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_put.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 15:25:48 by pmiceli           #+#    #+#             */
/*   Updated: 2017/12/05 18:19:30 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_put		ft_set_put(t_pos pos, t_put put, t_fdf fdf)
{
	int		x;
	int		y;
	int		tmp_y;

	y = 0;
	while (y < pos.y)
	{
		x = 0;
		put.y0 = y * 50 + 50;
		tmp_y = put.y0;
		while (x < pos.x)
		{
			put.x0 = x * 50 + 50;
			mlx_pixel_put(fdf.mlx, fdf.win1, put.x0, put.y0, 0x00FFFFFF);
			x++;
		}
		y++;
	}
	return (put);
}
