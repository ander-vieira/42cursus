/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:55:47 by andeviei          #+#    #+#             */
/*   Updated: 2024/03/01 21:23:24 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_left_three(t_algo *algo)
{
	if (stack_get(algo->a, 0) < stack_get(algo->a, 2)
		&& stack_get(algo->a, 2) < stack_get(algo->a, 1))
	{
		algo_op_n(algo, OP_SA, 1);
		algo_op_n(algo, OP_RA, 1);
	}
	else if (stack_get(algo->a, 1) < stack_get(algo->a, 0)
		&& stack_get(algo->a, 0) < stack_get(algo->a, 2))
		algo_op_n(algo, OP_SA, 1);
	else if (stack_get(algo->a, 1) < stack_get(algo->a, 2)
		&& stack_get(algo->a, 2) < stack_get(algo->a, 0))
		algo_op_n(algo, OP_RA, 1);
	else if (stack_get(algo->a, 2) < stack_get(algo->a, 0)
		&& stack_get(algo->a, 0) < stack_get(algo->a, 1))
		algo_op_n(algo, OP_RRA, 1);
	else if (stack_get(algo->a, 2) < stack_get(algo->a, 1)
		&& stack_get(algo->a, 1) < stack_get(algo->a, 0))
	{
		algo_op_n(algo, OP_RA, 1);
		algo_op_n(algo, OP_SA, 1);
	}
}

static void	move_all_left(t_algo *algo)
{
	t_uint	i;

	if (algo->b.l == 2 && stack_get(algo->b, 1) < stack_get(algo->b, 0))
		algo_op_n(algo, OP_SB, 1);
	i = 0;
	while (i < 3)
	{
		while (algo->b.l != 0
			&& (stack_get(algo->b, 0) < stack_get(algo->a, 0)))
		{
			algo_op_n(algo, OP_PA, 1);
			algo_op_n(algo, OP_RA, 1);
		}
		algo_op_n(algo, OP_RA, 1);
		i++;
	}
	while (algo->b.l != 0)
	{
		algo_op_n(algo, OP_PA, 1);
		algo_op_n(algo, OP_RA, 1);
	}
}

t_oper	algo_five(t_stack a)
{
	t_algo	algo;

	if (a.l != 4 && a.l != 5)
		return (oper_init());
	algo = algo_init(a);
	algo_op_n(&algo, OP_PB, a.l - 3);
	sort_left_three(&algo);
	move_all_left(&algo);
	algo_free(algo);
	return (algo.oper);
}
