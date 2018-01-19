/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xiaolin_wu.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 06:43:25 by pmiceli           #+#    #+#             */
/*   Updated: 2018/01/19 06:45:05 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef XIAOLIN_WU_H
# define XIAOLIN_WU_H
# include "fdf.h"

# define IPART_(X) ((int)(X))
# define ROUND_(X) ((int)(((double)(X)) + 0.5))
# define FPART_(X) (((double)(X)) - (double)IPART_(X))
# define RFPART_(X) (1.0 - FPART_(X))

typedef struct			s_print
{
	int					x;
	int					y;
	float				br;
	int					color;
}						t_print;

void					xioalin_wu(t_fdf fdf, t_put put);
void					print_xiao(int x, int y, float br, t_fdf fdf, int c);
int						set_brightness(int color, float br);
void					xiaolin_wu_3(t_fdf fdf, t_put put, t_wu wu);
int						check_print(int x, int y);
t_degrad				set_degrad(t_put put, t_degrad degrad);
#endif
