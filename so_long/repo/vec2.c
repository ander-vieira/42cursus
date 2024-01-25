/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:50:18 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/25 17:04:56 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_vec2	vec2_new(t_uint x, t_uint y)
{
	t_vec2	vec;

	vec.x = x;
	vec.y = y;
	return (vec);
}

t_vec2	vec2_add(t_vec2 v1, t_vec2 v2)
{
	t_vec2	result;

	result.x = v1.x + v2.x;
	result.y = v1.y + v2.y;
	return (result);
}
