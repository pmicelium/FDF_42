/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 22:26:04 by pmiceli           #+#    #+#             */
/*   Updated: 2017/12/07 15:14:33 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		main(int argc, char *argv[])
{
	t_fdf	fdf;
	t_pos	pos;
	t_put	put;
	int		x = 0;
	int		y = 0;

	pos = ft_set_pos(argv[1], pos, put);
	fdf.mlx = mlx_init();
	fdf.win1 = mlx_new_window(fdf.mlx, 1800 , 1000, argv[1]);
//	put = ft_set_put(pos, put, fdf);
//	put.y0 = (3 * 50) + 50;
//	put.x0 = (3 * 50) + 50;
//	put.y1 = (4 * 50) + 50;
//	put.x1 = (3 * 50) + 50;
//	bresenham_line(fdf, pos, put);
//	test_bresenham_line(fdf, pos, put);
//	test_bresenham_circle(fdf, pos, put);

	mlx_loop(fdf.mlx);
	return (0);
}
