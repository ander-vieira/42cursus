/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 20:55:36 by andeviei          #+#    #+#             */
/*   Updated: 2023/11/30 16:36:13 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
t_bool	sl_validchars(t_map	*map)
{
	size_t	p_num;
	size_t	c_num;
	size_t	e_num;
	size_t	i;

	p_num = 0;
	c_num = 0;
	e_num = 0;
	i = 0;
	while (i < map->w * map->h)
	{
		if (map->m[i] == 'P')
			p_num += 1;
		else if (map->m[i] == 'C')
			c_num += 1;
		else if (map->m[i] == 'E')
			e_num += 1;
		else if (map->m[i] != '0' && map->m[i] != '1')
			return (FALSE);
		i++;
	}
	if (p_num != 1)
		return (FALSE);
	if (c_num == 0)
		return (FALSE);
	if (e_num != 1)
		return (FALSE);
	return (TRUE);
}

//TODO
t_bool	sl_validmap(t_map *map)
{
	(void)map;
	return (TRUE);
}
*/