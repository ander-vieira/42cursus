/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:05:54 by andeviei          #+#    #+#             */
/*   Updated: 2024/02/29 20:14:35 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	stack_max(t_stack stack)
{
	size_t	i;
	size_t	i_max;

	i = 0;
	while (i < stack.l)
	{
		if (i == 0 || stack_get(stack, i) > stack_get(stack, i_max))
			i_max = i;
		i++;
	}
	return (i_max);
}

size_t	stack_target(t_stack stack, int num)
{
	size_t	i;
	int		num_prev;
	int		num_current;

	if (stack.l == 0)
		return (0);
	num_prev = stack_get(stack, stack.l - 1);
	i = 0;
	while (i < stack.l)
	{
		num_current = stack_get(stack, i);
		if (num < num_prev && (num > num_current || num_prev < num_current))
			return (i);
		num_prev = num_current;
		i++;
	}
	return (stack_max(stack));
}

t_bool	stack_ordered(t_stack stack)
{
	size_t	i;
	int		num_prev;
	int		num_current;

	if (stack.l < 2)
		return (TRUE);
	num_prev = stack_get(stack, 0);
	i = 1;
	while (i < stack.l)
	{
		num_current = stack_get(stack, i);
		if (num_prev > num_current)
			return (FALSE);
		num_prev = num_current;
		i++;
	}
	return (TRUE);
}
