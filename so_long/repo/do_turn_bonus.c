/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_turn_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 18:15:19 by andeviei          #+#    #+#             */
/*   Updated: 2024/02/03 19:33:27 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	do_turn(int x, int y)
{
	static t_uint	moves;

	if (!map_moveplayer(g_sl()->map, x, y))
		return ;
	if (map_count(g_sl()->map, TILE_ITEM) == 0
		&& map_find(g_sl()->map, NULL, TILE_EPLAYER))
		end_game(END_WIN);
	map_moveenemy(g_sl()->map);
	moves += 1;
	ft_printf(STDOUT_FILENO,
		"YOU HAVE MOVED %d TIMES... WHY NOT GIVE UP NOW?\n", moves);
}
