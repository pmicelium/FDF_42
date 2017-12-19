/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_feature_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 15:30:51 by pmiceli           #+#    #+#             */
/*   Updated: 2017/12/19 19:56:36 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	ft_feature_var(t_fdf fdf)
{
	mlx_string_put(fdf.mlx, fdf.win1, X_WIN_1 -100, 25, 0x00c1c1c1, "FPS :"); //peut etre le mettre dans une boucle plus tard//
	mlx_string_put(fdf.mlx, fdf.win1, X_WIN_1 -110, 45, 0x00c1c1c1, ft_strjoin("Zoom : ", ft_itoa(fdf.key.zoom)));
	mlx_string_put(fdf.mlx, fdf.win1, X_WIN_1 -160, 65, 0x00c1c1c1, ft_strjoin("Elevation : ", ft_itoa(fdf.key.elev)));
}

void	ft_feature_print(t_fdf fdf)
{
	mlx_string_put(fdf.mlx, fdf.win1, 25, 25, 0x00FFFFFF, "Features :");
	mlx_string_put(fdf.mlx, fdf.win1, 25, 50, 0x00c1c1c1,  "Zoom        : 0");
	mlx_string_put(fdf.mlx, fdf.win1, 25, 70, 0x00c1c1c1,  "Zoom out    : 9");
	mlx_string_put(fdf.mlx, fdf.win1, 25, 90, 0x00c1c1c1,  "Elevation + : +");
	mlx_string_put(fdf.mlx, fdf.win1, 25, 110, 0x00c1c1c1, "Elevation - : -");
	ft_feature_var(fdf);
}
