/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 22:27:28 by pmiceli           #+#    #+#             */
/*   Updated: 2017/12/07 12:49:16 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include "mlx.h"
# include <math.h>
typedef struct		s_fdf
{
	void			*mlx;
	void			*win1;
	void			*win2;
}					t_fdf;

typedef struct		s_pos
{
	int				x;
	int				y;
	int				**z;
}					t_pos;
typedef struct		s_put
{
	int				x0;
	int				y0;
	int				x1;
	int				y1;
	int				o_x;
	int				o_y;
	int				r;
}					t_put;

void				bresenham_line(t_fdf fdf, t_pos pos, t_put put, int color);
void				test_bresenham_line(t_fdf fdf, t_pos pos, t_put put);
void				test_bresenham_circle(t_fdf fdf, t_pos pos, t_put put);
t_pos				ft_set_pos(char *argv, t_pos pos, t_put put);
t_put				ft_set_put(t_pos pos, t_put put, t_fdf fdf);
void				bresenham_circle(t_fdf fdf, t_pos pos, t_put put);

#endif
