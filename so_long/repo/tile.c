/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tile.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:15:45 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/25 16:53:09 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	tile_get(t_vec2 pos)
{
	return (g_sl()->map[g_sl()->dims.x * pos.y + pos.x]);
}

void	tile_set(t_vec2 pos, char c)
{
	g_sl()->map[g_sl()->dims.x * pos.y + pos.x] = c;
}
