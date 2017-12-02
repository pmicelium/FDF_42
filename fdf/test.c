/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 20:08:48 by pmiceli           #+#    #+#             */
/*   Updated: 2017/12/02 20:23:39 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

int main()
{
	void *mlx;
	void *win;
	int x = 50;
	int y;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 400, 400, "je test le mlx");
	while (x < 350)
	{
		y = 50;
		while (y < 350)
		{
			mlx_pixel_put(mlx, win, x, y, 0x00FFFFFF);
			y++;
		}
		x++;
	}
	x = 100;
		while (x < 300)
	{
		y = 100;
		while (y < 300)
		{
			mlx_pixel_put(mlx, win, x, y, 0x000000FF);
			y++;
		}
		x++;
	}
	mlx_loop(mlx);
	return (0);
}
