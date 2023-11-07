# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 17:01:44 by andeviei          #+#    #+#              #
#    Updated: 2023/11/07 18:42:50 by andeviei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CFLAGS = -Wall -Wextra -Werror

SRCS = pipex.c command.c error.c print.c str.c
HDRS = pipex.h

all: $(NAME)

$(NAME): $(SRCS) $(HDRS)
	gcc $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re