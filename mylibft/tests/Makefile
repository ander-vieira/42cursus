# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/24 18:58:01 by andeviei          #+#    #+#              #
#    Updated: 2023/11/26 14:44:47 by andeviei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror

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

all: $(BASENAME_NAME) $(DIRNAME_NAME) $(PARSENUM_NAME) $(PRINTF_NAME)

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
	rm -f $(BASENAME_NAME) $(DIRNAME_NAME) $(PARSENUM_NAME) $(PRINTF_NAME)

re: fclean all

.PHONY: all clean fclean re