/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 14:04:58 by andeviei          #+#    #+#             */
/*   Updated: 2024/03/01 14:08:03 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

t_stack	stack_init(size_t s)
{
	t_stack	stack;

	stack.n = (int *)malloc(sizeof(int) * s);
	stack.s = s;
	stack.i = 0;
	stack.l = 0;
	return (stack);
}

void	stack_free(t_stack *stack)
{
	free(stack->n);
	stack->n = NULL;
}

void	stack_push(t_stack *stack, int num)
{
	if (stack->l == stack->s)
		return ;
	stack->n[wrap_add(stack->i, stack->l, stack->s)] = num;
	stack->l += 1;
}

int	stack_pop(t_stack *stack)
{
	if (stack->l == 0)
		return (0);
	stack->l -= 1;
	return (stack->n[wrap_add(stack->i, stack->l, stack->s)]);
}
