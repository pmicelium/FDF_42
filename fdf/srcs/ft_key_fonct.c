/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_fonc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 15:48:06 by pmiceli           #+#    #+#             */
/*   Updated: 2018/01/16 22:41:24 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	key_fonct_rot(int keycode, t_fdf *fdf)
{
	if (keycode == 13)
		fdf->key.rot_x++;
	if (keycode == 1)
		fdf->key.rot_x--;
	if (keycode == 0)
		fdf->key.rot_y--;
	if (keycode == 2)
		fdf->key.rot_y++;
	if (fdf->key.rot_x == 360)
		fdf->key.rot_x = 0;
	if (fdf->key.rot_x == -1)
		fdf->key.rot_x = 359;
	if (fdf->key.rot_y == 360)
		fdf->key.rot_y = 0;
	if (fdf->key.rot_y == -1)
		fdf->key.rot_y = 359;
}

static void	key_fonct_rot_z(int keycode, t_fdf *fdf)
{
	if (keycode == 3)
		fdf->key.rot_z--;
	if (keycode == 15)
		fdf->key.rot_z++;
	if (fdf->key.rot_z == 360)
		fdf->key.rot_z = 0;
	if (fdf->key.rot_z == -1)
		fdf->key.rot_z = 359;
}

static void	ft_free_all(t_fdf *fdf)
{
	int		i;

	i = 0;
	while (fdf->pos.point[i])
	{
		free(fdf->pos.point[i]);
		i++;
	}
	free(fdf->pos.point);
	mlx_clear_window(fdf->mlx, fdf->win1);
	mlx_destroy_image(fdf->mlx, fdf->img);
	mlx_destroy_window(fdf->mlx, fdf->win1);
}

int			key_fonct(int keycode, t_fdf *fdf)
{
	fdf->repaint = 1;
	if (keycode == 53)
	{
		ft_putendl_color("Exiting...", "green");
		ft_free_all(fdf);
		exit(1);
	}
	else if (keycode == 69 || keycode == 24 || keycode == 78 || keycode == 27)
		key_fonct_elev(keycode, fdf);
	else if (keycode == 25 || keycode == 29 || keycode == 92 || keycode == 82)
		key_fonct_zoom(keycode, fdf);
	else if (keycode == 126 || keycode == 123
			|| keycode == 124 || keycode == 125)
		key_fonct_mv_struct(keycode, fdf);
	else if (keycode == 49)
		key_fonct_reset(fdf);
	else if (keycode == 13 || keycode == 0 || keycode == 1 || keycode == 2)
		key_fonct_rot(keycode, fdf);
	else if (keycode == 15 || keycode == 3)
		key_fonct_rot_z(keycode, fdf);
	else if (keycode == 36)
		fdf->key.hud *= -1;
	else
		fdf->repaint = 0;
	return (0);
}

int			loop_hook(t_fdf *fdf)
{
	if (fdf->repaint == 1)
	{
		mlx_destroy_image(fdf->mlx, fdf->img);
		fdf->img = mlx_new_image(fdf->mlx, X_WIN_1, Y_WIN_1);
		fdf->img_data = (int*)mlx_get_data_addr(fdf->img, &fdf->bpp,
				&fdf->lsize, &fdf->endian);
		if (fdf->color == 1)
		{
			fdf->pos = ft_set_color(fdf->pos);
			fdf->color = 0;
		}
		ft_place(*fdf);
		fdf->repaint = 0;
	}
	mlx_clear_window(fdf->mlx, fdf->win1);
	mlx_put_image_to_window(fdf->mlx, fdf->win1, fdf->img, 0, 0);
	if (fdf->key.hud == 1)
	{
		ft_feature_print(*fdf);
		ft_fps(fdf);
	}
	return (0);
}
