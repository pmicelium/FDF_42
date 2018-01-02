/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 22:27:28 by pmiceli           #+#    #+#             */
/*   Updated: 2017/12/29 19:40:09 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include "mlx.h"
# include <math.h>
# include <stdio.h>
# include <time.h>
# define Y_WIN_1 1000
# define X_WIN_1 1800
# define GREY 0x00c1c1c1
# define WHITE 0x00FFFFFF

//
//
//
//faire le menage dans les strcut//
//
//
//

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
	int				y;
	int				**z;
	int				*placex;
	int				*placey;
	int				*placez;
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
	int				color;
}					t_put;

typedef struct		s_fps
{
	unsigned int	fps;
	unsigned int	start;
}					t_fps;

typedef struct		s_key
{
	int				elev;
	int				zoom;
	double			rot_x;
	double			rot_y;
	double			rot_z;
	int				w;
	int				a;
	int				hud;
}					t_key;

typedef struct		s_fdf
{
	void			*mlx;
	void			*img;
	int				*img_data;
	void			*win1;
	int				lsize;
	int				endian;
	int				bpp;
	int				repaint;
	struct s_pos	pos;
	struct s_key	key;
	struct s_degrad	degrad;
	struct s_fps	fps;
}					t_fdf;

void				bresenham_line(t_fdf fdf, t_put put, int color, int degrad);
void				bresenham_circle(t_fdf fdf, t_put put, int color);
void				ft_place(t_fdf fdf, t_key key);
void				ft_feature_print(t_fdf fdf);
void				key_fonct_set(t_fdf *fdf);
void				ft_display_bonus_fr(void);
void				ft_display_bonus_en(void);
void				ft_antialiasing(t_fdf *fdf);
int					key_fonct(int keycode, t_fdf *fdf);
void				key_fonct_mv_struct(int keycode, t_fdf *fdf);
void				key_fonct_elev(int keycode, t_fdf *fdf);
void				key_fonct_zoom(int keycode, t_fdf *fdf);
void				key_fonct_reset(t_fdf *fdf);
void				ft_red_upper(t_fdf *fdf, int button, int x);
void				ft_green_upper(t_fdf *fdf, int button, int x);
void				ft_fps(t_fdf *fdf);
void				ft_link_point(t_fdf fdf);
void				ft_feature_color_2(t_fdf fdf);

t_pos				ft_set_pos(char *argv, t_pos pos);

int					mouse_fonct(int button, int x, int y, t_fdf *fdf);
int					loop_hook(t_fdf *fdf);

#endif
