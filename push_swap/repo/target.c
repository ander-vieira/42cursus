/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 23:35:42 by andeviei          #+#    #+#             */
/*   Updated: 2024/03/01 21:19:55 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_trgt	get_trgt(t_algo algo, size_t target_a)
{
	t_trgt	t;

	t.ta = target_a;
	t.la = algo.a.l;
	t.tb = stack_target(algo.b, stack_get(algo.a, target_a));
	t.lb = algo.b.l;
	return (t);
}

static size_t	count_rotation(t_trgt t, t_rot r)
{
	if (r == ROT_NN)
		return (cmp_max(t.ta, t.tb));
	else if (r == ROT_NR)
		return (t.ta + t.lb - t.tb);
	else if (r == ROT_RN)
		return (t.la - t.ta + t.tb);
	else
		return (cmp_max(t.la - t.ta, t.lb - t.tb));
}

static t_rot	minimum_rotation(t_trgt t)
{
	t_rot	r_min;

	r_min = ROT_NN;
	if (count_rotation(t, ROT_NR) < count_rotation(t, r_min))
		r_min = ROT_NR;
	if (count_rotation(t, ROT_RN) < count_rotation(t, r_min))
		r_min = ROT_RN;
	if (count_rotation(t, ROT_RR) < count_rotation(t, r_min))
		r_min = ROT_RR;
	return (r_min);
}

size_t	target_count_steps(t_algo algo, size_t target_a)
{
	t_trgt	t;
	t_rot	r;

	t = get_trgt(algo, target_a);
	r = minimum_rotation(t);
	return (count_rotation(t, r));
}

void	target_do_steps(t_algo *algo, size_t target_a)
{
	t_trgt	t;
	t_rot	r;

	t = get_trgt(*algo, target_a);
	r = minimum_rotation(t);
	if (r == ROT_NN)
		algo_op_n(algo_op_n(algo, OP_RR, cmp_min(t.ta, t.tb)),
			op_choose(t.ta >= t.tb, OP_RA, OP_RB),
			cmp_diff(t.ta, t.tb));
	else if (r == ROT_NR)
		algo_op_n(algo_op_n(algo, OP_RA, t.ta), OP_RRB, t.lb - t.tb);
	else if (r == ROT_RN)
		algo_op_n(algo_op_n(algo, OP_RRA, t.la - t.ta), OP_RB, t.tb);
	else
		algo_op_n(algo_op_n(algo, OP_RRR, cmp_min(t.la - t.ta, t.lb - t.tb)),
			op_choose(t.la - t.ta >= t.lb - t.tb, OP_RRA, OP_RRB),
			cmp_diff(t.la - t.ta, t.lb - t.tb));
}
