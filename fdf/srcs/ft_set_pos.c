/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 15:31:44 by pmiceli           #+#    #+#             */
/*   Updated: 2017/12/07 12:49:05 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int		ft_parse_line(char *line)
{
	static int	c;
	static int	space;
	char		**tmp;
	int			i;
	int			j;

	tmp = ft_strsplit(line, ' ');
	j = 0;
	while (tmp[j])
		j++;
	if (c == 0)
	{
		space = j;
		c = ft_strlen(line);
	}
	i = ft_strlen(line);
	if (i != c || j != space)
	{
		ft_putendl_color("wrong line detected => exit", "red");
		exit(1);
	}
	return (0);
}

static char		**ft_malloc_line(char **line, int fd, t_pos *pos, t_put *put)
{
	char	*line2;
	char	**tmp;
	int		i;
	int		len;

	i = 0;
	pos->y = 0;
	while (get_next_line(fd, &line2) > 0)
		pos->y++;
	tmp = ft_strsplit(line2, ' ');
	while (tmp[pos->x])
		pos->x++;
	if (!(line = (char**)malloc(sizeof(char*) * pos->y)))
		exit(1);
	if (!(pos->z = (int**)malloc(sizeof(int*) * pos->y)))
		exit(1);
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
		x = 0;
		j = 0;
		y++;
		i++;
		free(tmp);
	}
	return (pos);
}

t_pos			ft_set_pos(char *argv, t_pos pos, t_put put)
{
	char	**line;
	int		fd;
	int		i;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		ft_putendl_color("READ error, check the file => exit", "red");
		exit(1);
	}
	i = 0;
	line = ft_malloc_line(line, fd, &pos, &put);
	close(fd);
	fd = open(argv, O_RDONLY);
	while (get_next_line(fd, &line[i]) > 0)
	{
		if (ft_parse_line(line[i]) == -1)
			exit(1);
		i++;
	}
	pos = ft_get_z(pos, line);
	free(line);
	return (pos);
}
