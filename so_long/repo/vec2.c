/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:50:18 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/29 17:44:04 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_vec2	vec2_new(int x, int y)
{
	t_vec2	vec;

	vec.x = x;
	vec.y = y;
	return (vec);
}

t_vec2	vec2_move(t_vec2 v, int x, int y)
{
	v.x += x;
	v.y += y;
	return (v);
}
