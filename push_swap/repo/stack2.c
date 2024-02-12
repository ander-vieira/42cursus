/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:25:37 by andeviei          #+#    #+#             */
/*   Updated: 2024/02/12 16:07:16 by andeviei         ###   ########.fr       */
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

void	stack_print(t_stack *stack)
{
	ft_printf(STDOUT_FILENO, "PRINTING STACK\n");
	while (stack != NULL)
	{
		ft_printf(STDOUT_FILENO, "%d\n", stack->i);
		stack = stack->n;
	}
}
