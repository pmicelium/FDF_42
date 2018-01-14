# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/14 02:47:46 by pmiceli           #+#    #+#              #
#    Updated: 2018/01/14 03:57:04 by pmiceli          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCDIR = ./srcs/
SRCNAMES = $(shell ls $(SRCDIR) | grep -E ".+\.c")
SRC = $(addprefix $(SRCDIR), $(SRCNAMES))
INC = ./includes/
OBJS_DIR = ./objs/
OBJS = $(addprefix $(OBJS_DIR), $(SRCNAMES:.c=.o))

LIBFT_DIR = ./libft/
LIBFT = ./libft/libft.a
MLX = ./minilibx_macos/libmlx.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra
MLX_FLAGS = -framework OpenGL -framework AppKit

all: $(OBJS_DIR) $(LIBFT) $(MLX) $(NAME)

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)%.o:$(SRCDIR)%.c
	@echo "\033[036m=>	\033[034mCreating 		$<\033[0m"
	@$(CC) $(CFLAGS) -I$(INC) -o $@ -c $<

$(NAME): $(OBJS)
	@echo "\033[036m=>	\033[035mCreating FDF's executable\033[0m"
	@$(CC) $(CFLAGS) $(MLX_FLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(MLX)
	@echo "\033[036m=>	\033[032mDONE !\033[0m"

$(LIBFT):
	@make -C $(LIBFT_DIR)
	@echo "\033[036m=>	\033[033mCompiling FDF ...\033[0m"
	@echo "\033[036m=>	\033[033mCreating FDF's objetcs\033[0m"

clean:
	@echo "\033[036m=>	\033[031mRemouve FDF's objects\033[0m"
	@rm -rf $(OBJS_DIR)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@echo "\033[036m=>	\033[031mRemouve FDF's executable\033[0m"
	@rm -rf $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all fclean clean re
