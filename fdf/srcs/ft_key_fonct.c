/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_fonc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 15:48:06 by pmiceli           #+#    #+#             */
/*   Updated: 2017/12/22 23:41:54 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

//
//
//
//faire mappage activer le hud //
//
//
//



static void	key_fonct_mv_struct(int keycode, t_fdf *fdf)
{
	if (keycode == 13)
		fdf->key.w -= 5;
	if (keycode == 1)
		fdf->key.w += 5;
	if (keycode == 0)
		fdf->key.a -= 5;
	if (keycode == 2)
		fdf->key.a += 5;
	fdf->img = mlx_new_image(fdf->mlx, X_WIN_1, Y_WIN_1);
	fdf->img_data = (int*)mlx_get_data_addr(fdf->img, &fdf->bpp, &fdf->lsize, &fdf->endian);
	ft_place(*fdf, fdf->pos, fdf->key);
}

static void	key_fonct_elev(int keycode, t_fdf *fdf)
{
	if (keycode == 78 || keycode == 27)
		fdf->key.elev--;
	else
		fdf->key.elev++;
	fdf->img = mlx_new_image(fdf->mlx, X_WIN_1, Y_WIN_1);
	fdf->img_data = (int*)mlx_get_data_addr(fdf->img, &fdf->bpp, &fdf->lsize, &fdf->endian);
	ft_place(*fdf, fdf->pos, fdf->key);
}

static void	key_fonct_zoom(int keycode, t_fdf *fdf)
{
	if (keycode == 25 || keycode == 92)
		fdf->key.zoom -= 5;
	else
		fdf->key.zoom += 5;
	fdf->img = mlx_new_image(fdf->mlx, X_WIN_1, Y_WIN_1);
	fdf->img_data = (int*)mlx_get_data_addr(fdf->img, &fdf->bpp, &fdf->lsize, &fdf->endian);
	ft_place(*fdf, fdf->pos, fdf->key);
}

static void	key_fonct_reset(t_fdf *fdf)
{
	key_fonct_set(fdf);
	fdf->img = mlx_new_image(fdf->mlx, X_WIN_1, Y_WIN_1);
	fdf->img_data = (int*)mlx_get_data_addr(fdf->img, &fdf->bpp, &fdf->lsize, &fdf->endian);
	ft_place(*fdf, fdf->pos, fdf->key);
}

int			key_fonct(int keycode, t_fdf *fdf)
{
	ft_putstr_color("keycode : ", "yellow");
	ft_putnbr_endl(keycode);
	if (keycode == 53)
	{
		ft_putendl_color("Exiting...", "green");
		exit(1);
	}
	if ((keycode == 69 || keycode == 24) || (keycode == 78 || keycode == 27))
		key_fonct_elev(keycode, fdf);
	if ((keycode == 25 || keycode == 29) || (keycode == 92 || keycode == 82))
		key_fonct_zoom(keycode, fdf);
	if (keycode == 13 || keycode == 0 || keycode == 1 || keycode == 2)
		key_fonct_mv_struct(keycode, fdf);
	if (keycode == 49)
		key_fonct_reset(fdf);
//	if (keycode == 8)
//		fdf->key.face *= -1;
	if (keycode == 36)
		fdf->key.hud *= -1;
	return (0);
}

int		loop_hook(t_fdf *fdf)
{
	ft_place(*fdf, fdf->pos, fdf->key);
	return (0);
}
