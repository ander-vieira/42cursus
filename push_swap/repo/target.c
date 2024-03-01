/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 23:35:42 by andeviei          #+#    #+#             */
/*   Updated: 2024/03/01 01:09:41 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	target_count_one(size_t target, size_t len)
{
	if (2 * target > len)
		return (len - target);
	else
		return (target);
}

size_t	target_count_steps(t_algo algo, size_t target_a)
{
	size_t	target_b;
	size_t	count_a;
	size_t	count_b;

	target_b = stack_target(algo.b, stack_get(algo.a, target_a));
	count_a = target_count_one(target_a, algo.a.l);
	count_b = target_count_one(target_b, algo.b.l);
	if (ft_xor(count_a != target_a, count_b != target_b))
		return (cmp_max(count_a, count_b) + 1);
	else
		return (count_a + count_b + 1);
}

static t_oper	*target_get_ab(size_t target_a, size_t count_a,
		size_t target_b, size_t count_b)
{
	t_oper	*oper;

	oper = NULL;
	if (count_a != target_a && count_b != target_b)
		oper_join(oper_join(&oper,
				oper_get_n(OP_RRR, cmp_min(count_a, count_b))), oper_get_n(
				op_choose(count_a >= count_b, OP_RRA, OP_RRB),
				cmp_diff(count_a, count_b)));
	else if (count_a != target_a && count_b == target_b)
		oper_join(oper_join(&oper, oper_get_n(OP_RRA, count_a)),
			oper_get_n(OP_RB, count_b));
	else if (count_a == target_a && count_b != target_b)
		oper_join(oper_join(&oper, oper_get_n(OP_RA, count_a)),
			oper_get_n(OP_RRB, count_b));
	else
		oper_join(oper_join(&oper,
				oper_get_n(OP_RR, cmp_min(count_a, count_b))), oper_get_n(
				op_choose(count_a >= count_b, OP_RA, OP_RB),
				cmp_diff(count_a, count_b)));
	oper_add(&oper, OP_PB);
	return (oper);
}

t_oper	*target_get_steps(t_algo algo, size_t target_a)
{
	size_t	target_b;

	target_b = stack_target(algo.b, stack_get(algo.a, target_a));
	return (target_get_ab(target_a, target_count_one(target_a, algo.a.l),
			target_b, target_count_one(target_b, algo.b.l)));
}
