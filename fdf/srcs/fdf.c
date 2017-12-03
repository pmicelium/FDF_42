/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 22:26:04 by pmiceli           #+#    #+#             */
/*   Updated: 2017/12/02 22:55:47 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int		main(int argc, char *argv[])
{
	t_fdf	fdf;
	int		***tab;

	tab = ft_set_tab(tab, argv[1]);
	fdf.mlx = mlx_init();
	fdf.win1 = mlx_new_window(fdf.mlx, 500, 500, "fdf");
//	fdf.win2 = mlx_new_window(fdf.mlx, 300, 400, "fonction");
//	set_fonct_win(fdf);
	mlx_loop(fdf.mlx);
	return (0);
}
