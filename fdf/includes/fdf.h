/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 22:27:28 by pmiceli           #+#    #+#             */
/*   Updated: 2017/12/18 19:37:28 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include "mlx.h"
# include <math.h>
# define Y_WIN_1 800
# define X_WIN_1 1400

typedef struct		s_fdf
{
	void			*mlx;
	void			*img;
	int				*img_data;
	void			*win1;
}					t_fdf;

typedef struct		s_pos
{
	int				x;
	int				y;      //malloc foireux quelque part//
	int				**z;
	int				*placex;
	int				*placey;
	int				*elev;
	int				high_color;
	int				low_color;
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

typedef struct		s_key
{
	float			elev;
}					t_key;

void				bresenham_line(t_fdf fdf, t_put put, int color);
void				bresenham_circle(t_fdf fdf, t_put put, int color);
void				ft_place(t_fdf fdf, t_pos pos, t_key key);

t_pos				ft_set_pos(char *argv, t_pos pos, t_put put);

int					key_fonct(int keycode, t_key *key);

#endif
