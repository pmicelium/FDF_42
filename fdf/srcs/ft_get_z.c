/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_z.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 04:56:06 by pmiceli           #+#    #+#             */
/*   Updated: 2018/01/14 05:06:30 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static t_pos	ft_malloc_z(t_pos pos)
{
	int		i;

	i = 0;
	if (!(pos.z = (int**)malloc(sizeof(int*) * (pos.y + 1))))
		exit(1);
	while (i < pos.y)
	{
		if (!(pos.z[i] = (int*)malloc(sizeof(int) * (pos.x + 1))))
			exit(1);
		i++;
	}
	return (pos);
}

t_pos			ft_get_z(int fd, t_pos pos, char *line)
{
	char	**tmp;
	int		x;
	int		i;
	int		y;

	y = 0;
	i = 0;
	pos = ft_malloc_z(pos);
	while ((gnl(fd, &line) > 0))
	{
		tmp = ft_strsplit(line, ' ');
		x = 0;
		i = 0;
		while(tmp[i])
		{
			pos.z[y][x] = ft_atoi(tmp[i++]);
			x++;
		}
		y++;
		ft_free_tab(tmp);
	}
	pos = ft_pos_normalization(pos);
	return (pos);
}

