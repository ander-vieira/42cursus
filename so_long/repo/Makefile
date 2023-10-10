# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andeviei <andeviei@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/10 12:31:30 by andeviei          #+#    #+#              #
#    Updated: 2023/10/10 12:31:30 by andeviei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CFLAGS = -Wall -Wextra -Werror

SRCS = parse_game.c point.c print.c so_long.c str.c
HDRS = so_long.h

all: $(NAME)

$(NAME): $(SRCS) $(HDRS)
	gcc $(CFLAGS) $(SRCS) -o $(NAME)

clean:

fclean: clean
	rm -f $(NAME)

re: fclean all

#bonus: $(SRCS_BONUS) $(HDRS_BONUS)
#	gcc $(CFLAGS) $(SRCS_BONUS) -o $(NAME)

.PHONY: all clean fclean re bonus