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

#include <mlx.h>
#include "libft/libft.h"
#include "fdf.h"

//ca ne sert a rien lol//
void	set_fonct_win(t_fdf fdf)
{
	size_t	x;
	size_t	y;

	x = 1;
	y = 0;
	while (x < 290)
		mlx_string_put(fdf.mlx, fdf.win2, x++, y, 0x00FFFFFF, "=");
	while (y < 380)
		mlx_string_put(fdf.mlx, fdf.win2, x, y++, 0x00FFFFFF, "|");
	while (x > 1)
		mlx_string_put(fdf.mlx, fdf.win2, x--, y, 0x00FFFFFF, "=");
	while (y > 1)
		mlx_string_put(fdf.mlx, fdf.win2, x, y--, 0x00FFFFFF, "|");
}
int		main(int argc, char *argv[])
{
	t_fdf	fdf;

	fdf.mlx = mlx_init();
	fdf.win1 = mlx_new_window(fdf.mlx, 1000, 1000, "fdf");
//	fdf.win2 = mlx_new_window(fdf.mlx, 300, 400, "fonction");
//	set_fonct_win(fdf);
	mlx_loop(fdf.mlx);
	return (0);
}
