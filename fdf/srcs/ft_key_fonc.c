/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_fonc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 15:48:06 by pmiceli           #+#    #+#             */
/*   Updated: 2017/12/19 21:13:18 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	key_fonct_elev(int keycode, t_fdf *fdf)
{
	if (keycode == 78 || keycode == 27)
		fdf->key.elev--;
	else
		fdf->key.elev++;
	fdf->img = mlx_new_image(fdf->mlx, X_WIN_1, Y_WIN_1);
	fdf->img_data = (int*)mlx_get_data_addr(fdf->img, &fdf->bpp, &fdf->lsize, &fdf->endian);
	ft_place(*fdf, fdf->pos, fdf->key);
}

void	key_fonct_zoom(int keycode, t_fdf *fdf)
{
	if (keycode == 25 || keycode == 92)
		fdf->key.zoom -= 5;
	else
		fdf->key.zoom += 5;
	fdf->img = mlx_new_image(fdf->mlx, X_WIN_1, Y_WIN_1);
	fdf->img_data = (int*)mlx_get_data_addr(fdf->img, &fdf->bpp, &fdf->lsize, &fdf->endian);
	ft_place(*fdf, fdf->pos, fdf->key);
}

int		key_fonct(int keycode, t_fdf *fdf)
{
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
	return (0);
}

int		loop_hook(t_fdf *fdf)
{
	ft_place(*fdf, fdf->pos, fdf->key);
	return (0);
}
