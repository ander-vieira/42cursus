# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/24 12:18:07 by andeviei          #+#    #+#              #
#    Updated: 2024/01/10 17:17:51 by andeviei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFLAGS = -c -Wall -Wextra -Werror

SRCS = \
error/ft_seterror.c \
misc/ft_abs.c misc/ft_isspace.c misc/ft_memcpy.c misc/ft_parsenum.c \
str/ft_strbuild.c str/ft_strchr.c str/ft_strcmp.c str/ft_strformat.c str/ft_strjoin.c str/ft_strlen.c str/ft_strnbrs.c \
str/ft_strnbru.c str/ft_strprefix.c str/ft_strrchr.c str/ft_strsub.c str/ft_strsuffix.c \
path/ft_basename.c path/ft_dirname.c path/ft_trimname.c \
read/ft_readline.c read/ft_readfull.c \
print/ft_print_addwrite.c print/ft_printchar.c print/ft_printf.c print/ft_printnbrs.c print/ft_printnbru.c print/ft_printstr.c
HDRS = libft.h
OBJS = $(patsubst %.c,%.o,$(notdir $(SRCS)))

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