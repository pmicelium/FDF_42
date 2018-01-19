# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/14 02:47:46 by pmiceli           #+#    #+#              #
#    Updated: 2018/01/19 22:15:16 by pmiceli          ###   ########.fr        #
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
MLX_DIR = ./minilibx_macos/
MLX = ./minilibx_macos/libmlx.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra
MLX_FLAGS = -framework OpenGL -framework AppKit

PRINT = "make[1]: Nothing to be done for 'all'"

all: $(OBJS_DIR) print_lib LIBFT print_mlx MLX print_fdf $(NAME) print_done

print_fdf :
	@echo "\033[033m➼	\033[033mCompiling FDF ...\033[0m"
	@echo "\033[033m➼	\033[033mCreating FDF's objetcs\033[0m"

print_lib :
	@echo "\033[033m➼	\033[033mCompiling Libft ...\033[0m"
	@echo "\033[033m➼	\033[033mCreating Libft's objetcs\033[0m"

print_mlx :
	@echo "\033[033m➼	\033[033mCompiling MLX ...\033[0m"
	@echo "\033[033m➼	\033[033mCreating MLX's objetcs\033[0m"

print_done :
	@echo $(PRINT)

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)%.o:$(SRCDIR)%.c
	@echo "\033[038;2;255;153;0m⧖	Creating 	$@\033[0m"
	@$(CC) $(CFLAGS) -I$(INC) -o $@ -c $<

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	@echo "\033[033m➼	\033[033mCreating FDF's executable\033[0m"
	@$(CC) $(CFLAGS) $(MLX_FLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(MLX)
	$(eval PRINT ="\033[032m✓	\033[032mDONE !\033[0m")
	@echo "================================================================="

LIBFT:
	@make -C $(LIBFT_DIR)

MLX:
	@make -C $(MLX_DIR)

clean:
	@rm -rf $(OBJS_DIR)
	@make -C $(LIBFT_DIR) clean
	@make -C $(MLX_DIR) clean
	@echo "❌	\033[031mRemouve FDF's objects\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@echo "❌	\033[031mRemouve FDF's executable\033[0m"

re: fclean all

ret : clean test

.PHONY: all fclean clean re MLX LIBFT print_fdf print_mlx print_done\
	print_lib
