/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:15:50 by andeviei          #+#    #+#             */
/*   Updated: 2024/02/05 15:52:54 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_uint	*g_moves(void)
{
	static t_uint	moves;

	return (&moves);
}

void	increment_moves(void)
{
	*g_moves() += 1;
}

t_uint	get_moves(void)
{
	return (*g_moves());
}

void	draw_moves(void)
{
	char	*str;

	str = ft_strformat("%u", *g_moves());
	if (str == NULL)
		return ;
	mlx_string_put(g_sl()->mlx, g_sl()->win, 4, 20, 0x00FF0000, str);
	free(str);
}
