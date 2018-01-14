#include "./libft/libft.h"

int		main(int ac, char **av)
{
	char *str;

	int fd = open(av[1], O_RDONLY);
	get_next_line(fd, &str);
	ft_putendl(str);
	free(str);
	while (1);
	return (0);
}
