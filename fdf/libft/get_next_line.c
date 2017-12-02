/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 10:46:55 by pmiceli           #+#    #+#             */
/*   Updated: 2017/12/02 18:43:56 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include <limits.h>
#include <fcntl.h>
#include <stdio.h>

static char		*ft_get_after(char **line, char *after)
{
	char	*tmp;

	if (ft_strchr(after, '\n'))
	{
		*ft_strchr(after, '\n') = '\0';
		*line = after;
		tmp = ft_strdup(&after[ft_strlen(after) + 1]);
		return (tmp);
	}
	if (ft_strlen(after))
	{
		*line = after;
		tmp = ft_strdup(&after[ft_strlen(after) + 1]);
		return (tmp);
	}
	return (NULL);
}

int				get_next_line(int fd, char **line)
{
	int				ret;
	char			buff[BUFF_SIZE + 1];
	static char		*after[OPEN_MAX];

	if (fd < 0 || fd >= OPEN_MAX)
		return (-1);
	if (!after[fd])
		if (!(after[fd] = (char*)ft_memalloc(sizeof(char) * BUFF_SIZE)))
			return (-1);
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buff[ret] = '\0';
		after[fd] = ft_strjoin_free(after[fd], buff);
		if (ft_strchr(after[fd], '\n'))
			break ;
	}
	if ((after[fd] = ft_get_after(line, after[fd])))
		return (1);
	return (0);
}
