/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xioalin_wu.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 01:22:55 by pmiceli           #+#    #+#             */
/*   Updated: 2018/01/19 06:13:52 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef XIAOLING_WU_H
# include "fdf.h"
# define XIAOLING_WU_H

#define ipart_(X) ((int)(X))
#define round_(X) ((int)(((double)(X)) + 0.5))
#define fpart_(X) (((double)(X)) - (double)ipart_(X))
#define rfpart_(X) (1.0 - fpart_(X))

void		xioalin_wu(t_fdf fdf, t_put put);
void		print_xiao(int x, int y, float br, t_fdf fdf, int color);
int			set_brightness(int color, float br);
void		xiaolin_wu_3(t_fdf fdf, t_put put, t_wu wu);
int			check_print(int x, int y);
t_degrad	set_degrad(t_put put, t_degrad degrad);
#endif
