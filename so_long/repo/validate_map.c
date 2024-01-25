/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:45:05 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/25 19:15:28 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_bool	validate_dims(void)
{
	if (g_sl()->map.d.x < 3 || g_sl()->map.d.y < 3)
		return (print_error("The map is too small"), FALSE);
	return (TRUE);
}

static t_bool	no_bad_tiles(void)
{
	t_vec2	pos;
	char	tile;

	pos.y = 0;
	while (pos.y < g_sl()->map.d.y)
	{
		pos.x = 0;
		while (pos.x < g_sl()->map.d.x)
		{
			tile = map_gettile(g_sl()->map, pos);
			if (tile != TILE_FLOOR && tile != TILE_WALL && tile != TILE_PLAYER
				&& tile != TILE_ITEM && tile != TILE_EXIT)
				return (print_error("Map contains invalid tiles"), FALSE);
			pos.x++;
		}
		pos.y++;
	}
	return (TRUE);
}

static t_bool	count_tiles(void)
{
	if (map_count(g_sl()->map, TILE_PLAYER) != 1)
		return (print_error("Map must contain exactly one player"), FALSE);
	if (map_count(g_sl()->map, TILE_EXIT) != 1)
		return (print_error("Map must contain exactly one exit"), FALSE);
	if (map_count(g_sl()->map, TILE_ITEM) == 0)
		return (print_error("Map must contain at least one item"), FALSE);
	return (TRUE);
}

static t_bool	validate_path(void)
{
	t_map	map;

	map = map_duplicate(g_sl()->map);
	if (map.t == NULL)
		return (print_error(NULL), FALSE);
	map_flood(map, map_find(map, TILE_PLAYER));
	if (map_count(map, TILE_ITEM) != 0)
		return (map_free(map),
			print_error("There is no valid path to all items"), FALSE);
	if (map_count(map, TILE_EXIT) != 0)
		return (map_free(map),
			print_error("There is no valid path to the exit"), FALSE);
	if (map_countedges(map, TILE_FLOOD) != 0)
		return (map_free(map),
			print_error("The map isn't enclosed in walls"), FALSE);
	return (map_free(map), TRUE);
}

t_bool	validate_map(void)
{
	return (validate_dims()
		&& no_bad_tiles()
		&& count_tiles()
		&& validate_path());
}
