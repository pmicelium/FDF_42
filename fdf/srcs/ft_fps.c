/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fps.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 21:44:12 by pmiceli           #+#    #+#             */
/*   Updated: 2017/12/27 23:11:07 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		ft_fps(t_fdf fdf)
{
	static struct timespec			last;
	static unsigned long			start = 0;
	static unsigned int		fps;
	static unsigned int		tmp = 0;
	char					*tmp_2;
	struct timespec			tmptime;

	fps++;
	if (!last.tv_nsec)
		clock_gettime(CLOCK_MONOTONIC_RAW, &last);
	clock_gettime(CLOCK_MONOTONIC_RAW, &tmptime);
	start += (tmptime.tv_sec - last.tv_sec) * 1000000000 + (tmptime.tv_nsec - last.tv_nsec);
	clock_gettime(CLOCK_MONOTONIC_RAW, &last);
	if (((float)start / 1000000000) >= 0.25)
	{
		tmp = start / fps;
		fps = 0;
		start = 0;
	}
	tmp_2 = tmp == 0 ? ft_strdup("0") : ft_itoa((int)((float)1 / ((float)tmp / 1000000000)));
	mlx_string_put(fdf.mlx, fdf.win1, X_WIN_1 - 40, 25, GREY, tmp_2);
	free(tmp_2);
}


