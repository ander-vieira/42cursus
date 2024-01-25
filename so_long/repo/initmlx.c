/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initmlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:23:23 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/25 20:26:38 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_bool	load_images(void)
{
	g_sl()->img_floor = image_load(IMG_FLOOR);
	if (g_sl()->img_floor.i == NULL)
		return (print_error("Error loading floor texture"), FALSE);
	g_sl()->img_wall = image_load(IMG_WALL);
	if (g_sl()->img_wall.i == NULL)
		return (print_error("Error loading wall texture"), FALSE);
	g_sl()->img_player = image_load(IMG_PLAYER);
	if (g_sl()->img_player.i == NULL)
		return (print_error("Error loading player texture"), FALSE);
	g_sl()->img_item = image_load(IMG_ITEM);
	if (g_sl()->img_item.i == NULL)
		return (print_error("Error loading item texture"), FALSE);
	g_sl()->img_exit = image_load(IMG_EXIT);
	if (g_sl()->img_exit.i == NULL)
		return (print_error("Error loading exit texture"), FALSE);
	return (TRUE);
}

static int	close_window(void *p)
{
	(void)p;
	map_free(g_sl()->map);
	exit(EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

static int	handle_key(int keycode, void *p)
{
	(void)p;
	ft_printf(STDOUT_FILENO, "%d\n", keycode);
	if (keycode == KEY_ESC)
		exit(0);
	else if (keycode == KEY_UP || keycode == KEY_W)
		ft_printstr(STDOUT_FILENO, "MOVE UP\n");
	else if (keycode == KEY_LEFT || keycode == KEY_A)
		ft_printstr(STDOUT_FILENO, "MOVE LEFT\n");
	else if (keycode == KEY_DOWN || keycode == KEY_S)
		ft_printstr(STDOUT_FILENO, "MOVE DOWN\n");
	else if (keycode == KEY_RIGHT || keycode == KEY_D)
		ft_printstr(STDOUT_FILENO, "MOVE RIGHT\n");
	return (0);
}

void	init_mlx(void)
{
	g_sl()->mlx = mlx_init();
	if (!load_images())
		return ;
	g_sl()->win = mlx_new_window(g_sl()->mlx, g_sl()->map.d.x * TILE_WIDTH,
		g_sl()->map.d.y * TILE_HEIGHT, WIN_TITLE);
	image_draw(g_sl()->img_player, vec2_new(0, 0));
	mlx_hook(g_sl()->win, EVT_KEYDN, 0, (void *)&handle_key, NULL);
	mlx_hook(g_sl()->win, EVT_DSTRY, 0, (void *)&close_window, NULL);
	mlx_loop(g_sl()->mlx);
}
