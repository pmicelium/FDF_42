/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 19:04:23 by pmiceli           #+#    #+#             */
/*   Updated: 2018/01/08 20:48:45 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void			key_fonct_set(t_fdf *fdf)
{
	fdf->key.elev = 2;
	fdf->key.zoom = 5;
	fdf->key.w = 0;
	fdf->key.a = 0;
	fdf->degrad.h_r = (fdf->pos.high_color >> 16) & 0xFF;
	fdf->degrad.h_g = (fdf->pos.high_color >> 8) & 0xFF;
	fdf->degrad.h_b = (fdf->pos.high_color) & 0xFF;
	fdf->degrad.l_r = (fdf->pos.low_color >> 16) & 0xFF;
	fdf->degrad.l_g = (fdf->pos.low_color >> 8) & 0xFF;
	fdf->degrad.l_b = (fdf->pos.low_color) & 0xFF;
	fdf->key.hud = 1;
	fdf->repaint = 1;
	fdf->key.rot_x = 0;
	fdf->key.rot_y = 0;
	fdf->key.rot_z = 0;
	fdf->fps.fps = 0;
	fdf->fps.start = 0;
}

static int		show_bonus(int argc, char **argv, int i)
{
	if (ft_strcmp(argv[i], "-bonus.fr") == 0)
	{
		ft_display_bonus_fr();
		i++;
		if (i == argc)
			return (0);
	}
	if (ft_strcmp(argv[i], "-bonus.en") == 0)
	{
		i++;
		ft_display_bonus_en();
		if (i == argc)
			return (0);
	}
	return (i);
}

int				main(int argc, char *argv[])
{
	t_fdf	fdf;
	int		i;

	i = 1;
	i = show_bonus(argc, argv, i);
	if (i == 0)
		return (0);
	fdf.pos = ft_set_pos(argv[i], fdf.pos);
	fdf.mlx = mlx_init();
	fdf.win1 = mlx_new_window(fdf.mlx, X_WIN_1, Y_WIN_1, argv[i]);
	fdf.img = mlx_new_image(fdf.mlx, X_WIN_1, Y_WIN_1);
	fdf.img_data = (int*)mlx_get_data_addr(fdf.img, &fdf.bpp, &fdf.lsize,
			&fdf.endian);
	fdf.pos.low_color = 0x00FFFFFF;
	fdf.pos.high_color = 0x00FF0000;
	key_fonct_set(&fdf);
	ft_place(fdf);
	mlx_hook(fdf.win1, 4, (1l << 8), &mouse_fonct, &fdf);
	mlx_hook(fdf.win1, 2, (1l << 8), &key_fonct, &fdf);
	mlx_loop_hook(fdf.mlx, loop_hook, &fdf);
	mlx_loop(fdf.mlx);
	return (0);
}
