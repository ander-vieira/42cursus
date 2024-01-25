/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:49:19 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/25 17:47:56 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	map_gettile(t_map map, t_vec2 pos)
{
	if (pos.x > map.d.x || pos.y > map.d.y)
		return ('\0');
	return (map.t[map.d.x * pos.y + pos.x]);
}

void	map_settile(t_map map, t_vec2 pos, char c)
{
	if (pos.x > map.d.x || pos.y > map.d.y)
		return ;
	map.t[map.d.x * pos.y + pos.x] = c;
}

void	map_print(t_map map)
{
	t_vec2	pos;

	pos.y = 0;
	while (pos.y < g_sl()->map.d.y)
	{
		pos.x = 0;
		while (pos.x < g_sl()->map.d.x)
		{
			ft_printchar(STDOUT_FILENO, map_gettile(map, pos));
			pos.x++;
		}
		ft_printchar(STDOUT_FILENO, '\n');
		pos.y++;
	}
}

size_t	map_count(t_map map, char c)
{
	size_t	count;
	t_vec2	pos;

	count = 0;
	pos.y = 0;
	while (pos.y < map.d.y)
	{
		pos.x = 0;
		while (pos.x < map.d.x)
		{
			if (map_gettile(map, pos) == c)
				count++;
			pos.x++;
		}
		pos.y++;
	}
	return (count);
}

void	map_alloc(t_map *map)
{
	map->t = (char *)malloc(sizeof(char) * map->d.x * map->d.y);
}
