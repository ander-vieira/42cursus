/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 23:55:27 by andeviei          #+#    #+#             */
/*   Updated: 2024/03/01 00:25:25 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	cmp_max(size_t a, size_t b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

size_t	cmp_min(size_t a, size_t b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

size_t	cmp_diff(size_t a, size_t b)
{
	if (a >= b)
		return (a - b);
	else
		return (b - a);
}
