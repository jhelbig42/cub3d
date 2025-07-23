# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhelbig <jhelbig@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/07 14:46:57 by jhelbig           #+#    #+#              #
#    Updated: 2024/11/20 13:05:26 by jhelbig          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_striteri.c ft_strmapi.c ft_putnbr_fd.c ft_putendl_fd.c ft_putstr_fd.c ft_putchar_fd.c ft_split.c ft_itoa.c ft_strdup.c ft_strtrim.c ft_strjoin.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_substr.c ft_calloc.c \
ft_print_char.c ft_printf.c ft_print_number_base.c ft_print_pointer.c ft_print_str.c \
		ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c \
		get_next_line.c \
		get_next_line_utils.c 


OBJS = $(SRC:%.c=%.o)

BONUS_OBJS = $(BONUS:%.c=%.o)

HEADERS = libft.h \
	get_next_line.h

TEST = test_libc_ft.c

UNITY = src/unity.c

CC = cc

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

${NAME}: ${OBJS} ${HEADERS}
	ar rcs $(NAME) $(OBJS)

#$< is the first depency, $@ is the target
%.o: %.c
	$(CC) $(CFLAGS) -Iincludes -c $< -o $@

bonus: $(NAME) $(BONUS_OBJS)
	ar rcs $(NAME) $(BONUS_OBJS)

clean: 
	rm -f $(OBJS) $(BONUS_OBJS)
	rm -f test

fclean: clean
	rm -f $(NAME)

re: fclean all

test: $(NAME)  ${TEST} ${OBJS} ${BONUS_OBJS}
	$(CC) $(CFLAGS) -o test $(TEST) $(UNITY) ${OBJS} ${BONUS_OBJS}
	./test

.PHONY: all clean fclean re test bonus
