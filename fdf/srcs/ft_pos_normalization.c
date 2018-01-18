/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pos_normalization.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 17:59:54 by pmiceli           #+#    #+#             */
/*   Updated: 2018/01/18 21:53:46 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static t_pos	ft_pos_normalization_2(t_pos pos)
{
	int			i;
	int			j;

	i = 0;
	while (i < pos.y)
	{
		j = 0;
		while (j < pos.x)
		{
			pos.point[i][j].z -= pos.low_nb;
			j++;
		}
		i++;
	}
	return (pos);
}

t_pos			ft_pos_normalization(t_pos pos)
{
	int		i;
	int		j;

	pos.low_nb = pos.point[0][0].z;
	pos.high_nb = pos.point[0][0].z;
	i = 0;
	while (i < pos.y)
	{
		j = 0;
		while (j < pos.x)
		{
			if (pos.point[i][j].z < pos.low_nb)
				pos.low_nb = pos.point[i][j].z;
			else if (pos.point[i][j].z > pos.high_nb)
				pos.high_nb = pos.point[i][j].z;
			j++;
		}
		i++;
	}
	pos = ft_pos_normalization_2(pos);
	return (pos);
}
