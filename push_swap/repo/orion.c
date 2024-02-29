/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orion.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 13:01:25 by andeviei          #+#    #+#             */
/*   Updated: 2024/02/29 20:15:24 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_oper	*get_steps(t_algo *algo, t_uint target_a)
{
	t_oper	*oper;
	t_uint	target_b;

	oper = NULL;
	if (2 * target_a > algo->a.l)
		oper_join(&oper, oper_get_n(OP_RRA, algo->a.l - target_a));
	else
		oper_join(&oper, oper_get_n(OP_RA, target_a));
	target_b = stack_target(algo->b, stack_get(algo->a, target_a));
	if (2 * target_b > algo->b.l)
		oper_join(&oper, oper_get_n(OP_RRB, algo->b.l - target_b));
	else
		oper_join(&oper, oper_get_n(OP_RB, target_b));
	oper_add(&oper, OP_PB);
	return (oper);
}

static void	next_move(t_algo *algo)
{
	t_uint	i;
	t_oper	*oper_min;
	t_oper	*oper;

	oper_min = NULL;
	i = 0;
	while (i < algo->a.l)
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

	target_b = stack_max(algo->b);
	if (2 * target_b > algo->b.l)
		algo_add(algo, oper_get_n(OP_RRB, algo->b.l - target_b));
	else
		algo_add(algo, oper_get_n(OP_RB, target_b));
	algo_add(algo, oper_get_n(OP_PA, algo->b.l));
}

t_oper	*orion(t_stack a)
{
	t_algo	algo;

	algo = algo_init(a);
	while (algo.a.l != 0)
		next_move(&algo);
	order_b(&algo);
	stack_free(&(algo.a));
	stack_free(&(algo.b));
	return (algo.oper);
}
