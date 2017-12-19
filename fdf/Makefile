NAME = fdf

SRCS = srcs/main.c\
	   srcs/ft_set_pos.c\
	   srcs/ft_algo_bresenham.c\
	   srcs/ft_place.c\
	   srcs/ft_key_fonc.c\
	   srcs/ft_feature_print.c\

all : $(NAME)

$(NAME) :
	gcc -o $(NAME) $(SRCS) libft/libft.a  minilibx_macos/libmlx.a -framework OpenGL -framework Appkit -fsanitize=address
	@echo "=============================================="

clean :
	rm fdf

re : clean all
