/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 22:27:28 by pmiceli           #+#    #+#             */
/*   Updated: 2018/01/19 04:31:09 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../libft/includes/libft.h"
# include "mlx.h"
# include <math.h>
# include <stdio.h>
# include <time.h>
# define Y_WIN_1 1000
# define X_WIN_1 1800
# define GREY 0x00c1c1c1
# define WHITE 0x00FFFFFF
# define X_CEN ((fdf->pos.x / 2)  * fdf->key.zoom)
# define Y_CEN ((fdf->pos.y / 2 - 1) * fdf->key.zoom)
# define Z_CEN ((fdf->pos.high_nb / 2) * fdf->key.elev)

typedef struct		s_degrad
{
	int				h_r;
	int				h_g;
	int				h_b;
	int				l_r;
	int				l_g;
	int				l_b;
	int				b_r;
	int				b_g;
	int				b_b;
	int				c_r;
	int				c_g;
	int				c_b;
}					t_degrad;

typedef struct		s_point
{
	int				hexa;
	int				color;
	int				z;
}					t_point;

typedef struct		s_pos
{
	int				x;
	int				y;
	int				*placex;
	int				*placey;
	int				*placez;
	int				*elev;
	int				*color;
	int				high_color;
	int				low_color;
	int				degraded;
	int				low_nb;
	int				high_nb;
	struct s_point	**point;
	struct s_degrad	degrad;
}					t_pos;

typedef struct		s_wu
{
	double			gradient;
	double			xend;
	double			yend;
	double			xgap;
	double			ygap;
	int				xpx11;
	int				ypx11;
	double			intery;
	double			interx;
	int				xpx12;
	int				ypx12;
}					t_wu;


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
	int				color;
	int				color1;
//	struct s_wu		wu;
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
	int				anti_aliasing;
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
	int				color;
	int				leaks;
	struct s_pos	pos;
	struct s_key	key;
	struct s_fps	fps;
}					t_fdf;

void				bresenham_line(t_fdf fdf, t_put put);
void				ft_place(t_fdf fdf);
void				ft_feature_print(t_fdf fdf);
void				key_fonct_set(t_fdf *fdf);
void				ft_display_bonus_fr(void);
void				ft_display_bonus_en(void);
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
t_pos				ft_pos_normalization(t_pos pos);
t_pos				ft_get_z(int fd, t_pos pos, char *line);
t_pos				ft_set_color(t_pos pos);
int					mouse_fonct(int button, int x, int y, t_fdf *fdf);
int					loop_hook(t_fdf *fdf);
void				mouse_fonct_zoom(int button, t_fdf *fdf);
void				ft_print_usage();
void				key_fonct_2(int keycode, t_fdf *fdf);
void				xiaolin_wu(t_fdf fdf, t_put put);

#endif
