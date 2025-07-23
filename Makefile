# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhelbig <jhelbig@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/07 14:46:57 by jhelbig           #+#    #+#              #
#    Updated: 2025/07/10 11:20:27 by jhelbig          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = cub3d

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = inc

SRC = main.c
	
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

HEADERS = 

LIBFT_DIR = libft
LIBFT_A = $(LIBFT_DIR)/libft.a

CC = cc

CFLAGS = -g -Wall -Wextra -Werror

MAKEALL = make all
MAKECLEAN = make clean
MAKEFCLEAN = make fclean

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ) $(HEADERS) $(LIBFT_A)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT_A) -o $(NAME)
	
${LIBFT_A}:
	$(MAKEALL) -C $(LIBFT_DIR)
	
clean: 
	$(MAKECLEAN) -C $(LIBFT_DIR)
	rm -f $(OBJ)

fclean: clean
	rm -r $(OBJ_DIR)
	rm $(LIBFT_A)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
