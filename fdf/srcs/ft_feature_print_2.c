/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_feature_print_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 18:55:11 by pmiceli           #+#    #+#             */
/*   Updated: 2018/01/08 16:42:08 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_feature_color_2(t_fdf fdf)
{
	char *tmp;

	tmp = ft_itoa(fdf.degrad.h_r);
	mlx_string_put(fdf.mlx, fdf.win1, 180, Y_WIN_1 - 100, GREY, tmp);
	free(tmp);
	mlx_string_put(fdf.mlx, fdf.win1, 245, Y_WIN_1 - 100, GREY,
			"-     +");
	tmp = ft_itoa(fdf.degrad.h_g);
	mlx_string_put(fdf.mlx, fdf.win1, 265, Y_WIN_1 - 100, GREY, tmp);
	free(tmp);
	mlx_string_put(fdf.mlx, fdf.win1, 335, Y_WIN_1 - 100, GREY,
			"-     +");
	tmp = ft_itoa(fdf.degrad.h_b);
	mlx_string_put(fdf.mlx, fdf.win1, 355, Y_WIN_1 - 100, GREY, tmp);
	free(tmp);
}
