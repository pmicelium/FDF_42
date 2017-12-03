/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 15:31:44 by pmiceli           #+#    #+#             */
/*   Updated: 2017/12/03 15:38:01 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		***ft_set_tab(int ***tab, char *argv)
{
	char	*line;
	int		fd;
	int		res;

	fd = open(argv, O_RDONLY);
	get_next_line(fd, &line);
	ft_putendl(line);
	while (res = get_next_line(fd, &line) < 0)
	{

	}
	return (tab);
}
