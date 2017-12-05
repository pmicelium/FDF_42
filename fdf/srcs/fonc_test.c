/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonc_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 14:34:15 by pmiceli           #+#    #+#             */
/*   Updated: 2017/12/05 14:36:12 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void test_bresenham_circle(t_fdf fdf, t_pos pos, t_put put)
{
	put.x0 = 900;
	put.y0 = 500;
	put.x1 = 900;
	put.y1 = 750;
	bresenham_line(fdf, pos, put);
	put.x1 = 1150;
	put.y1 = 500;
	bresenham_line(fdf, pos, put);

	put.o_x = 900;
	put.o_y = 500;
	put.r = 250;
	bresenham_circle(fdf, pos, put);
}

void test_bresenham_line(t_fdf fdf, t_pos pos, t_put put)
{
	put.x0 = 350;
	put.y0 = 350;
	put.x1 = 550;
	put.y1 = 550;
	bresenham_line(fdf, pos, put);
	put.x1 = 550;
	put.y1 = 150;
	bresenham_line(fdf, pos, put);
	put.x1 = 150;
	put.y1 = 150;
	bresenham_line(fdf, pos, put);
	put.x1 = 150;
	put.y1 = 550;
	bresenham_line(fdf, pos, put);
	put.x1 = 350;
	put.y1 = 550;
	bresenham_line(fdf, pos, put);
	put.x1 = 350;
	put.y1 = 150;
	bresenham_line(fdf, pos, put);
	put.x1 = 150;
	put.y1 = 350;
	bresenham_line(fdf, pos, put);
	put.x1 = 550;
	put.y1 = 350;
	bresenham_line(fdf, pos, put);
	}

