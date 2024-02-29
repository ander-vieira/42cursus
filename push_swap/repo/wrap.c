/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 19:30:52 by andeviei          #+#    #+#             */
/*   Updated: 2024/02/29 20:31:36 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	wrap_add(size_t a, size_t b, size_t max)
{
	if (a + b >= max)
		return (a + b - max);
	return (a + b);
}

size_t	wrap_sub(size_t a, size_t b, size_t max)
{
	if (a < b)
		return (a + max - b);
	return (a - b);
}
