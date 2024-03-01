/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:32:53 by andeviei          #+#    #+#             */
/*   Updated: 2024/02/29 20:49:11 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_move(t_stack *stack1, t_stack *stack2)
{
	stack_push(stack2, stack_pop(stack1));
}

void	stack_swap(t_stack *stack)
{
	int	num;

	if (stack->l < 2)
		return ;
	num = stack_get(*stack, 0);
	stack_set(*stack, 0, stack_get(*stack, 1));
	stack_set(*stack, 1, num);
}

void	stack_rotate(t_stack *stack)
{
	if (stack->l < 2)
		return ;
	stack_set(*stack, stack->l, stack_get(*stack, 0));
	stack->i = wrap_sub(stack->i, 1, stack->s);
}

void	stack_rrotate(t_stack *stack)
{
	if (stack->l < 2)
		return ;
	stack->i = wrap_add(stack->i, 1, stack->s);
	stack_set(*stack, 0, stack_get(*stack, stack->l));
}
