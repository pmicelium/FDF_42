/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 15:31:44 by pmiceli           #+#    #+#             */
/*   Updated: 2018/01/02 18:33:45 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int		ft_parse_line(char *line)
{
	return (0);
}

static int		ft_count_x(char *str)
{
	int		i;
	int		res;

	i = 0;
	res = 0;
	while (str[i])
	{
		if (str[i] != 32 && (str[i + 1] == 32 || str[i + 1] == '\0'))
			res++;
		i++;
	}
	return (res);
}

static char		**ft_malloc_line(char **line, int fd, t_pos *pos)
{
	char	*line2;
	int		i;
	int		j;

	i = 0;
	j = 0;
	pos->y = 0;
	pos->x = 0;
	line2 = NULL;
	while (get_next_line(fd, &line2) > 0)
	{
		if (j == 0)
		{
			pos->x = ft_count_x(line2);
			j++;
		}
		pos->y++;
		free(line2);
	}
// no leaks //
	if (!(line = (char**)malloc(sizeof(char*) * (pos->y + 1))))
		exit(1);
	line[pos->y] = NULL;
	if (!(pos->z = (int**)malloc(sizeof(int*) * (pos->y + 1))))
		exit(1);
	pos->z[pos->y] = NULL;
	while (i < pos->y)
	{
		if (!(pos->z[i] = (int*)malloc(sizeof(int) * pos->x)))
			exit(1);
		i++;
	}
	return (line);
}

static t_pos	ft_get_z(t_pos pos, char **line)
{
	int		i;
	int		j;
	int		x;
	int		y;
	char	**tmp;

	i = 0;
	y = 0;
	while (line[i] && i < pos.y - 1)
	{
		tmp = ft_strsplit(line[i], ' ');
		j = 0;
		x = 0;
		while (tmp[j])
		{
			pos.z[y][x] = ft_atoi(tmp[j++]);
			x++;
		}
		y++;
		i++;
		ft_free_tab(tmp);
	}
	return (pos);
}

t_pos			ft_set_pos(char *argv, t_pos pos)
{
	char	**line;
	int		fd;
	int		i;

	line = NULL;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		ft_putendl_color("READ error, check the file => exit", "red");
		exit(1);
	}
	i = 0;
	line = ft_malloc_line(line, fd, &pos); //faire apres le parse//
	close(fd);
	fd = open(argv, O_RDONLY);
	while (get_next_line(fd, &line[i]) > 0)
	{
		if (ft_parse_line(line[i]) == -1)
			exit(1);
		i++;
	}
	close(fd);
	pos = ft_get_z(pos, line);
	ft_free_tab(line);
	return (pos);
}
