/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_feature_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 15:30:51 by pmiceli           #+#    #+#             */
/*   Updated: 2017/12/22 23:46:23 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	ft_feature_color(t_fdf fdf)
{
	mlx_string_put(fdf.mlx, fdf.win1, 25, Y_WIN_1 - 125, 0x00FFFFFF,   "Colors :");
	mlx_string_put(fdf.mlx, fdf.win1, 180, Y_WIN_1 - 125, 0x00FFFFFF,  "RED");
	mlx_string_put(fdf.mlx, fdf.win1, 255, Y_WIN_1 - 125, 0x00FFFFFF,  "GREEN");
	mlx_string_put(fdf.mlx, fdf.win1, 355, Y_WIN_1 - 125, 0x00FFFFFF,  "BLUE");

	mlx_string_put(fdf.mlx, fdf.win1, 25, Y_WIN_1 - 100, fdf.pos.high_color,   "Upper color :");
	mlx_string_put(fdf.mlx, fdf.win1, 160, Y_WIN_1 - 100, 0x00c1c1c1, "-     +");
	mlx_string_put(fdf.mlx, fdf.win1, 180, Y_WIN_1 - 100, 0x00c1c1c1, ft_itoa(fdf.degrad.h_r));
	mlx_string_put(fdf.mlx, fdf.win1, 245, Y_WIN_1 - 100, 0x00c1c1c1, "-     +");
	mlx_string_put(fdf.mlx, fdf.win1, 265, Y_WIN_1 - 100, 0x00c1c1c1, ft_itoa(fdf.degrad.h_g));
	mlx_string_put(fdf.mlx, fdf.win1, 335, Y_WIN_1 - 100, 0x00c1c1c1, "-     +");
	mlx_string_put(fdf.mlx, fdf.win1, 355, Y_WIN_1 - 100, 0x00c1c1c1, ft_itoa(fdf.degrad.h_b));


	mlx_string_put(fdf.mlx, fdf.win1, 25, Y_WIN_1 - 75, fdf.pos.low_color,   "Lower color:");
	mlx_string_put(fdf.mlx, fdf.win1, 160, Y_WIN_1 - 75, 0x00c1c1c1, "-     +");
	mlx_string_put(fdf.mlx, fdf.win1, 180, Y_WIN_1 - 75, 0x00c1c1c1, ft_itoa(fdf.degrad.l_r));
	mlx_string_put(fdf.mlx, fdf.win1, 245, Y_WIN_1 - 75, 0x00c1c1c1, "-     +");
	mlx_string_put(fdf.mlx, fdf.win1, 265, Y_WIN_1 - 75, 0x00c1c1c1, ft_itoa(fdf.degrad.l_g));
	mlx_string_put(fdf.mlx, fdf.win1, 335, Y_WIN_1 - 75, 0x00c1c1c1, "-     +");
	mlx_string_put(fdf.mlx, fdf.win1, 355, Y_WIN_1 - 75, 0x00c1c1c1, ft_itoa(fdf.degrad.l_b));
}

static void	ft_feature_key(t_fdf fdf)
{
	mlx_string_put(fdf.mlx, fdf.win1, 25, 25, 0x00FFFFFF,  "Features :");
	mlx_string_put(fdf.mlx, fdf.win1, 25, 50, 0x00c1c1c1,  "HUD            : return");
	mlx_string_put(fdf.mlx, fdf.win1, 25, 70, 0x00c1c1c1,  "Zoom           : 0");
	mlx_string_put(fdf.mlx, fdf.win1, 25, 90, 0x00c1c1c1,  "Zoom out       : 9");
	mlx_string_put(fdf.mlx, fdf.win1, 25, 110, 0x00c1c1c1, "Elevation +    : +");
	mlx_string_put(fdf.mlx, fdf.win1, 25, 130, 0x00c1c1c1, "Elevation -    : -");
	mlx_string_put(fdf.mlx, fdf.win1, 25, 150, 0x00c1c1c1, "Mouve image    : wasd");
	mlx_string_put(fdf.mlx, fdf.win1, 25, 170, 0x00c1c1c1, "Reset image    : space");
	mlx_string_put(fdf.mlx, fdf.win1, 25, 190, 0x00c1c1c1, "hidden surface : c");
}

static void	ft_feature_var(t_fdf fdf)
{
	mlx_string_put(fdf.mlx, fdf.win1, X_WIN_1 -100, 25, 0x00c1c1c1, "FPS :");
	mlx_string_put(fdf.mlx, fdf.win1, X_WIN_1 -110, 45, 0x00c1c1c1, ft_strjoin("Zoom : x", ft_itoa(fdf.key.zoom)));
	mlx_string_put(fdf.mlx, fdf.win1, X_WIN_1 -160, 65, 0x00c1c1c1, ft_strjoin("Elevation : ", ft_itoa(fdf.key.elev)));
	mlx_string_put(fdf.mlx, fdf.win1, X_WIN_1 -220, 85, 0x00c1c1c1, "hidden surfaces : ");
	if (fdf.key.face == 1)
		mlx_string_put(fdf.mlx, fdf.win1, X_WIN_1 -40, 85, 0x00FF0000, "off");
	else
		mlx_string_put(fdf.mlx, fdf.win1, X_WIN_1 -40, 85, 0x0000FF00, "on");

}

void	ft_feature_print(t_fdf fdf)
{
	ft_feature_key(fdf);
	ft_feature_var(fdf);
	ft_feature_color(fdf);
}
