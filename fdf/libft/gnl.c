/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 10:46:55 by pmiceli           #+#    #+#             */
/*   Updated: 2018/01/14 01:39:04 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

static char		*ft_get_after(char **line, char *after)
{
	if (ft_strchr(after, '\n'))
	{
		*ft_strchr(after, '\n') = '\0';
		*line = after;
		return (&after[ft_strlen(after) + 1]);
	}
	return (NULL);
}

int				gnl(int fd, char **line)
{
	int				ret;
	char			buff[BUFF_SIZE + 1];
	static char		*after;

	if (fd < 0 || fd >= OPEN_MAX)
		return (-1);
	if (!after)
		if (!(after = (char*)ft_memalloc(sizeof(char) * BUFF_SIZE)))
			return (-1);
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buff[ret] = '\0';
		after = ft_strjoin_free(after, buff);
		if (ft_strchr(after, '\n'))
			break ;
	}
	if ((after = ft_get_after(line, after)))
		return (1);
	free(after);
	return (0);
}
