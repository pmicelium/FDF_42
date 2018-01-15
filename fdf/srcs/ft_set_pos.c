/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 04:14:19 by pmiceli           #+#    #+#             */
/*   Updated: 2018/01/15 22:04:20 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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

static int		ft_parse_line_2(char *line)
{
	/*
	int		i;
	int		j;
	char	**tmp;

	i = 0;
	tmp = ft_strsplit(line, ' ');
	while (tmp[i]);
	ft_free_tab(tmp);
	*/
	if (!(line))
			NL;
	return (1);
}

static int		ft_parse_line(int fd, t_pos *pos)
{
	char	*line;

	while ((gnl(fd, &line) > 0))
	{
		if (ft_parse_line_2(line) == 0)
		{
			ft_putstr_color("Error line ", "red");
			ft_putnbr(pos->y);
			ft_putendl_color(" , exit", "red");
			return (0);
		}
		if (pos->y == 0)
			pos->x = ft_get_x(line);
		pos->y++;
	}
	return (1);
}

t_pos			ft_set_pos(char *argv, t_pos pos)
{
	int			fd;

	pos.y = 0;
	if ((fd = open(argv, O_RDONLY)) < 0)
	{
		ft_putendl_color("READ error, check the file !", "red");
		exit(1);
	}
	if (ft_parse_line(fd, &pos) == 0)
		exit(1);
	close(fd);
	fd = open(argv, O_RDONLY);
	pos = ft_get_z(fd, pos);
	close(fd);
	return (pos);
}
