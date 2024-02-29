/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:04:06 by andeviei          #+#    #+#             */
/*   Updated: 2024/02/29 18:09:18 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_algo	algo_init(t_stack *a)
{
	t_algo	algo;

	algo.a = stack_clone(a);
	algo.b = NULL;
	algo.oper = NULL;
	return (algo);
}

void	algo_free(t_algo algo)
{
	stack_free(&(algo.a));
	stack_free(&(algo.b));
}

void	algo_add(t_algo *algo, t_oper *oper)
{
	oper_do(algo, oper);
	oper_join(&(algo->oper), oper);
}
