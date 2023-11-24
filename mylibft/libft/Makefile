# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/24 12:18:07 by andeviei          #+#    #+#              #
#    Updated: 2023/11/24 23:51:50 by andeviei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFLAGS = -c -Wall -Wextra -Werror

SRCS = ft_free.c ft_gnl.c ft_isspace.c ft_memcpy.c ft_parsenum.c ft_seterror.c ft_strchr.c ft_strcmp.c ft_strdup.c ft_strjoin.c \
ft_strlen.c ft_strprefix.c
HDRS = libft.h ft_error.h ft_types.h
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(OBJS): $(SRCS) $(HDRS)
	gcc $(CFLAGS) $(SRCS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re