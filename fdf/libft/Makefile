# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 14:44:04 by pmiceli           #+#    #+#              #
#    Updated: 2017/12/03 17:18:12 by pmiceli          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_putchar.c\
	   ft_putstr.c\
	   ft_strcmp.c\
	   ft_putnbr_endl.c\
	   ft_strlen.c\
	   ft_atoi.c\
	   ft_putnbr.c\
	   ft_strcat.c\
	   ft_putendl_background.c\
	   ft_strchr_rev.c\
	   ft_putendl_color.c\
	   ft_putstr_background.c\
	   ft_putstr_color.c\
	   ft_strjoin_free.c\
	   ft_strcpy.c\
	   ft_atoi_tab.c\
	   ft_strdup.c\
	   ft_strncat.c\
	   ft_strncmp.c\
	   ft_strncpy.c\
	   ft_swap_char.c\
	   ft_swap_nbr.c\
	   ft_isalnum.c\
	   ft_isalpha.c\
	   ft_isascii.c\
	   ft_isdigit.c\
	   ft_isprint.c\
	   ft_strstr.c\
	   ft_tolower.c\
	   ft_toupper.c\
	   ft_strchr.c\
	   ft_strrchr.c\
	   ft_bzero.c\
	   ft_memset.c\
	   ft_free_tab.c\
	   ft_strlcat.c\
	   ft_memcpy.c\
	   ft_memccpy.c\
	   ft_memchr.c\
	   ft_memcmp.c\
	   ft_memmove.c\
	   ft_intlen.c\
	   ft_itoa.c\
	   ft_memdel.c\
	   ft_memalloc.c\
	   ft_putchar_fd.c\
	   ft_putendl.c\
	   ft_putendl_fd.c\
	   ft_printlst_char.c\
	   ft_strtrim.c\
	   ft_strsub.c\
	   get_next_line.c\
	   ft_strsplit.c\
	   ft_strequ.c\
	   ft_strnew.c\
	   ft_strnequ.c\
	   ft_strmapi.c\
	   ft_strmap.c\
	   ft_striteri.c\
	   ft_strjoin.c\
	   ft_striter.c\
	   ft_strdel.c\
	   ft_strclr.c\
	   ft_putstr_fd.c\
	   ft_putnbr_fd.c\
	   ft_printtab_char.c\
	   ft_printtab_int.c\
	   ft_lstnew.c\
	   ft_lstadd.c\
	   ft_lstmap.c\
	   ft_lstiter.c\
	   ft_lstdel.c\
	   ft_lstdelone.c\
	   ft_strnstr.c\

OBJS = $(subst .c,.o,$(SRCS))

all : $(NAME)

$(NAME):
	@gcc -Wall -Wextra -Werror -c $(SRCS)
	@echo "\033[036m=>	\033[0m\033[032mObject created\033[0m"
	@ar rc $(NAME) $(OBJS)
	@mkdir objets
	@mv $(OBJS) objets
	@ranlib $(NAME)
	@echo "\033[036m=>	\033[0m\033[032mLib created\033[0m"

clean :
	@rm -rf objets
	@echo "\033[36m=>	\033[0m\033[31mObjets removed\033[0m"

fclean : clean
	@rm -rf $(NAME)
	@echo "\033[036m=>	\033[0m\033[31mLib removed"

re : fclean all

.PHONY : all clean fclean re
