/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 19:04:23 by pmiceli           #+#    #+#             */
/*   Updated: 2018/01/17 05:48:30 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void			key_fonct_set(t_fdf *fdf)
{
	fdf->key.elev = 2;
	fdf->key.zoom = 5;
	fdf->key.w = 0;
	fdf->key.a = 0;
	fdf->pos.degrad.h_r = (fdf->pos.high_color >> 16) & 0xFF;
	fdf->pos.degrad.h_g = (fdf->pos.high_color >> 8) & 0xFF;
	fdf->pos.degrad.h_b = (fdf->pos.high_color) & 0xFF;
	fdf->pos.degrad.l_r = (fdf->pos.low_color >> 16) & 0xFF;
	fdf->pos.degrad.l_g = (fdf->pos.low_color >> 8) & 0xFF;
	fdf->pos.degrad.l_b = (fdf->pos.low_color) & 0xFF;
	fdf->key.hud = 1;
	fdf->repaint = 1;
	fdf->key.rot_x = 0;
	fdf->key.rot_y = 0;
	fdf->key.rot_z = 0;
	fdf->fps.fps = 0;
	fdf->fps.start = 0;
	fdf->color = 1;
}

static int		ft_parameters2(char **argv, int i, t_fdf *fdf)
{
	if (ft_strcmp(argv[i], "-lcolor") == 0)
	{
		i++;
		if (ft_is_base(argv[i], HEXA) == 1)
			fdf->pos.low_color = ft_atoi_base(argv[i], HEXA);
		else
			ft_putendl_color("-lcolor error: wrong number detected", "red");
	}
	if (ft_strcmp(argv[i], "-ucolor") == 0)
	{
		i++;
		if (ft_is_base(argv[i], HEXA) == 1)
			fdf->pos.high_color = ft_atoi_base(argv[i], HEXA);
		else
			ft_putendl_color("-ucolor error: wrong number detected", "red");
	}
	return (i);
}

static int		ft_parameters(int argc, char **argv, int i, t_fdf *fdf)
{
	while (ft_strcmp(argv[i], "-bonus.fr") == 0 ||
			ft_strcmp(argv[i], "-bonus.en") == 0 ||
			ft_strcmp(argv[i], "-lcolor") == 0 ||
			ft_strcmp(argv[i], "-ucolor") == 0 ||
			ft_strcmp(argv[i], "-leaks") == 0)
	{
		if (ft_strcmp(argv[i], "-bonus.fr") == 0)
			ft_display_bonus_fr();
		if (ft_strcmp(argv[i], "-bonus.en") == 0)
			ft_display_bonus_en();
		if (ft_strcmp(argv[i], "-leaks") == 0)
			fdf->leaks = 1;
		if (ft_strcmp(argv[i], "-lcolor") == 0 ||
				ft_strcmp(argv[i], "-ucolor") == 0)
			i = ft_parameters2(argv, i, fdf);
		i++;
		if (i == argc)
			return (0);
	}
	return (i);
}

int				main(int argc, char *argv[])
{
	t_fdf	fdf;
	int		i;

	if (argc == 1)
		ft_print_usage();
	i = 1;
	fdf.leaks = 0;
	fdf.pos.low_color = 0x00FFFFFF;
	fdf.pos.high_color = 0x80FF0000;
	i = ft_parameters(argc, argv, i, &fdf);
	if (i == 0)
		return (0);
	key_fonct_set(&fdf);
	fdf.pos = ft_set_pos(argv[i], fdf.pos);
	fdf.mlx = mlx_init();
	fdf.win1 = mlx_new_window(fdf.mlx, X_WIN_1, Y_WIN_1, argv[i]);
	fdf.img = mlx_new_image(fdf.mlx, X_WIN_1, Y_WIN_1);
	fdf.img_data = (int*)mlx_get_data_addr(fdf.img, &fdf.bpp, &fdf.lsize,
			&fdf.endian);
	ft_place(fdf);
	mlx_hook(fdf.win1, 4, (1l << 8), &mouse_fonct, &fdf);
	mlx_hook(fdf.win1, 2, (1l << 8), &key_fonct, &fdf);
	mlx_loop_hook(fdf.mlx, loop_hook, &fdf);
	mlx_loop(fdf.mlx);
	return (0);
}
