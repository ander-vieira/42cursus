/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ursa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:55:47 by andeviei          #+#    #+#             */
/*   Updated: 2024/02/29 18:36:57 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_oper	*order_three(int num0, int num1, int num2)
{
	t_oper	*oper;

	oper = NULL;
	if (num0 < num2 && num2 < num1)
	{
		oper_add(&oper, OP_SA);
		oper_add(&oper, OP_RA);
	}
	else if (num1 < num0 && num0 < num2)
		oper_add(&oper, OP_SA);
	else if (num1 < num2 && num2 < num0)
		oper_add(&oper, OP_RA);
	else if (num2 < num0 && num0 < num1)
		oper_add(&oper, OP_RRA);
	else if (num2 < num1 && num1 < num0)
	{
		oper_add(&oper, OP_RA);
		oper_add(&oper, OP_SA);
	}
	return (oper);
}

static void	return_two(t_algo *algo)
{
	t_uint	i;
	t_uint	last_a;

	if (stack_get(algo->b, 1) < stack_get(algo->b, 0))
		algo_add(algo, oper_get_n(OP_SB, 1));
	i = 0;
	last_a = 2;
	while(i < 3)
	{
		while (algo->b != NULL
			&& (stack_get(algo->b, 0) < stack_get(algo->a, 0)))
		{
			algo_add(algo, oper_get_n(OP_PA, 1));
			algo_add(algo, oper_get_n(OP_RA, 1));
			last_a++;
		}
		algo_add(algo, oper_get_n(OP_RA, 1));
		i++;
	}
	while (algo->b != NULL)
	{
		algo_add(algo, oper_get_n(OP_PA, 1));
		algo_add(algo, oper_get_n(OP_RA, 1));
	}
}

t_oper	*ursa(t_stack *a)
{
	t_algo	algo;

	if (stack_length(a) != 5)
		return (NULL);
	algo = algo_init(a);
	algo_add(&algo, oper_get_n(OP_PB, 2));
	algo_add(&algo, order_three(stack_get(algo.a, 0), stack_get(algo.a, 1), stack_get(algo.a, 2)));
	return_two(&algo);
	algo_free(algo);
	return (algo.oper);
}
