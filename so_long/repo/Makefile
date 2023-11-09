# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/04 18:27:14 by andeviei          #+#    #+#              #
#    Updated: 2023/11/09 15:41:16 by andeviei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CFLAGS = -Wall -Wextra -Werror -Imlx -Lmlx -lmlx -framework OpenGL -framework AppKit

SRCS = so_long.c display.c errors.c print.c readfile.c str.c validmap.c
HDRS = so_long.h bool.h

all: $(NAME)

$(NAME): $(SRCS) $(HDRS)
	make -C mlx/
	gcc $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	make clean -C mlx/
	rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re