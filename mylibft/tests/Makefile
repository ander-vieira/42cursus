# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/24 18:58:01 by andeviei          #+#    #+#              #
#    Updated: 2024/01/10 18:33:28 by andeviei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror

NAME = tester

SRC = tester.c tester_utils.c test_misc.c test_str1.c test_str2.c test_str3.c \
test_str4.c test_read.c test_print.c test_printf.c test_path.c
HDR = tester.h

LIBFT_DIR = ../libft/
LIBFT =$(LIBFT_DIR)libft.a

all: $(NAME)

$(NAME): $(SRC) $(HDR) $(LIBFT)
	gcc $(CFLAGS) $(SRC) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR) all clean

clean:
	make -C $(LIBFT_DIR) fclean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re