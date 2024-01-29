/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:27:22 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/29 18:06:40 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	map_duplicate(t_map map)
{
	t_map	result;

	result.d = map.d;
	map_alloc(&result);
	if (result.t != NULL)
		ft_memcpy(result.t, map.t, result.d.x * result.d.y);
	return (result);
}

t_bool	map_find(t_map map, t_vec2 *pos, char c)
{
	t_vec2	p;

	p.y = 0;
	while (p.y < map.d.y)
	{
		p.x = 0;
		while (p.x < map.d.x)
		{
			if (map_gettile(map, p) == c)
			{
				if (pos != NULL)
					*pos = p;
				return (TRUE);
			}
			p.x++;
		}
		p.y++;
	}
	return (FALSE);
}

void	map_flood(t_map map, t_vec2 pos)
{
	char	tile;

	tile = map_gettile(map, pos);
	if (tile != TILE_FLOOR && tile != TILE_PLAYER
		&& tile != TILE_ITEM && tile != TILE_EXIT)
		return ;
	map_settile(map, pos, TILE_FLOOD);
	if (pos.x > 0)
		map_flood(map, vec2_move(pos, -1, 0));
	if (pos.x < map.d.x - 1)
		map_flood(map, vec2_move(pos, 1, 0));
	if (pos.y > 0)
		map_flood(map, vec2_move(pos, 0, -1));
	if (pos.y < map.d.y - 1)
		map_flood(map, vec2_move(pos, 0, 1));
}

size_t	map_countedges(t_map map, char c)
{
	int		i;
	size_t	count;

	count = 0;
	i = 0;
	while (i < map.d.x)
	{
		if (map_gettile(map, vec2_new(i, 0)) == c)
			count++;
		if (map_gettile(map, vec2_new(i, map.d.y - 1)) == c)
			count++;
		i++;
	}
	i = 0;
	while (i < map.d.y)
	{
		if (map_gettile(map, vec2_new(0, i)) == c)
			count++;
		if (map_gettile(map, vec2_new(map.d.x - 1, i)) == c)
			count++;
		i++;
	}
	return (count);
}

void	map_free(t_map map)
{
	free(map.t);
}
