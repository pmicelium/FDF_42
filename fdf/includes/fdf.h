/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 22:27:28 by pmiceli           #+#    #+#             */
/*   Updated: 2017/12/22 20:03:06 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include "mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdio.h>
# include <time.h>
# define Y_WIN_1 1000
# define X_WIN_1 1800

typedef struct		s_degrad
{
	int				h_r;
	int				h_g;
	int				h_b;
	int				l_r;
	int				l_g;
	int				l_b;
}					t_degrad;

typedef struct		s_pos
{
	int				x;
	int				y;      //malloc foireux quelque part je pense //
	int				**z;
	int				*placex;
	int				*placey;
	int				*elev;
	int				high_color;
	int				low_color;
	int				degraded;
}					t_pos;

typedef struct		s_put
{
	int				x0;
	int				y0;
	int				x1;
	int				y1;
	int				dx;
	int				dy;
	int				inc_x;
	int				inc_y;
	int				err;
	int				e2;
	int				o_x;
	int				o_y;
	int				r;
}					t_put;
/*
typedef struct		s_fps
{
	clock_t			time;
	int				fps;
	int				tmp;
}					t_fps;
*/
typedef struct		s_key
{
	int			elev;
	int			zoom;
	int			x_deriv;
	int			y_deriv;
	int			w;
	int			a;
	int			face;
}					t_key;

typedef struct		s_fdf
{
	void			*mlx;
	void			*img;
	int				*img_data;
	void			*win1;
	void			*win2;
	int				lsize;
	int				endian;
	int				bpp;
	struct s_pos	pos;
	struct s_key	key;
	struct s_degrad	degrad;
//	struct s_fps	fps;
}					t_fdf;

void				bresenham_line(t_fdf fdf, t_put put, int color, int degrad);
void				bresenham_circle(t_fdf fdf, t_put put, int color);
void				ft_place(t_fdf fdf, t_pos pos, t_key key);
void				ft_feature_print(t_fdf fdf);
void				key_fonct_set(t_fdf *fdf);

t_pos				ft_set_pos(char *argv, t_pos pos);

int					key_fonct(int keycode, t_fdf *fdf);
int					loop_hook(t_fdf *fdf);

#endif
