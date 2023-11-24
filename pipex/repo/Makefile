# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 17:01:44 by andeviei          #+#    #+#              #
#    Updated: 2023/11/24 19:26:35 by andeviei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CFLAGS = -Wall -Wextra -Werror

SRCS = pipex.c error.c getargv.c getpath.c heredoc.c initpipex.c runcmd.c str.c
HDRS = pipex.h bool.h

all: $(NAME)

$(NAME): $(SRCS) $(HDRS)
	gcc $(CFLAGS) $(SRCS) -o $(NAME)

bonus: $(SRCS) $(HDRS)
	gcc $(CFLAGS) $(SRCS) -o $(NAME)

clean:

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus