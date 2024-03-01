# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/04 18:27:14 by andeviei          #+#    #+#              #
#    Updated: 2024/03/01 14:22:59 by andeviei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker

CFLAGS = -Wall -Wextra -Werror

SRCS = push_swap.c algo.c algo_any.c algo_five.c algo_three.c algo_two.c cmp.c op.c oper.c oper2.c pick_algo.c read_args.c stack.c stack2.c stack3.c stack4.c target.c wrap.c
HDRS = push_swap.h

SRCS_BONUS = checker_bonus.c op_bonus.c read_args_bonus.c stack_bonus.c stack2_bonus.c stack3_bonus.c wrap_bonus.c
HDRS_BONUS = checker_bonus.h

LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(SRCS) $(HDRS)
	gcc $(CFLAGS) $(SRCS) $(LIBFT) -o $(NAME)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(LIBFT) $(SRCS_BONUS) $(HDRS_BONUS)
	gcc $(CFLAGS) $(SRCS_BONUS) $(LIBFT) -o $(NAME_BONUS)

$(LIBFT):
	make -C $(LIBFT_DIR) all clean

clean:
	make -C $(LIBFT_DIR) fclean

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re