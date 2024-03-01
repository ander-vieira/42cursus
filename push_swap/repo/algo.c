/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:04:06 by andeviei          #+#    #+#             */
/*   Updated: 2024/03/01 21:23:53 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_algo	algo_init(t_stack a)
{
	t_algo	algo;

	algo.a = stack_clone(a);
	algo.b = stack_init(a.s);
	algo.oper = oper_init();
	return (algo);
}

void	algo_free(t_algo algo)
{
	stack_free(&(algo.a));
	stack_free(&(algo.b));
}

t_algo	*algo_op_n(t_algo *algo, t_op op, size_t n)
{
	op_do_n(op, n, algo);
	oper_add(&(algo->oper), op, n);
	return (algo);
}
