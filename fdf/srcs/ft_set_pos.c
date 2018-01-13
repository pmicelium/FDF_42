/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 15:31:44 by pmiceli           #+#    #+#             */
/*   Updated: 2018/01/08 18:27:31 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int		ft_parse_line(char *line)
{
	return (1);
}

static void		ft_get_xy(int fd, t_pos *pos)
{
	
}

t_pos			ft_set_pos(char *argv, t_pos pos)
{
	int			fd;
	int			i;
	int test;
	char		*line;

	i = 0;
	if ((fd = open(argv, O_RDONLY)) < 0)
	{
		ft_putendl_color("READ error, check the file !", "red");
		exit(1);
	}
	ft_get_xy(fd, &pos);
	close(fd);
	fd = open(argv, O_RDONLY);
//	/*
	while ((test = gnl(fd, &line) > 0))
	{
		ft_putstr_color("gnl : ", "green");
		ft_putnbr_endl(test);
		if (ft_parse_line(line) == 0)
		{
			ft_putstr_color("Error line ", "red");
			ft_putnbr(i);
			ft_putendl_color(" , exit", "red");
			free(line);
			exit(1);
		}
		ft_putendl(line);
		i++;
		free(line);
	}
//	*/
	close(fd);
	while (1);
	return (pos);
}
