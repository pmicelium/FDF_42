NAME = fdf

SRCS = srcs/main.c\
	   srcs/ft_set_pos.c\
	   srcs/ft_algo_bresenham.c\
	   srcs/ft_place.c\
	   srcs/ft_key_fonct.c\
	   srcs/ft_key_fonct_2.c\
	   srcs/ft_mouse_fonct.c\
	   srcs/ft_mouse_fonct_2.c\
	   srcs/ft_feature_print.c\
	   srcs/ft_feature_print_2.c\
	   srcs/ft_display_bonus.c\
	   srcs/ft_fps.c\
	   srcs/ft_link_point.c\
	   srcs/ft_pos_normalization.c\

all : test

$(NAME) :
	@echo "\033[036m=>	\033[0m\033[033mCompiling libft ...\033[0m"
	@make re -C libft
	@echo "\033[036m=>	\033[0m\033[032mDONE !\033[0m"
	@echo "\033[036m=>	\033[0m\033[033mCompiling minilibx_macos ...\033[0m"
	@make re -C minilibx_macos
	@echo "\033[036m=>	\033[0m\033[032mDONE !\033[0m"
	@echo "\033[036m=>	\033[0m\033[033mCompiling FDF ...\033[0m"
	@gcc -Wall -Wextra -Werror -o $(NAME) $(SRCS) libft/libft.a  minilibx_macos/libmlx.a -framework OpenGL -framework Appkit -fsanitize=address
	@echo "\033[036m=>	\033[0m\033[032mDONE !\033[0m"
	@echo "=============================================="

test :
	@echo "\033[036m=>	\033[0m\033[033mCompiling FDF ...\033[0m"
	@gcc -o $(NAME) $(SRCS) libft/libft.a  minilibx_macos/libmlx.a -framework OpenGL -framework Appkit -fsanitize=address
	@echo "\033[036m=>	\033[0m\033[032mDONE !\033[0m"
	@echo "=============================================="

clean :
	@rm fdf
	@echo "\033[036m=>	\033[0m\033[031mRemove executable\033[0m"

re : clean all
