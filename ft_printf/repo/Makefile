# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/19 13:40:38 by andeviei          #+#    #+#              #
#    Updated: 2023/10/19 16:56:00 by andeviei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CFLAGS = -c -Wall -Wextra -Werror

SRCS = ft_printf.c parsedirec.c printdirec.c put.c str.c
HDRS = ft_printf.h
OBJS = $(SRCS:.c=.o)
SRCS_BONUS = ft_printf_bonus.c parsedirec_bonus.c printdirec_bonus.c put_bonus.c str_bonus.c
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

$(OBJS): $(SRCS) $(HDRS)
	gcc $(CFLAGS) $(SRCS)

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(OBJS_BONUS)
	ar -rcs $(NAME) $(OBJS_BONUS)

$(OBJS_BONUS): $(SRCS_BONUS) $(HDRS)
	gcc $(CFLAGS) $(SRCS_BONUS)

.PHONY: all clean fclean re bonus