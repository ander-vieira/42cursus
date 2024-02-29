/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:46:32 by andeviei          #+#    #+#             */
/*   Updated: 2024/02/29 20:08:06 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

t_stack	stack_clone(t_stack stack)
{
	t_stack	new;

	new = stack_init(stack.s);
	ft_memcpy(new.n, stack.n, sizeof(int) * stack.s);
	new.i = stack.i;
	new.l = stack.l;
	return (new);
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
