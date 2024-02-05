/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_turn_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 18:15:19 by andeviei          #+#    #+#             */
/*   Updated: 2024/02/05 15:26:41 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static t_vec2	move_vec2(t_move move)
{
	if (move == MOVE_LEFT)
		return ((t_vec2){-1, 0});
	else if (move == MOVE_RIGHT)
		return ((t_vec2){1, 0});
	else if (move == MOVE_UP)
		return ((t_vec2){0, -1});
	else if (move == MOVE_DOWN)
		return ((t_vec2){0, 1});
	else
		return ((t_vec2){0, 0});
}

static void	add_enemy_move(char tile, t_move move, t_move *moves, t_uint *n)
{
	if (tile != TILE_WALL && tile != TILE_ITEM && tile != TILE_EXIT)
	{
		moves[*n] = move;
		(*n)++;
	}
}

static t_move	get_enemy_move(t_map map)
{
	t_vec2	pos;
	t_move	moves[4];
	t_uint	moves_num;

	if (!map_find(map, &pos, TILE_ENEMY))
		return (0);
	moves_num = 0;
	add_enemy_move(map_gettile(map, (t_vec2){pos.x - 1, pos.y}),
		MOVE_LEFT, moves, &moves_num);
	add_enemy_move(map_gettile(map, (t_vec2){pos.x + 1, pos.y}),
		MOVE_RIGHT, moves, &moves_num);
	add_enemy_move(map_gettile(map, (t_vec2){pos.x, pos.y - 1}),
		MOVE_UP, moves, &moves_num);
	add_enemy_move(map_gettile(map, (t_vec2){pos.x, pos.y + 1}),
		MOVE_DOWN, moves, &moves_num);
	if (moves_num == 0)
		return (MOVE_NONE);
	return (moves[rand() % moves_num]);
}

void	do_turn(t_move move)
{
	if (!map_moveplayer(g_sl()->map, move_vec2(move)))
		return ;
	if (map_count(g_sl()->map, TILE_ITEM) == 0
		&& map_find(g_sl()->map, NULL, TILE_EPLAYER))
		end_game(END_WIN);
	map_moveenemy(g_sl()->map, move_vec2(get_enemy_move(g_sl()->map)));
	increment_moves();
	ft_printf(STDOUT_FILENO,
		"YOU HAVE MOVED %d TIMES... WHY NOT GIVE UP NOW?\n", get_moves());
}
