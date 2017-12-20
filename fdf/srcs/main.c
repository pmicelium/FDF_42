/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 19:04:23 by pmiceli           #+#    #+#             */
/*   Updated: 2017/12/20 20:17:47 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// ajouter le multpile fd //

int		main(int argc, char *argv[])
{
	t_fdf	fdf;
	int		x = 0;
	int		y = 0;

	fdf.pos = ft_set_pos(argv[1], fdf.pos);
	fdf.mlx = mlx_init();
	fdf.win1 = mlx_new_window(fdf.mlx, X_WIN_1 , Y_WIN_1, argv[1]);
	fdf.img = mlx_new_image(fdf.mlx, X_WIN_1, Y_WIN_1);
	fdf.img_data = (int*)mlx_get_data_addr(fdf.img, &fdf.bpp, &fdf.lsize, &fdf.endian);

	fdf.key.elev = 0;
	fdf.key.zoom = 50;
	fdf.key.w = 0;
	fdf.key.a = 0;

	ft_place(fdf, fdf.pos, fdf.key);

	mlx_key_hook(fdf.win1, key_fonct, &fdf);
//	mlx_hook(fdf.win1, x_event, x_mask, key_fonct_mv_struct, &fdf);
	mlx_loop_hook(fdf.mlx, loop_hook, &fdf);
	mlx_loop(fdf.mlx);
	return (0);
}
