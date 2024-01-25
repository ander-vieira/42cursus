# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/04 18:27:14 by andeviei          #+#    #+#              #
#    Updated: 2024/01/25 19:58:16 by andeviei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -framework OpenGL -framework AppKit

SRCS = so_long.c error.c image.c initmlx.c map.c map2.c read_map.c tile.c validate_args.c validate_map.c vec2.c
HDRS = so_long.h

LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a

MLX_DIR = mlx/
MLX = $(MLX_DIR)libmlx.a

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(SRCS) $(HDRS)
	gcc $(CFLAGS) $(MLXFLAGS) $(SRCS) $(LIBFT) $(MLX) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR) all clean

$(MLX):
	make -C $(MLX_DIR) all

clean:
	make -C $(LIBFT_DIR) fclean
	make -C $(MLX_DIR) clean
	rm -f $(NAME)

fclean: clean

re: fclean all

norm:
	norminette $(LIBFT_DIR) $(SRCS) $(HDRS)

.PHONY: all clean fclean re