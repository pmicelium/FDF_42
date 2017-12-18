NAME = fdf

SRCS = srcs/ft_fdf.c\
	   srcs/ft_set_pos.c\
	   srcs/ft_algo_bresenham_line.c\
	   srcs/ft_algo_bresenham_circle.c\
	   srcs/ft_place.c\
	   srcs/ft_key_fonc.c\

all : $(NAME)

$(NAME) :
	gcc -o $(NAME) $(SRCS) libft/libft.a  minilibx_macos/libmlx.a -framework OpenGL -framework Appkit -fsanitize=address
	@echo "=============================================="

clean :
	rm fdf

re : clean all
