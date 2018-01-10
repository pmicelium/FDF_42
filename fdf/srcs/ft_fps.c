/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fps.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 21:44:12 by pmiceli           #+#    #+#             */
/*   Updated: 2018/01/08 16:43:09 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		ft_fps(t_fdf *fdf)
{
	static struct timespec			last;
	static unsigned int				tmp;
	char							*tmp_2;
	struct timespec					tmptime;

	fdf->fps.fps++;
	if (!last.tv_nsec)
		clock_gettime(CLOCK_MONOTONIC_RAW, &last);
	clock_gettime(CLOCK_MONOTONIC_RAW, &tmptime);
	fdf->fps.start += (tmptime.tv_sec - last.tv_sec) * 1000000000 +
		(tmptime.tv_nsec - last.tv_nsec);
	clock_gettime(CLOCK_MONOTONIC_RAW, &last);
	if (((float)fdf->fps.start / 1000000000) >= 0.25)
	{
		tmp = fdf->fps.start / fdf->fps.fps;
		fdf->fps.fps = 0;
		fdf->fps.start = 0;
	}
	tmp_2 = tmp == 0 ? ft_strdup("0") : ft_itoa((int)((float)1 /
				((float)tmp / 1000000000)));
	mlx_string_put(fdf->mlx, fdf->win1, X_WIN_1 - 40, 25, GREY, tmp_2);
	free(tmp_2);
}
