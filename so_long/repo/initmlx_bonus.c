/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initmlx_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:23:23 by andeviei          #+#    #+#             */
/*   Updated: 2024/02/03 19:26:59 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	draw_map(void *p)
{
	t_uint	frame;
	t_vec2	pos;

	(void)p;
	frame = get_frame();
	pos.y = 0;
	while (pos.y < g_sl()->map.d.y)
	{
		pos.x = 0;
		while (pos.x < g_sl()->map.d.x)
		{
			map_drawtile(g_sl()->map, pos, frame);
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
		end_game(END_CLOSE);
	else if (keycode == KEY_UP || keycode == KEY_W)
		do_turn(0, -1);
	else if (keycode == KEY_LEFT || keycode == KEY_A)
		do_turn(-1, 0);
	else if (keycode == KEY_DOWN || keycode == KEY_S)
		do_turn(0, 1);
	else if (keycode == KEY_RIGHT || keycode == KEY_D)
		do_turn(1, 0);
	return (0);
}

static int	close_window(void *p)
{
	(void)p;
	end_game(END_CLOSE);
	return (EXIT_FAILURE);
}

void	init_mlx(void)
{
	g_sl()->mlx = mlx_init();
	if (!load_images())
		return ;
	g_sl()->win = mlx_new_window(g_sl()->mlx, g_sl()->map.d.x * TILE_WIDTH,
		g_sl()->map.d.y * TILE_HEIGHT, WIN_TITLE);
	mlx_loop_hook(g_sl()->mlx, &draw_map, NULL);
	mlx_hook(g_sl()->win, EVT_KEYDN, 0, (void *)&handle_key, NULL);
	mlx_hook(g_sl()->win, EVT_DSTRY, 0, (void *)&close_window, NULL);
	mlx_loop(g_sl()->mlx);
}
