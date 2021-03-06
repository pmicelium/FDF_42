/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_fonct_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 21:23:08 by pmiceli           #+#    #+#             */
/*   Updated: 2018/01/18 23:50:08 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	key_fonct_2(int keycode, t_fdf *fdf)
{
	if (keycode == 12)
		fdf->key.anti_aliasing = fdf->key.anti_aliasing == 1 ? 0 : 1;
	if (keycode == 36)
		fdf->key.hud *= -1;
}

void	key_fonct_mv_struct(int keycode, t_fdf *fdf)
{
	if (keycode == 126)
		fdf->key.w -= 3;
	if (keycode == 125)
		fdf->key.w += 3;
	if (keycode == 123)
		fdf->key.a -= 3;
	if (keycode == 124)
		fdf->key.a += 3;
}

void	key_fonct_elev(int keycode, t_fdf *fdf)
{
	if (keycode == 78 || keycode == 27)
		fdf->key.elev--;
	else
		fdf->key.elev++;
}

void	key_fonct_zoom(int keycode, t_fdf *fdf)
{
	if (keycode == 25 || keycode == 92)
		fdf->key.zoom--;
	else
		fdf->key.zoom++;
}

void	key_fonct_reset(t_fdf *fdf)
{
	key_fonct_set(fdf);
}
