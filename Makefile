# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bdrinkin <bdrinkin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/17 20:07:40 by bdrinkin          #+#    #+#              #
#    Updated: 2021/01/11 17:11:51 by bdrinkin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

BUILD_DIR := build
SRC := bonus_hook_list.c\
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

OBJ := $(SRC:%.c=$(BUILD_DIR)/%.o)
DEP := $(OBJ:%.o=%.d)

LFT_DIR := libft
LFT_LIB := -L$(LFT_DIR) -lft

ifeq ($(shell uname -s), Linux)
	MLX_DIR := minilibx_linux
	MLX_LIB := -lXext -lX11
else
	MLX_DIR := minilibx_macos
	MLX_LIB := -framework OpenGL -framework AppKit
endif
MLX_LIB += -L$(MLX_DIR) -lmlx

CC := clang

# MAKEFLAGS += -j
WFLAGS := -Wall -Wextra
WFLAGS += -Werror
# WFLAGS += -Wpedantic
# OFLAGS := -g
OFLAGS := -O3 -march=native
OFLAGS += -ffast-math
CFLAGS := $(WFLAGS) $(OFLAGS) -MMD -I$(LFT_DIR)/includes -I $(MLX_DIR) -I includes
LFLAGS := $(LFT_LIB) $(MLX_LIB) -lm

vpath %.c src

.PHONY: all clean fclean re

$(NAME): $(OBJ)
	@make -sC $(MLX_DIR) all
	@make -sC $(LFT_DIR) all
	@printf "[$(NAME)] Linking objects...\n"
	@$(CC) $(OBJ) -o $(NAME) $(LFLAGS)
	@printf "\033[32;1m[$(NAME)] Done\033[0m\n"

-include $(DEP)
$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@printf "[$(NAME)] Building object '$@'\n"
	@$(CC) $(CFLAGS) -o $@ -c $<

all: $(NAME)

clean:
	@make -sC $(MLX_DIR) clean
	@make -sC $(LFT_DIR) clean
	@rm -rf $(BUILD_DIR)

fclean: clean
	@make -sC $(LFT_DIR) fclean
	@rm -f $(NAME)

re: fclean
	@make all
