/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pos_normalization.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 17:59:54 by pmiceli           #+#    #+#             */
/*   Updated: 2018/01/08 18:35:38 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static t_pos	ft_pos_normalization_2(t_pos pos)
{
	int		i;
	int			j;

	i = 0;
	while (i < pos.y - 1)
	{
		j = 0;
		while (j < pos.x)
		{
			pos.z[i][j] -= pos.low_nb;
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

	pos.low_nb = pos.z[0][0];
	pos.high_nb = pos.z[0][0];
	i = 0;
	while (i < pos.y - 1)
	{
		j = 0;
		while (j < pos.x)
		{
			if (pos.z[i][j] < pos.low_nb)
				pos.low_nb = pos.z[i][j];
			else if (pos.z[i][j] > pos.high_nb)
				pos.high_nb = pos.z[i][j];
			j++;
		}
		i++;
	}
	pos = ft_pos_normalization_2(pos);
	return (pos);
}
