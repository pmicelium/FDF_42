/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 19:04:23 by pmiceli           #+#    #+#             */
/*   Updated: 2017/12/25 20:31:50 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// ajouter le multpile fd //

void	key_fonct_set(t_fdf *fdf)
{
	fdf->key.elev = 2;
	fdf->key.zoom = 30;
	fdf->key.w = 0;
	fdf->key.a = 0;
	fdf->key.face = 1;
	fdf->pos.low_color = 0x00FFFFFF;
	fdf->pos.high_color = 0x00FF0000;
	fdf->degrad.h_r = (fdf->pos.high_color >> 16) & 0xFF;
	fdf->degrad.h_g = (fdf->pos.high_color >> 8) & 0xFF;
	fdf->degrad.h_b = (fdf->pos.high_color) & 0xFF;
	fdf->degrad.l_r = (fdf->pos.low_color >> 16) & 0xFF;
	fdf->degrad.l_g = (fdf->pos.low_color >> 8) & 0xFF;
	fdf->degrad.l_b = (fdf->pos.low_color) & 0xFF;
	fdf->key.hud = 1;
	fdf->key.rot_x = 0;
	fdf->key.rot_y = 0;
	fdf->key.rot_z = 0;
}

int		main(int argc, char *argv[])
{
	t_fdf	fdf;
	int i;
	char **line;

	i = 1;
	if (ft_strcmp(argv[i], "-bonus.fr") == 0)
	{
		ft_display_bonus_fr();
		i++;
		if (i == argc)
			exit(1);
	}
	if (ft_strcmp(argv[i], "-bonus.en") == 0)
	{
		ft_display_bonus_en();
		i++;
		if (i == argc)
			exit(1);
	}
	fdf.pos = ft_set_pos(argv[i], fdf.pos);
	fdf.mlx = mlx_init();
	fdf.win1 = mlx_new_window(fdf.mlx, X_WIN_1 , Y_WIN_1, argv[1]);
	fdf.img = mlx_new_image(fdf.mlx, X_WIN_1, Y_WIN_1);
	fdf.img_data = (int*)mlx_get_data_addr(fdf.img, &fdf.bpp, &fdf.lsize, &fdf.endian);

	key_fonct_set(&fdf);

	ft_place(fdf, fdf.pos, fdf.key);

	mlx_key_hook(fdf.win1, key_fonct, &fdf);
	mlx_mouse_hook(fdf.win1, mouse_fonct, &fdf);
	mlx_loop_hook(fdf.mlx, loop_hook, &fdf);
	mlx_loop(fdf.mlx);
	return (0);
}
