/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:49:19 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/25 17:23:39 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_print(void)
{
	t_vec2	pos;

	pos.y = 0;
	while (pos.y < g_sl()->dims.y)
	{
		pos.x = 0;
		while (pos.x < g_sl()->dims.x)
		{
			ft_printchar(STDOUT_FILENO, tile_get(pos));
			pos.x++;
		}
		ft_printchar(STDOUT_FILENO, '\n');
		pos.y++;
	}
}

size_t	map_count(char c)
{
	size_t	count;
	t_vec2	pos;

	count = 0;
	pos.y = 0;
	while (pos.y < g_sl()->dims.y)
	{
		pos.x = 0;
		while (pos.x < g_sl()->dims.x)
		{
			if (tile_get(pos) == c)
				count++;
			pos.x++;
		}
		pos.y++;
	}
	return (count);
}
