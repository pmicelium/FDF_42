/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 04:14:19 by pmiceli           #+#    #+#             */
/*   Updated: 2018/01/18 22:10:44 by pmiceli          ###   ########.fr       */
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
	int				h;
	int				i;
	int				j;
	char			**tmp;
	static int		nb = 0;

	j = -1;
	tmp = ft_strsplit(line, ' ');
	while (tmp[++j])
	{
		i = -1;
		h = ft_strstr(tmp[j], "0x") != NULL ? 1 : 0;
		while (tmp[j][++i])
		{
			if (ft_isdigit(tmp[j][i]) == 0 && tmp[j][i] != '-' && h == 0)
			{
				ft_free_tab(tmp);
				return (j);
			}
		}
	}
	ft_free_tab(tmp);
	if (nb == 0)
		nb = j;
	return (j != nb ? 0 : -1);
}

static int		ft_parse_line(int fd, t_pos *pos)
{
	char	*line;
	int		ret;

	while ((gnl(fd, &line) > 0))
	{
		if ((ret = ft_parse_line_2(line)) != -1)
		{
			if (ret == 0)
				ft_putstr_color("Error line ", "red");
			else
				ft_putstr_color("Wrong character detected line ", "red");
			ft_putnbr(pos->y + 1);
			if (ret != 0)
			{
				ft_putstr(":");
				ft_putnbr(ret);
			}
			ft_putendl_color(", exit", "red");
			return (0);
		}
		pos->x = pos->y == 0 ? ft_get_x(line) : pos->x;
		pos->y++;
	}
	pos->y++;
	return (1);
}

t_pos			ft_set_pos(char *argv, t_pos pos)
{
	int			fd;
	char		*line;

	line = NULL;
	pos.y = 0;
	if ((fd = open(argv, O_RDONLY)) < 0)
	{
		ft_putendl_color("READ error, check the file", "red");
		exit(1);
	}
	if (ft_parse_line(fd, &pos) == 0)
		exit(1);
	close(fd);
	fd = open(argv, O_RDONLY);
	pos = ft_get_z(fd, pos, line);
	close(fd);
	return (pos);
}
