#include "../fdf.h"

int		***ft_set_tab(int ***tab, char *argv)
{
	char	*line;
	int		fd;

	fd = open(argv, O_RDONLY);
	get_next_line(fd, &line);
	ft_putendl(line);
	return (tab);
}
