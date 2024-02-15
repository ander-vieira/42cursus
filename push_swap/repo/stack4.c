/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:05:54 by andeviei          #+#    #+#             */
/*   Updated: 2024/02/15 18:15:47 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_uint	stack_min(t_stack *stack)
{
	t_uint	i;
	t_uint	i_min;
	int		num_min;

	i = 0;
	while (stack != NULL)
	{
		if (i == 0 || stack->i < num_min)
		{
			i_min = i;
			num_min = stack->i;
		}
		stack = stack->n;
	}
	return (i_min);
}

t_uint	stack_target(t_stack *stack, int num)
{
	t_uint	i;	
	t_stack	*current;
	t_stack	*prev;

	if (stack == NULL || stack->n == NULL)
		return (0);
	current = stack;
	prev = stack;
	while (prev->n != NULL)
		prev = prev->n;
	i = 0;
	while (current != NULL)
	{
		if (num > prev->i && (num < current->i || prev->i > current->i))
			return (i);
		i++;
		prev = current;
		current = current->n;
	}
	return (stack_min(stack));
}
