/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pick_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 13:31:22 by andeviei          #+#    #+#             */
/*   Updated: 2024/03/01 03:37:48 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_oper	*g_oper_min(void)
{
	static t_oper	oper_min;

	return (&oper_min);
}

static void	check_algo(t_oper (*fun)(t_stack), t_stack a)
{
	t_oper	oper;

	oper = fun(a);
	if (oper.l == 0)
		return ;
	if (g_oper_min()->l == 0 || oper.l < g_oper_min()->l)
	{
		oper_free(g_oper_min());
		*g_oper_min() = oper;
	}
	else
		oper_free(&oper);
}

t_oper	pick_algo(t_stack a)
{
	check_algo(&aries, a);
	check_algo(&ursa, a);
	check_algo(&orion, a);
	return (*g_oper_min());
}
