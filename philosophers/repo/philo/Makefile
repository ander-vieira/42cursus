# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/01 22:26:20 by andeviei          #+#    #+#              #
#    Updated: 2024/09/15 20:28:05 by andeviei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CFLAGS = -Wall -Wextra -Werror

SRCS = philo.c error.c parsenum.c print_msg.c sim_fork.c sim_free.c sim_init.c time.c
HDRS = philo.h

all: $(NAME)

$(NAME): $(SRCS) $(HDRS)
	gcc $(CFLAGS) $(SRCS) -o $(NAME)

clean:

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re