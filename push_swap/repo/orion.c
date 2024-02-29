/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orion.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 13:01:25 by andeviei          #+#    #+#             */
/*   Updated: 2024/02/29 18:07:12 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_oper	*get_steps(t_algo *algo, t_uint target_a)
{
	t_oper	*oper;
	t_uint	target_b;
	t_uint	len_a;
	t_uint	len_b;

	oper = NULL;
	len_a = stack_length(algo->a);
	if (2 * target_a > len_a)
		oper_join(&oper, oper_get_n(OP_RRA, len_a - target_a));
	else
		oper_join(&oper, oper_get_n(OP_RA, target_a));
	target_b = stack_target(algo->b, stack_get(algo->a, target_a));
	len_b = stack_length(algo->b);
	if (2 * target_b > len_b)
		oper_join(&oper, oper_get_n(OP_RRB, len_b - target_b));
	else
		oper_join(&oper, oper_get_n(OP_RB, target_b));
	oper_add(&oper, OP_PB);
	return (oper);
}

static void	next_move(t_algo *algo)
{
	t_uint	len_a;
	t_uint	i;
	t_oper	*oper_min;
	t_oper	*oper;

	len_a = stack_length(algo->a);
	oper_min = NULL;
	i = 0;
	while (i < len_a)
	{
		oper = get_steps(algo, i);
		if (i == 0 || oper_length(oper) < oper_length(oper_min))
		{
			oper_free(&oper_min);
			oper_min = oper;
		}
		else
			oper_free(&oper);
		i++;
	}
	algo_add(algo, oper_min);
}

static void	order_b(t_algo *algo)
{
	t_uint	target_b;
	t_uint	len_b;

	target_b = stack_max(algo->b);
	len_b = stack_length(algo->b);
	if (2 * target_b > len_b)
		algo_add(algo, oper_get_n(OP_RRB, len_b - target_b));
	else
		algo_add(algo, oper_get_n(OP_RB, target_b));
	algo_add(algo, oper_get_n(OP_PA, stack_length(algo->b)));
}

t_oper	*orion(t_stack *a)
{
	t_algo	algo;

	algo = algo_init(a);
	while (algo.a != NULL)
		next_move(&algo);
	order_b(&algo);
	stack_free(&(algo.a));
	stack_free(&(algo.b));
	return (algo.oper);
}
