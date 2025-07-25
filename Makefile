# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhelbig <jhelbig@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/07 14:46:57 by jhelbig           #+#    #+#              #
#    Updated: 2025/07/25 10:37:47 by jhelbig          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = cub3d

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = inc

SRC = main.c \
		destroy.c \
		error.c \
		parser/find_colors.c \
		parser/find_paths.c \
		free.c \
		keypress.c \
		parser/parser.c
	
	
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

HEADERS = $(SRC_DIR)/cube.h 

LIBFT_DIR = libft
LIBFT_A = $(LIBFT_DIR)/libft.a

MINILIBX_DIR = minilibx-linux

CC = cc

CFLAGS = -g -Wall -Wextra -Werror

MAKEALL = make all
MAKECLEAN = make clean
MAKEFCLEAN = make fclean

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OBJ) $(HEADERS) $(LIBFT_A)
	$(MAKEALL) -C $(MINILIBX_DIR)
	$(CC) $(OBJ) $(LIBFT_A) -Lminilibx-linux -l:libmlx_Linux.a -L/usr/local/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
	
${LIBFT_A}:
	$(MAKEALL) -C $(LIBFT_DIR)
	
clean: 
	$(MAKECLEAN) -C $(LIBFT_DIR)
	$(MAKECLEAN) -C $(MINILIBX_DIR)
	rm -f $(OBJ)

fclean: clean
	rm -r $(OBJ_DIR)
	rm $(LIBFT_A)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
