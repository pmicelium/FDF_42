/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 15:31:44 by pmiceli           #+#    #+#             */
/*   Updated: 2018/01/14 02:55:31 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int		ft_parse_line(char *line)
{
	if (!(line))
		ft_putendl(line);
	return (1);
}

static int		ft_get_x(char *line)
{
	int		i;
	int		res;

	i = 0;
	res = 0;
	while (line[i])
	{
		if (line[i] != 32 && (line[i + 1] == 32 || line[i + 1] == '\0'))
			res++;
		i++;
	}
	return (res);
}

t_pos			ft_set_pos(char *argv, t_pos pos)
{
	int			fd;
	int test;
	char		*line;

	pos.y = 0;
	if ((fd = open(argv, O_RDONLY)) < 0)
	{
		ft_putendl_color("READ error, check the file !", "red");
		exit(1);
	}
//	ft_get_xy(fd, &pos);
	close(fd);
	fd = open(argv, O_RDONLY);
	while ((test = gnl(fd, &line) > 0))
	{
		if (ft_parse_line(line) == 0)
		{
			if (pos.y == 0)
				pos.x = ft_get_x(line);
			ft_putstr_color("Error line ", "red");
			ft_putnbr(pos.y);
			ft_putendl_color(" , exit", "red");
			free(line);
			exit(1);
		}
		pos.y++;
	}
	ft_putnbr_endl(pos.x);
	ft_putnbr_endl(pos.y);
	close(fd);
	TEST;
	while (1);
	return (pos);
}
