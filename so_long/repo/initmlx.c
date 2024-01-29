/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initmlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:23:23 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/29 18:09:24 by andeviei         ###   ########.fr       */
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
		return (print_error("Error loading exit texture 1"), FALSE);
	g_sl()->img_exit_active = image_load(IMG_EXIT_ACTIVE);
	if (g_sl()->img_exit_active.i == NULL)
		return (print_error("Error loading exit texture 2"), FALSE);
	return (TRUE);
}

static int	draw_map(void *p)
{
	t_vec2	pos;

	(void)p;
	pos.y = 0;
	while (pos.y < g_sl()->map.d.y)
	{
		pos.x = 0;
		while (pos.x < g_sl()->map.d.x)
		{
			map_drawtile(g_sl()->map, pos);
			pos.x++;
		}
		pos.y++;
	}
	return (0);
}

static int	handle_key(int keycode, void *p)
{
	(void)p;
	if (keycode == KEY_ESC)
		exit(0);
	else if (keycode == KEY_UP || keycode == KEY_W)
		map_moveplayer(g_sl()->map, 0, -1);
	else if (keycode == KEY_LEFT || keycode == KEY_A)
		map_moveplayer(g_sl()->map, -1, 0);
	else if (keycode == KEY_DOWN || keycode == KEY_S)
		map_moveplayer(g_sl()->map, 0, 1);
	else if (keycode == KEY_RIGHT || keycode == KEY_D)
		map_moveplayer(g_sl()->map, 1, 0);
	if (map_count(g_sl()->map, TILE_ITEM) == 0
		&& map_find(g_sl()->map, NULL, TILE_EPLAYER))
		exit(0);
	return (EXIT_SUCCESS);
}

static int	close_window(void *p)
{
	(void)p;
	map_free(g_sl()->map);
	exit(EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

void	init_mlx(void)
{
	g_sl()->moves = 0;
	g_sl()->mlx = mlx_init();
	if (!load_images())
		return ;
	g_sl()->win = mlx_new_window(g_sl()->mlx, g_sl()->map.d.x * TILE_WIDTH,
		g_sl()->map.d.y * TILE_HEIGHT, WIN_TITLE);
	image_draw(g_sl()->img_player, vec2_new(0, 0));
	mlx_loop_hook(g_sl()->mlx, &draw_map, NULL);
	mlx_hook(g_sl()->win, EVT_KEYDN, 0, (void *)&handle_key, NULL);
	mlx_hook(g_sl()->win, EVT_DSTRY, 0, (void *)&close_window, NULL);
	mlx_loop(g_sl()->mlx);
}
