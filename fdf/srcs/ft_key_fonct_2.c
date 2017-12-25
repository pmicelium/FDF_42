/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_fonct_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 21:23:08 by pmiceli           #+#    #+#             */
/*   Updated: 2017/12/25 22:31:57 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	key_fonct_mv_struct(int keycode, t_fdf *fdf)
{
	if (keycode == 126)
		fdf->key.w -= 5;
	if (keycode == 125)
		fdf->key.w += 5;
	if (keycode == 123)
		fdf->key.a -= 5;
	if (keycode == 124)
		fdf->key.a += 5;
	fdf->img = mlx_new_image(fdf->mlx, X_WIN_1, Y_WIN_1);
	fdf->img_data = (int*)mlx_get_data_addr(fdf->img, &fdf->bpp, &fdf->lsize,
			&fdf->endian);
	ft_place(*fdf, fdf->pos, fdf->key);
}

void	key_fonct_elev(int keycode, t_fdf *fdf)
{
	if (keycode == 78 || keycode == 27)
		fdf->key.elev--;
	else
		fdf->key.elev++;
	fdf->img = mlx_new_image(fdf->mlx, X_WIN_1, Y_WIN_1);
	fdf->img_data = (int*)mlx_get_data_addr(fdf->img, &fdf->bpp, &fdf->lsize,
			&fdf->endian);
	ft_place(*fdf, fdf->pos, fdf->key);
}

void	key_fonct_zoom(int keycode, t_fdf *fdf)
{
	if (keycode == 25 || keycode == 92)
		fdf->key.zoom -= 5;
	else
		fdf->key.zoom += 5;
	fdf->img = mlx_new_image(fdf->mlx, X_WIN_1, Y_WIN_1);
	fdf->img_data = (int*)mlx_get_data_addr(fdf->img, &fdf->bpp, &fdf->lsize,
			&fdf->endian);
	ft_place(*fdf, fdf->pos, fdf->key);
}

void	key_fonct_reset(t_fdf *fdf)
{
	key_fonct_set(fdf);
	fdf->img = mlx_new_image(fdf->mlx, X_WIN_1, Y_WIN_1);
	fdf->img_data = (int*)mlx_get_data_addr(fdf->img, &fdf->bpp, &fdf->lsize,
			&fdf->endian);
	ft_place(*fdf, fdf->pos, fdf->key);
}
