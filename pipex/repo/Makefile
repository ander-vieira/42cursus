# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 17:01:44 by andeviei          #+#    #+#              #
#    Updated: 2023/11/25 00:23:19 by andeviei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CFLAGS = -Wall -Wextra -Werror

SRCS = pipex.c error.c getargv.c getpath.c initpipex.c runcmd.c
HDRS = pipex.h

SRCS_BONUS = pipex_bonus.c error_bonus.c getargv_bonus.c getpath_bonus.c heredoc_bonus.c initpipex_bonus.c runcmd_bonus.c
HDRS_BONUS = pipex_bonus.h

LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a

all: $(NAME)

$(NAME): $(SRCS) $(HDRS) $(LIBFT)
	gcc $(CFLAGS) $(SRCS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR) all clean

bonus: $(SRCS_BONUS) $(HDRS_BONUS) $(LIBFT)
	gcc $(CFLAGS) $(SRCS_BONUS) $(LIBFT) -o $(NAME)

clean:
	make -C $(LIBFT_DIR) fclean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus