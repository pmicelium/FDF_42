/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 22:26:04 by pmiceli           #+#    #+#             */
/*   Updated: 2017/12/09 18:49:37 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		main(int argc, char *argv[])
{
	t_fdf	fdf;
	t_pos	pos;
	t_put	put;
	t_cam	cam;
	int		x = 0;
	int		y = 0;
	int		lsize;
	int		endian;
	int		bpp;

	cam.x = 900;
	cam.y = 500;
	cam.z = 900;
	pos = ft_set_pos(argv[1], pos, put);

	fdf.mlx = mlx_init();
	fdf.win1 = mlx_new_window(fdf.mlx, X_WIN_1 , Y_WIN_1 ,argv[1]);

//	put = ft_set_put(pos, put, fdf);

	fdf.img = mlx_new_image(fdf.mlx, X_WIN_1, Y_WIN_1);
	fdf.img_data = (int*)mlx_get_data_addr(fdf.img, &bpp, &lsize, &endian);


	mlx_put_image_to_window(fdf.mlx, fdf.win1, fdf.img, 0, 0);
	mlx_key_hook(fdf.win1, key_fonct, 0);
	mlx_loop(fdf.mlx);
	return (0);
}
