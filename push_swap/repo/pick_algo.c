/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pick_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 13:31:22 by andeviei          #+#    #+#             */
/*   Updated: 2024/02/29 17:39:45 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_oper	**g_min(void)
{
	static t_oper	*min;

	return (&min);
}

static void	check_algo(t_oper *(*fun)(t_stack *), t_stack *a)
{
	t_oper			*oper;
	t_uint			len;
	static t_uint	minlen;

	oper = fun(a);
	if (oper == NULL)
		return ;
	len = oper_length(oper);
	if (minlen == 0 || len < minlen)
	{
		oper_free(g_min());
		*g_min() = oper;
		minlen = len;
	}
	else
		oper_free(&oper);
}

t_oper	*pick_algo(t_stack *a)
{
	*g_min() = NULL;
	check_algo(&aries, a);
	check_algo(&orion, a);
	return (*g_min());
}
