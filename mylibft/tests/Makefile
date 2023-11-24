# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/24 18:58:01 by andeviei          #+#    #+#              #
#    Updated: 2023/11/24 19:14:43 by andeviei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = tester

CFLAGS = -Wall -Wextra -Werror

SRCS = test.c
HDRS = test.h

LIBFT_DIR = ../libft/
LIBFT =$(LIBFT_DIR)libft.a

all: $(NAME)

$(NAME): $(SRCS) $(HDRS) $(LIBFT)
	gcc $(CFLAGS) $(SRCS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR) all clean

clean:
	make -C $(LIBFT_DIR) fclean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re