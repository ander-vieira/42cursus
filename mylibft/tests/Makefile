# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/24 18:58:01 by andeviei          #+#    #+#              #
#    Updated: 2023/12/05 16:59:42 by andeviei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror

NAME = tester

SRC = tester.c tester_utils.c test_misc.c test_str1.c test_str2.c test_str3.c \
test_gnl.c
HDR = tester.h

BASENAME_NAME = basename_tester
BASENAME_SRCS = basename_test.c

DIRNAME_NAME = dirname_tester
DIRNAME_SRCS = dirname_test.c

PARSENUM_NAME = parsenum_tester
PARSENUM_SRCS = parsenum_test.c

PRINTF_NAME = printf_tester
PRINTF_SRCS = printf_test.c

LIBFT_DIR = ../libft/
LIBFT =$(LIBFT_DIR)libft.a

all: $(NAME) $(BASENAME_NAME) $(DIRNAME_NAME) $(PARSENUM_NAME) $(PRINTF_NAME)

$(NAME): $(SRC) $(HDR) $(LIBFT)
	gcc $(CFLAGS) $(SRC) $(LIBFT) -o $(NAME)

$(BASENAME_NAME): $(BASENAME_SRCS) $(LIBFT)
	gcc $(CFLAGS) $(BASENAME_SRCS) $(LIBFT) -o $(BASENAME_NAME)

$(DIRNAME_NAME): $(DIRNAME_SRCS) $(LIBFT)
	gcc $(CFLAGS) $(DIRNAME_SRCS) $(LIBFT) -o $(DIRNAME_NAME)
	
$(PARSENUM_NAME): $(PARSENUM_SRCS) $(LIBFT)
	gcc $(CFLAGS) $(PARSENUM_SRCS) $(LIBFT) -o $(PARSENUM_NAME)

$(PRINTF_NAME): $(PRINTF_SRCS) $(LIBFT)
	gcc $(CFLAGS) $(PRINTF_SRCS) $(LIBFT) -o $(PRINTF_NAME)

$(LIBFT):
	make -C $(LIBFT_DIR) all clean

clean:
	make -C $(LIBFT_DIR) fclean

fclean: clean
	rm -f $(NAME) $(BASENAME_NAME) $(DIRNAME_NAME) $(PARSENUM_NAME) $(PRINTF_NAME)

re: fclean all

.PHONY: all clean fclean re