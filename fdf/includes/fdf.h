/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 22:27:28 by pmiceli           #+#    #+#             */
/*   Updated: 2017/12/02 22:29:53 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft/libft.h"
# include "minilibx_macos/mlx.h"
typedef struct		s_fdf
{
	void			*mlx;
	void			*win1;
	void			*win2;
}					t_fdf;

int					***ft_set_tab(int ***tab, char *argv);

#endif
