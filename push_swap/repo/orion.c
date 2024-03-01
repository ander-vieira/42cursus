/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orion.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 13:01:25 by andeviei          #+#    #+#             */
/*   Updated: 2024/03/01 03:38:29 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_one_right(t_algo *algo)
{
	size_t	i;
	size_t	i_min;
	size_t	len_min;
	size_t	len;

	i = 0;
	while (i < algo->a.l)
	{
		len = target_count_steps(*algo, i);
		if (i == 0 || len < len_min)
		{
			i_min = i;
			len_min = len;
		}
		i++;
	}
	algo_oper(algo, target_get_steps(*algo, i_min));
}

static void	move_all_left(t_algo *algo)
{
	t_uint	target_b;

	target_b = stack_max(algo->b);
	if (2 * target_b > algo->b.l)
		algo_op_n(algo, OP_RRB, algo->b.l - target_b);
	else
		algo_op_n(algo, OP_RB, target_b);
	algo_op_n(algo, OP_PA, algo->b.l);
}

t_oper	orion(t_stack a)
{
	t_algo	algo;

	algo = algo_init(a);
	while (algo.a.l != 0)
		move_one_right(&algo);
	move_all_left(&algo);
	algo_free(algo);
	return (algo.oper);
}
