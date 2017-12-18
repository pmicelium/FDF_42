/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 19:04:23 by pmiceli           #+#    #+#             */
/*   Updated: 2017/12/18 19:04:41 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		main(int argc, char *argv[])
{
	t_fdf	fdf;
	t_key	key;
	t_pos	pos;
	t_put	put;
	int		x = 0;
	int		y = 0;
	int		lsize;
	int		endian;
	int		bpp;
	int		tmp;

	pos = ft_set_pos(argv[1], pos, put);

	fdf.mlx = mlx_init();
	fdf.win1 = mlx_new_window(fdf.mlx, X_WIN_1 , Y_WIN_1, argv[1]);

	fdf.img = mlx_new_image(fdf.mlx, X_WIN_1, Y_WIN_1);
	fdf.img_data = (int*)mlx_get_data_addr(fdf.img, &bpp, &lsize, &endian);
	key.elev = 0;
	ft_place(fdf, pos, key);

	mlx_put_image_to_window(fdf.mlx, fdf.win1, fdf.img, 0, 0);
	tmp = mlx_key_hook(fdf.win1, key_fonct, &key);
	mlx_loop(fdf.mlx);
	return (0);
}
