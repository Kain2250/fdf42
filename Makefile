# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bdrinkin <bdrinkin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/17 20:07:40 by bdrinkin          #+#    #+#              #
#    Updated: 2020/02/11 17:44:46 by bdrinkin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc
FLAGS = -Wall -Wextra -O3
LIBRARIES_MAC = -lmlx -lm -lft -L$(LIBFT_DIRECTORY) -L$(MINILIBX_DIRECTORY) -framework OpenGL -framework AppKit
LIBRARIES_UBUNTU = -lm -lft -L$(LIBFT_DIRECTORY) -L /usr/X11/lib /usr/X11/lib/libmlx.a -lXext -lX11

HEADERS = -I $(INCLUDES_DIRECTORY)
LIBFT = $(LIBFT_DIRECTORY)libft.a
LIBFT_DIRECTORY = libft/

INCLUDES_DIRECTORY = includes/
INCLUDES_LIST = fdf.h

SRC_DIRECTORY = src/
SRC_LIST = bonus_hook_list.c\
	bonus.c\
	change.c\
	cheker.c\
	colors.c\
	crutch.c\
	go_list.c\
	help_ft.c\
	hook_list.c\
	init.c\
	key_hot_list.c\
	main.c\
	output_map.c\
	read_file.c
	
SRC = $(addprefix $(SRC_DIRECTORY), $(SRC_LIST))

MINILIBX_DIRECTORY = /usr/local/lib/

GREEN = \033[0;32;1m
RED = \033[0;31;1m
RESET = \033[0m

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBFT)
	@$(CC) $(FLAGS) $(SRC) -o $(NAME) $(LIBRARIES_MAC) $(HEADERS)
	@echo "\n$(NAME): $(GREEN)Создание исполняемого файла$(RESET)"
	@echo "$(NAME): $(GREEN)$(NAME) Готово$(RESET)"

$(LIBFT):
	@echo "$(NAME): $(GREEN)Создание $(LIBFT)...$(RESET)"
	@$(MAKE) -sC $(LIBFT_DIRECTORY)

clean:
	@make -sC $(LIBFT_DIRECTORY) clean

fclean: clean
	@rm -f $(LIBFT)
	@echo "$(NAME): $(RED)$(LIBFT) было удалено$(RESET)"
	@rm -f $(NAME)
	@echo "$(NAME): $(RED)$(NAME) было удалено$(RESET)"


re: fclean all