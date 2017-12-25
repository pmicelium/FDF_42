/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 22:27:28 by pmiceli           #+#    #+#             */
/*   Updated: 2017/12/23 23:08:47 by pmiceli          ###   ########.fr       */
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

typedef struct		s_cal
{
	int				x_len;
	int				y_len;
	int				base_x_len;
	int				base_y_len;
	int				y_trans;
	int				x_trans;
	int				rot_x;
	int				rot_y;
}					t_cal;

typedef struct		s_pos
{
	int				x;
	int				y;      //malloc foireux quelque part je pense //
	int				**z;
	int			*placex;
	int			*placey;
	int				*elev;
	int				high_color;
	int				low_color;
	int				degraded;
	struct s_cal	cal;
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
	int			elev;
	int			zoom;
	double		rot_x;
	double		rot_y;
	double		rot_z;
	int			w;
	int			a;
	float		x_deriv;
	float		y_deriv;
	int			face;
	int			hud;
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
void				ft_display_bonus_fr(void);
void				ft_display_bonus_en(void);

t_pos				ft_set_pos(char *argv, t_pos pos);

int					key_fonct(int keycode, t_fdf *fdf);
int					mouse_fonct(int button, int x, int y, t_fdf *fdf);
int					loop_hook(t_fdf *fdf);

#endif
