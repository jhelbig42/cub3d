# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhelbig <jhelbig@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/07 14:46:57 by jhelbig           #+#    #+#              #
#    Updated: 2025/07/25 14:42:44 by jhelbig          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

SRC_DIR = src
OBJ_DIR = build
INC_DIR = includes

CFILES		:=
vpath %.c $(SRC_FOLDER)
CFILES += main.cpp

SRC		:=
SRC += $(SRC_DIR)/main.c
SRC += $(SRC_DIR)/destroy.c
SRC += $(SRC_DIR)/keypress.c

SRC += $(SRC_DIR)/parser/parser.c
SRC += $(SRC_DIR)/parser/find_colors.c 
SRC += $(SRC_DIR)/parser/find_paths.c
SRC += $(SRC_DIR)/parser/map_arr.c
SRC += $(SRC_DIR)/parser/utils.c

SRC += $(SRC_DIR)/utils/free.c
SRC += $(SRC_DIR)/utils/error.c 

SRC += $(SRC_DIR)/init/init.c

SRC += $(SRC_DIR)/render/render.c
SRC += $(SRC_DIR)/render/create_graphics.c

OBJ := $(patsubst src/%.c, build/%.o, $(SRC))

HEADERS = $(SRC_DIR)/$(INC_DIR)/cube.h 
HEADERS = $(SRC_DIR)/$(INC_DIR)/CONSTANTS.h 
HEADERS = $(SRC_DIR)/$(INC_DIR)/structs.h
HEADERS = $(SRC_DIR)/init/init.h 
HEADERS = $(SRC_DIR)/parser/parser.h 

LIBFT_DIR = libft
LIBFT_A = $(LIBFT_DIR)/libft.a

MINILIBX_DIR = minilibx-linux

CC = clang

CFLAGS = -g -Wall -Wextra -Werror

MAKEALL = make all
MAKECLEAN = make clean
MAKEFCLEAN = make fclean

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OBJ) $(HEADERS) $(LIBFT_A)
	$(MAKEALL) -C $(MINILIBX_DIR)
	$(CC) $(OBJ) $(LIBFT_A) -Lminilibx-linux -l:libmlx_Linux.a -L/usr/local/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
	
${LIBFT_A}:
	$(MAKEALL) -C $(LIBFT_DIR)
	
debug: 
	gdb --args ./cub3d test

clean: 
	$(MAKECLEAN) -C $(LIBFT_DIR)
	$(MAKECLEAN) -C $(MINILIBX_DIR)
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(OBJ_DIR)
	rm -rf $(LIBFT_A)
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
