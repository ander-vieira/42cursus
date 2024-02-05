# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/04 18:27:14 by andeviei          #+#    #+#              #
#    Updated: 2024/02/05 16:34:12 by andeviei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -framework OpenGL -framework AppKit

SRCS = so_long.c end_game.c error.c initmlx.c load_images.c map.c map2.c map3.c read_map.c validate_map.c
HDRS = so_long.h

SRCS_BONUS = so_long_bonus.c do_turn_bonus.c end_game_bonus.c error_bonus.c get_frame_bonus.c initmlx_bonus.c load_images_bonus.c \
map_bonus.c map2_bonus.c map3_bonus.c moves_bonus.c read_map_bonus.c validate_map_bonus.c
HDRS_BONUS = so_long_bonus.h

LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a

MLX_DIR = mlx/
MLX = $(MLX_DIR)libmlx.a

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(SRCS) $(HDRS)
	gcc $(CFLAGS) $(MLXFLAGS) $(SRCS) $(LIBFT) $(MLX) -o $(NAME)

bonus: $(LIBFT) $(MLX) $(SRCS_BONUS) $(HDRS_BONUS)
	gcc $(CFLAGS) $(MLXFLAGS) $(SRCS_BONUS) $(LIBFT) $(MLX) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR) all clean

$(MLX):
	make -C $(MLX_DIR) all

clean:
	make -C $(LIBFT_DIR) fclean
	make -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)

re: fclean all

norm:
	norminette $(LIBFT_DIR) $(SRCS) $(SRCS_BONUS) $(HDRS) $(HDRS_BONUS)

.PHONY: all clean fclean re bonus