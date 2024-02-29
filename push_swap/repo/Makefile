# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/04 18:27:14 by andeviei          #+#    #+#              #
#    Updated: 2024/02/29 20:08:15 by andeviei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CFLAGS = -Wall -Wextra -Werror

SRCS = push_swap.c algo.c aries.c op.c oper.c oper2.c orion.c pick_algo.c read_args.c stack.c stack2.c stack3.c stack4.c ursa.c wrap.c
HDRS = push_swap.h

LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(SRCS) $(HDRS)
	gcc $(CFLAGS) $(SRCS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR) all clean

clean:
	make -C $(LIBFT_DIR) fclean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re