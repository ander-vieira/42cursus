/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_steps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:01:45 by andeviei          #+#    #+#             */
/*   Updated: 2024/02/15 20:54:54 by andeviei         ###   ########.fr       */
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

t_oper	*get_steps(t_uint target_a)
{
	t_oper	*oper;
	t_uint	target_b;

	oper = NULL;
	add_steps_a(&oper, target_a);
	oper_add(&oper, OP_PB);
	add_steps_b(&oper, target_b);
	return (oper);
}

t_oper	*find_best_target(void)
{
	t_uint	len_a;
	t_uint	i;
	t_oper	*oper_min;
	t_uint	steps;
	t_oper	*oper;

	len_a = stack_length(*g_a());
	i = 0;
	while (i < len_a)
	{
		oper = get_steps(i);
		steps = oper_length(oper);
		if (i == 0 || steps < oper_length(oper_min))
		{
			oper_free(oper_min);
			oper_min = oper;
		}
		else
			oper_free(oper);
		i++;
	}
	return (oper);
}