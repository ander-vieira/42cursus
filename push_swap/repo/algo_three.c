/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_three.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:19:10 by andeviei          #+#    #+#             */
/*   Updated: 2024/03/01 03:15:12 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	order_three(t_oper *oper, t_stack a)
{
	if (stack_get(a, 0) < stack_get(a, 2)
		&& stack_get(a, 2) < stack_get(a, 1))
	{
		oper_add(oper, OP_SA, 1);
		oper_add(oper, OP_RA, 1);
	}
	else if (stack_get(a, 1) < stack_get(a, 0)
		&& stack_get(a, 0) < stack_get(a, 2))
		oper_add(oper, OP_SA, 1);
	else if (stack_get(a, 1) < stack_get(a, 2)
		&& stack_get(a, 2) < stack_get(a, 0))
		oper_add(oper, OP_RA, 1);
	else if (stack_get(a, 2) < stack_get(a, 0)
		&& stack_get(a, 0) < stack_get(a, 1))
		oper_add(oper, OP_RRA, 1);
	else if (stack_get(a, 2) < stack_get(a, 1)
		&& stack_get(a, 1) < stack_get(a, 0))
	{
		oper_add(oper, OP_RA, 1);
		oper_add(oper, OP_SA, 1);
	}
}

t_oper	algo_three(t_stack a)
{
	t_oper	oper;

	oper = oper_init();
	if (a.l == 3)
		order_three(&oper, a);
	return (oper);
}
