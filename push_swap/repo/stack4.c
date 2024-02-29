/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:05:54 by andeviei          #+#    #+#             */
/*   Updated: 2024/02/16 17:20:15 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_uint	stack_max(t_stack *stack)
{
	t_uint	i;
	t_uint	i_max;
	int		num_max;

	i = 0;
	while (stack != NULL)
	{
		if (i == 0 || stack->i > num_max)
		{
			i_max = i;
			num_max = stack->i;
		}
		i++;
		stack = stack->n;
	}
	return (i_max);
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
		if (num < prev->i && (num > current->i || prev->i < current->i))
			return (i);
		i++;
		prev = current;
		current = current->n;
	}
	return (stack_max(stack));
}

t_bool	stack_ordered(t_stack *stack)
{
	while (stack != NULL && stack->n != NULL)
	{
		if (stack->i > stack->n->i)
			return (FALSE);
		stack = stack->n;
	}
	return (TRUE);
}
