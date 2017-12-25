/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fps.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 21:44:12 by pmiceli           #+#    #+#             */
/*   Updated: 2017/12/25 21:45:34 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		ft_fps(t_fdf fdf, clock_t time)
{
	static clock_t			start;
	static unsigned int		fps;
	static unsigned int		tmp = 0;

	ft_feature_print(fdf);
	fps++;
	time = clock() - time;
	start += time;
	if (((float)start / CLOCKS_PER_SEC) >= 0.25)
	{
		mlx_string_put(fdf.mlx, fdf.win1, X_WIN_1 - 40, 25, 0x00c1c1c1,
				ft_itoa(fps * 4));
		tmp = fps * 4;
		fps = 0;
		start = 0;
	}
	else
		mlx_string_put(fdf.mlx, fdf.win1, X_WIN_1 - 40, 25, 0x00c1c1c1,
				ft_itoa(tmp));
}
