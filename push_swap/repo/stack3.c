/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:32:53 by andeviei          #+#    #+#             */
/*   Updated: 2024/02/15 18:06:57 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*last;

	if (stack == NULL || stack_length(*stack) < 2)
		return ;
	first = *stack;
	second = first->n;
	last = second;
	while (last->n != NULL)
		last = last->n;
	first->n = NULL;
	last->n = first;
	*stack = second;
}

void	stack_rrotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*before_last;
	t_stack	*last;

	if (stack == NULL || stack_length(*stack) < 2)
		return ;
	first = *stack;
	before_last = *stack;
	while (before_last->n->n != NULL)
		before_last = before_last->n;
	last = before_last->n;
	before_last->n = NULL;
	last->n = first;
	*stack = last;
}

void	stack_swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (stack == NULL || stack_length(*stack) < 2)
		return ;
	first = *stack;
	second = first->n;
	first->n = second->n;
	second->n = first;
	*stack = second;
}

void	stack_move(t_stack **stack1, t_stack **stack2)
{
	if (stack1 == NULL || stack2 == NULL || *stack1 == NULL)
		return ;
	stack_push(stack2, stack_pop(stack1));
}
