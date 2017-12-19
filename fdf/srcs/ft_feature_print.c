/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_feature_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 15:30:51 by pmiceli           #+#    #+#             */
/*   Updated: 2017/12/19 22:12:41 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	ft_feature_color(t_fdf fdf)
{
	mlx_string_put(fdf.mlx, fdf.win1, 25, Y_WIN_1 - 35, 0x00c1c1c1,"Lower color : faire itoa_base");
	mlx_string_put(fdf.mlx, fdf.win1, 25, Y_WIN_1 - 55, 0x00c1c1c1,"Upper color : faire itoa_base");
}

static void	ft_feature_key(t_fdf fdf)
{
	mlx_string_put(fdf.mlx, fdf.win1, 25, 25, 0x00FFFFFF,  "Features :");
	mlx_string_put(fdf.mlx, fdf.win1, 25, 50, 0x00c1c1c1,  "Zoom        : 0");
	mlx_string_put(fdf.mlx, fdf.win1, 25, 70, 0x00c1c1c1,  "Zoom out    : 9");
	mlx_string_put(fdf.mlx, fdf.win1, 25, 90, 0x00c1c1c1,  "Elevation + : +");
	mlx_string_put(fdf.mlx, fdf.win1, 25, 110, 0x00c1c1c1, "Elevation - : -");
}

static void	ft_feature_var(t_fdf fdf)
{
	mlx_string_put(fdf.mlx, fdf.win1, X_WIN_1 -100, 25, 0x00c1c1c1, "FPS :"); //peut etre le mettre dans une boucle plus tard//
	mlx_string_put(fdf.mlx, fdf.win1, X_WIN_1 -110, 45, 0x00c1c1c1, ft_strjoin("Zoom : x", ft_itoa(fdf.key.zoom)));
	mlx_string_put(fdf.mlx, fdf.win1, X_WIN_1 -160, 65, 0x00c1c1c1, ft_strjoin("Elevation : ", ft_itoa(fdf.key.elev)));
}

void	ft_feature_print(t_fdf fdf)
{
	ft_feature_key(fdf);
	ft_feature_var(fdf);
	ft_feature_color(fdf);
}
