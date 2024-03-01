/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ursa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:55:47 by andeviei          #+#    #+#             */
/*   Updated: 2024/03/01 03:26:36 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	order_three(t_algo *algo)
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

static void	return_two(t_algo *algo)
{
	t_uint	i;

	if (stack_get(algo->b, 1) < stack_get(algo->b, 0))
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

t_oper	ursa(t_stack a)
{
	t_algo	algo;

	algo = algo_init(a);
	if (a.l == 5)
	{
		algo_op_n(&algo, OP_PB, 2);
		order_three(&algo);
		return_two(&algo);
	}
	algo_free(algo);
	return (algo.oper);
}
