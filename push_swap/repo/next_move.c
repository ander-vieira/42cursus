/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:01:45 by andeviei          #+#    #+#             */
/*   Updated: 2024/02/16 15:15:19 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	add_steps_a(t_oper **oper, t_uint target_a)
{
	t_uint	len_a;

	len_a = stack_length(*g_a());
	if (2 * target_a > len_a)
		oper_add_n(oper, OP_RRA, len_a - target_a);
	else
		oper_add_n(oper, OP_RA, target_a);
}

static void	add_steps_b(t_oper **oper, t_uint target_b)
{
	t_uint	len_b;

	len_b = stack_length(*g_b());
	if (2 * target_b > len_b)
		oper_add_n(oper, OP_RRB, len_b - target_b);
	else
		oper_add_n(oper, OP_RB, target_b);
}

static t_oper	*get_steps(t_uint target_a)
{
	t_oper	*oper;
	t_uint	target_b;

	oper = NULL;
	add_steps_a(&oper, target_a);
	target_b = stack_target(*g_b(), stack_get(*g_a(), target_a));
	add_steps_b(&oper, target_b);
	oper_add(&oper, OP_PB);
	return (oper);
}

t_oper	*next_move(void)
{
	t_uint	len_a;
	t_uint	i;
	t_oper	*oper_min;
	t_oper	*oper;

	len_a = stack_length(*g_a());
	oper_min = NULL;
	i = 0;
	while (i < len_a)
	{
		oper = get_steps(i);
		if (i == 0 || oper_length(oper) < oper_length(oper_min))
		{
			oper_free(&oper_min);
			oper_min = oper;
		}
		else
			oper_free(&oper);
		i++;
	}
	oper_do(oper_min);
	return (oper_min);
}

void	order_b(t_oper **oper)
{
	add_steps_b(oper, stack_max(*g_b()));
	oper_add_n(oper, OP_PA, stack_length(*g_b()));
}
