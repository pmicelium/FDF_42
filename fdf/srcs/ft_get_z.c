/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_z.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 04:56:06 by pmiceli           #+#    #+#             */
/*   Updated: 2018/01/16 22:35:41 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int		ft_set_color_2(t_pos pos, int x, int y)
{
	int		color;
	int		r;
	int		g;
	int		b;

	if (pos.point[y][x].z == 0)
		return (pos.low_color);
	r = (pos.degrad.h_r - pos.degrad.l_r) * ((float)pos.point[y][x].z /
			(float)(pos.high_nb - pos.low_nb)) + pos.degrad.l_r;
	g = (pos.degrad.h_g - pos.degrad.l_g) * ((float)pos.point[y][x].z /
			(float)(pos.high_nb - pos.low_nb)) + pos.degrad.l_g;
	b = (pos.degrad.h_b - pos.degrad.l_b) * ((float)pos.point[y][x].z /
			(float)(pos.high_nb - pos.low_nb)) + pos.degrad.l_b;
	color = (r & 0xFF) << 16 | (g & 0xFF) << 8 | (b & 0xFF);
	return (color);
}

t_pos	ft_set_color(t_pos pos)
{
	int		x;
	int		y;

	y = 0;
	while (y < pos.y)
	{
		x = 0;
		while (x < pos.x)
		{
			if (pos.point[y][x].hexa == 0)
				pos.point[y][x].color = ft_set_color_2(pos, x, y);
			x++;
		}
		y++;
	}
	return (pos);
}

static t_pos	ft_malloc_z(t_pos pos)
{
	int		i;

	i = 0;
	if (!(pos.point = (t_point**)ft_memalloc(sizeof(t_point*) * (pos.y + 1))))
		exit(1);
	while (i < pos.y)
	{
		if (!(pos.point[i] = (t_point*)ft_memalloc(sizeof(t_point)
						* (pos.x + 1))))
			exit(1);
		i++;
	}
	return (pos);
}

static int		ft_hexa(char *tmp)
{
	char		**tmp2;
	int			color;

	tmp2 = ft_strsplit(tmp, ',');
	color = ft_atoi_base(tmp2[1], HEXA);
	ft_free_tab(tmp2);
	return (color);
}

t_pos			ft_get_z(int fd, t_pos pos, char *line)
{
	char	**tmp;
	int		x;
	int		i;
	int		y;

	y = 0;
	pos = ft_malloc_z(pos);
	while ((gnl(fd, &line) > 0))
	{
		tmp = ft_strsplit(line, ' ');
		x = 0;
		i = 0;
		while (tmp[i])
		{
			if (ft_strstr(tmp[i], ",0x") != NULL)
			{
				pos.point[y][x].hexa = 1;
				pos.point[y][x].color = ft_hexa(tmp[i]);
			}
			else
				pos.point[y][x].hexa = 0;
			pos.point[y][x++].z = ft_atoi(tmp[i++]);
		}
		y++;
		ft_free_tab(tmp);
	}
	pos = ft_pos_normalization(pos);
	pos = ft_set_color(pos);
	return (pos);
}
