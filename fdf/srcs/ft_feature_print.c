/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_feature_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 15:30:51 by pmiceli           #+#    #+#             */
/*   Updated: 2018/01/16 04:46:03 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	ft_feature_color_3(t_fdf fdf)
{
	char *tmp;

	mlx_string_put(fdf.mlx, fdf.win1, 25, Y_WIN_1 - 75, fdf.pos.low_color,
			"Lower color:");
	mlx_string_put(fdf.mlx, fdf.win1, 160, Y_WIN_1 - 75, GREY,
			"-     +");
	tmp = ft_itoa(fdf.pos.degrad.l_r);
	mlx_string_put(fdf.mlx, fdf.win1, 180, Y_WIN_1 - 75, GREY, tmp);
	free(tmp);
	mlx_string_put(fdf.mlx, fdf.win1, 245, Y_WIN_1 - 75, GREY,
			"-     +");
	tmp = ft_itoa(fdf.pos.degrad.l_g);
	mlx_string_put(fdf.mlx, fdf.win1, 265, Y_WIN_1 - 75, GREY, tmp);
	free(tmp);
	mlx_string_put(fdf.mlx, fdf.win1, 335, Y_WIN_1 - 75, GREY,
			"-     +");
	tmp = ft_itoa(fdf.pos.degrad.l_b);
	mlx_string_put(fdf.mlx, fdf.win1, 355, Y_WIN_1 - 75, GREY, tmp);
	free(tmp);
}

static void	ft_feature_color(t_fdf fdf)
{
	mlx_string_put(fdf.mlx, fdf.win1, 25, Y_WIN_1 - 125, WHITE,
			"Colors :");
	mlx_string_put(fdf.mlx, fdf.win1, 180, Y_WIN_1 - 125, WHITE,
			"RED");
	mlx_string_put(fdf.mlx, fdf.win1, 255, Y_WIN_1 - 125, WHITE,
			"GREEN");
	mlx_string_put(fdf.mlx, fdf.win1, 355, Y_WIN_1 - 125, WHITE,
			"BLUE");
	mlx_string_put(fdf.mlx, fdf.win1, 25, Y_WIN_1 - 100, fdf.pos.high_color,
			"Upper color :");
	mlx_string_put(fdf.mlx, fdf.win1, 160, Y_WIN_1 - 100, GREY,
			"-     +");
	ft_feature_color_2(fdf);
	ft_feature_color_3(fdf);
}

static void	ft_feature_key(t_fdf fdf)
{
	mlx_string_put(fdf.mlx, fdf.win1, 25, 25, 0x00FFFFFF,
			"Features :");
	mlx_string_put(fdf.mlx, fdf.win1, 25, 50, 0x00c1c1c1,
			"HUD                 : return");
	mlx_string_put(fdf.mlx, fdf.win1, 25, 70, 0x00c1c1c1,
			"Zoom                : 0");
	mlx_string_put(fdf.mlx, fdf.win1, 25, 90, 0x00c1c1c1,
			"Zoom out            : 9");
	mlx_string_put(fdf.mlx, fdf.win1, 25, 110, 0x00c1c1c1,
			"Elevation +         : +");
	mlx_string_put(fdf.mlx, fdf.win1, 25, 130, 0x00c1c1c1,
			"Elevation -         : -");
	mlx_string_put(fdf.mlx, fdf.win1, 25, 150, 0x00c1c1c1,
			"Rotate image < x >  : w s");
	mlx_string_put(fdf.mlx, fdf.win1, 25, 170, 0x00c1c1c1,
			"Rotate image < y >  : a d");
	mlx_string_put(fdf.mlx, fdf.win1, 25, 190, 0x00c1c1c1,
			"Rotate image < z >  : r f");
	mlx_string_put(fdf.mlx, fdf.win1, 25, 210, 0x00c1c1c1,
			"Move image          : arrows");
	mlx_string_put(fdf.mlx, fdf.win1, 25, 230, 0x00c1c1c1,
			"Reset image         : space");
}

static void	ft_feature_var(t_fdf fdf)
{
	char *tmp;

	mlx_string_put(fdf.mlx, fdf.win1, X_WIN_1 - 100, 25, 0x00c1c1c1, "FPS :");
	tmp = ft_strjoin_free_2("Zoom : x", ft_itoa(fdf.key.zoom));
	mlx_string_put(fdf.mlx, fdf.win1, X_WIN_1 - 110, 45, 0x00c1c1c1, tmp);
	free(tmp);
	tmp = ft_strjoin_free_2("Elevation : ", ft_itoa(fdf.key.elev));
	mlx_string_put(fdf.mlx, fdf.win1, X_WIN_1 - 160, 65, 0x00c1c1c1, tmp);
	free(tmp);
	tmp = ft_strjoin_free_2("X-axis rotation : ", ft_itoa(fdf.key.rot_x));
	mlx_string_put(fdf.mlx, fdf.win1, X_WIN_1 - 220, 85, 0x00c1c1c1, tmp);
	free(tmp);
	tmp = ft_strjoin_free_2("Y-axis rotation : ", ft_itoa(fdf.key.rot_y));
	mlx_string_put(fdf.mlx, fdf.win1, X_WIN_1 - 220, 105, 0x00c1c1c1, tmp);
	free(tmp);
	tmp = ft_strjoin_free_2("Z-axis rotation : ", ft_itoa(fdf.key.rot_z));
	mlx_string_put(fdf.mlx, fdf.win1, X_WIN_1 - 220, 125, 0x00c1c1c1, tmp);
	free(tmp);
}

void		ft_feature_print(t_fdf fdf)
{
	ft_feature_key(fdf);
	ft_feature_var(fdf);
	ft_feature_color(fdf);
}
