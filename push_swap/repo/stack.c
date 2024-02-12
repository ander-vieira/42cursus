/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:46:32 by andeviei          #+#    #+#             */
/*   Updated: 2024/02/12 14:30:50 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*stack_new(int num, t_stack *next)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	stack->i = num;
	stack->n = next;
	return (stack);
}

void	stack_push(t_stack **stack, int num)
{
	if (stack == NULL)
		return ;
	*stack = stack_new(num, *stack);
}

int	stack_pop(t_stack **stack)
{
	t_stack	*elem;
	int		num;

	if (stack == NULL || *stack == NULL)
		return (0);
	elem = *stack;
	*stack = elem->n;
	num = elem->i;
	free(elem);
	return (num);
}

void	stack_free(t_stack *stack)
{
	if (stack != NULL)
		stack_free(stack->n);
	free(stack);
}

t_uint	stack_length(t_stack *stack)
{
	if (stack == NULL)
		return (0);
	else
		return (1 + stack_length(stack->n));
}
