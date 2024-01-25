/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:45:05 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/25 17:24:47 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_bool	validate_dims(void)
{
	if (g_sl()->dims.x < 3 || g_sl()->dims.y < 3)
		return (print_error("The map is too small"), FALSE);
	return (TRUE);
}

static t_bool	no_bad_tiles(void)
{
	t_vec2	pos;

	pos = vec2_new(0, 0);
	while (pos.y < g_sl()->dims.y)
	{
		while (pos.x < g_sl()->dims.x)
		{
			if (tile_get(pos) != '0' && tile_get(pos) != '1'
				&& tile_get(pos) != 'P' && tile_get(pos) != 'C'
				&& tile_get(pos) != 'E')
				return (print_error("Map contains invalid tiles"), FALSE);
			pos.x++;
		}
		pos.y++;
	}
	return (TRUE);
}

static t_bool	count_tiles(void)
{
	if (map_count('P') != 1)
		return (print_error("Map must contain exactly one player"), FALSE);
	if (map_count('E') != 1)
		return (print_error("Map must contain exactly one exit"), FALSE);
	if (map_count('C') == 0)
		return (print_error("Map must contain at least one collectable"),
			FALSE);
	return (TRUE);
}

t_bool	validate_map(void)
{
	return (validate_dims()
		&& no_bad_tiles()
		&& count_tiles());
}
