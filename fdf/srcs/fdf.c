/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 22:26:04 by pmiceli           #+#    #+#             */
/*   Updated: 2017/12/04 23:18:26 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		main(int argc, char *argv[])
{
	t_fdf	fdf;
	t_pos	pos;
	t_put	put;
	double		x;
	double		y;
	double		rad;

	rad = M_PI / 180;
	pos = ft_set_tab(argv[1], pos);
//	x = (cos(30 * rad) * (pos.x * 50));
//	y =  2 * (sin(30 * rad) * (pos.y * 50));
	fdf.mlx = mlx_init();
//	printf("%f\n", x);
//	printf("%f\n", y);
	fdf.win1 = mlx_new_window(fdf.mlx, 700 , 700, "test fdf");
	put.x0 = 350;
	put.y0 = 350;
	put.x1 = 550;
	put.y1 = 550;
	ft_putendl("test 1");
	bresenham(fdf, pos, put);
	put.x1 = 550;
	put.y1 = 150;
	ft_putendl("test 2");
	bresenham(fdf, pos, put);
	put.x1 = 150;
	put.y1 = 150;
	ft_putendl("test 3");
	bresenham(fdf, pos, put);
	put.x1 = 150;
	put.y1 = 550;
	ft_putendl("test 4");
	bresenham(fdf, pos, put);
	put.x1 = 350;
	put.y1 = 550;
	ft_putendl("test 5");
	bresenham(fdf, pos, put);
	put.x1 = 350;
	put.y1 = 150;
	ft_putendl("test 6");
	bresenham(fdf, pos, put);
	put.x1 = 150;
	put.y1 = 350;
	ft_putendl("test 7");
	bresenham(fdf, pos, put);
	put.x1 = 550;
	put.y1 = 350;
	ft_putendl("test 8");
	bresenham(fdf, pos, put);

	mlx_loop(fdf.mlx);
	return (0);
}
