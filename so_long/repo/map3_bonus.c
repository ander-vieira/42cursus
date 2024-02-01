/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map3_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:29:36 by andeviei          #+#    #+#             */
/*   Updated: 2024/02/01 16:27:51 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	draw_image(t_image img, t_vec2 pos)
{
	mlx_put_image_to_window(g_sl()->mlx, g_sl()->win, img.i,
		pos.x * TILE_WIDTH, pos.y * TILE_HEIGHT);
}

static void	draw_anim(t_anim anim, t_vec2 pos, t_uint frame)
{
	mlx_put_image_to_window(g_sl()->mlx, g_sl()->win,
		anim.i[frame * anim.n / FPS].i,
		pos.x * TILE_WIDTH, pos.y * TILE_HEIGHT);
}

void	map_drawtile(t_map map, t_vec2 pos, t_uint frame)
{
	char	c;

	c = map_gettile(map, pos);
	if (c == TILE_FLOOR || c == TILE_PLAYER || c == TILE_EPLAYER
		|| c == TILE_ITEM || c == TILE_EXIT)
		draw_image(g_sl()->img_floor, pos);
	if (c == TILE_WALL)
		draw_image(g_sl()->img_wall, pos);
	if (c == TILE_EXIT || c == TILE_EPLAYER)
	{
		if (map_count(map, TILE_ITEM) == 0)
			draw_image(g_sl()->img_exit[1], pos);
		else
			draw_image(g_sl()->img_exit[0], pos);
	}
	if (c == TILE_ITEM)
		draw_anim(g_sl()->anim_item, pos, frame);
	if (c == TILE_PLAYER || c == TILE_EPLAYER)
		draw_anim(g_sl()->anim_player, pos, frame);
}

void	map_moveplayer(t_map map, int x, int y)
{
	t_vec2	pos_old;
	t_vec2	pos_new;

	if (!map_find(map, &pos_old, TILE_PLAYER))
		map_find(map, &pos_old, TILE_EPLAYER);
	pos_new = (t_vec2){pos_old.x + x, pos_old.y + y};
	if (map_gettile(map, pos_new) == TILE_WALL)
		return ;
	if (map_gettile(map, pos_new) == TILE_EXIT)
		map_settile(map, pos_new, TILE_EPLAYER);
	else
		map_settile(map, pos_new, TILE_PLAYER);
	if (map_gettile(map, pos_old) == TILE_EPLAYER)
		map_settile(map, pos_old, TILE_EXIT);
	else
		map_settile(map, pos_old, TILE_FLOOR);
	g_sl()->moves += 1;
	ft_printf(STDOUT_FILENO,
		"YOU HAVE MOVED %d TIMES... WHY NOT GIVE UP NOW?\n", g_sl()->moves);
}
