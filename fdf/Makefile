NAME = fdf

SRCS = srcs/fdf.c\
	   srcs/ft_set_tab.c\

all : $(NAME)

$(NAME) :
	make -C libft
	make -C minilibx_macos
	gcc -o $(NAME) $(SRCS) libft/libft.a minilibx_macos/libmlx.a -framework OpenGL -framework Appkit

clean :
	rm fdf

re : clean all
