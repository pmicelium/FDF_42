/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_feature_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 15:30:51 by pmiceli           #+#    #+#             */
/*   Updated: 2017/12/20 19:53:50 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	ft_set_color(t_fdf fdf, char color)
{
	int mlx_color;

	if (color == 'R')
		mlx_color = 0x00FF0000;
	if (color == 'G')
		mlx_color = 0x0000FF00;
	if (color == 'B')
		mlx_color = 0x000000FF;
	if (color == 'L')
		mlx_color = fdf.pos.low_color;
	if (color == 'H')
		mlx_color = fdf.pos.high_color;
	return (mlx_color);
}

static void	ft_print_slider(t_fdf fdf, int x, int y, char color)
{
	int i;
	int j;
	int mlx_color;

	i = x;
	j = y;
	mlx_color = ft_set_color(fdf, color);
	while (i < x + 300)
	{
		j = y;
		while (j > y - 10)
		{
			mlx_pixel_put(fdf.mlx, fdf.win1, i, j, mlx_color);
			j--;
		}
		i++;
	}
}

static void	ft_feature_color(t_fdf fdf)
{
	mlx_string_put(fdf.mlx, fdf.win1, 25, Y_WIN_1 - 35, 0x00c1c1c1,"Lower color : ");
	ft_print_slider(fdf, 170, Y_WIN_1 - 20, 'R');
	ft_print_slider(fdf, 500, Y_WIN_1 - 20, 'G');
	ft_print_slider(fdf, 830, Y_WIN_1 - 20, 'B');
	ft_print_slider(fdf, 1160, Y_WIN_1 - 20, 'L');
	mlx_string_put(fdf.mlx, fdf.win1, 25, Y_WIN_1 - 75, 0x00c1c1c1,"Upper color : ");
	ft_print_slider(fdf, 170, Y_WIN_1 - 35, 'R');
}

static void	ft_feature_key(t_fdf fdf)
{
	mlx_string_put(fdf.mlx, fdf.win1, 25, 25, 0x00FFFFFF,  "Features :");
	mlx_string_put(fdf.mlx, fdf.win1, 25, 50, 0x00c1c1c1,  "Zoom        : 0");
	mlx_string_put(fdf.mlx, fdf.win1, 25, 70, 0x00c1c1c1,  "Zoom out    : 9");
	mlx_string_put(fdf.mlx, fdf.win1, 25, 90, 0x00c1c1c1,  "Elevation + : +");
	mlx_string_put(fdf.mlx, fdf.win1, 25, 110, 0x00c1c1c1, "Elevation - : -");
	mlx_string_put(fdf.mlx, fdf.win1, 25, 130, 0x00c1c1c1, "Mouve image : wasd");
}

static void	ft_feature_var(t_fdf fdf)
{
	mlx_string_put(fdf.mlx, fdf.win1, X_WIN_1 -100, 25, 0x00c1c1c1, "FPS :");
	mlx_string_put(fdf.mlx, fdf.win1, X_WIN_1 -110, 45, 0x00c1c1c1, ft_strjoin("Zoom : x", ft_itoa(fdf.key.zoom)));
	mlx_string_put(fdf.mlx, fdf.win1, X_WIN_1 -160, 65, 0x00c1c1c1, ft_strjoin("Elevation : ", ft_itoa(fdf.key.elev)));
}

void	ft_feature_print(t_fdf fdf)
{
	ft_feature_key(fdf);
	ft_feature_var(fdf);
}
