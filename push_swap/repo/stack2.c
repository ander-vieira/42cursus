/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:25:37 by andeviei          #+#    #+#             */
/*   Updated: 2024/02/14 19:39:28 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_uint	stack_length(t_stack *stack)
{
	if (stack == NULL)
		return (0);
	else
		return (1 + stack_length(stack->n));
}

int	stack_get(t_stack *stack, t_uint i)
{
	t_uint	j;

	j = 0;
	while (stack != NULL && j < i)
	{
		stack = stack->n;
		j++;
	}
	if (stack == NULL)
		return (0);
	return (stack->i);
}

t_bool	stack_find(t_stack *stack, t_uint *i, int num)
{
	t_uint	j;

	j = 0;
	while (stack != NULL)
	{
		if (stack->i == num)
		{
			if (i != NULL)
				*i = j;
			return (TRUE);
		}
		stack = stack->n;
		j++;
	}
	return (FALSE);
}

void	stack_print(t_stack *stack, char *name)
{
	ft_printf(STDOUT_FILENO, "PRINTING %s\n", name);
	while (stack != NULL)
	{
		ft_printf(STDOUT_FILENO, "%d\n", stack->i);
		stack = stack->n;
	}
}

void	stack_free(t_stack **stack)
{
	if (stack == NULL || *stack == NULL)
		return ;
	stack_free(&((*stack)->n));
	free(*stack);
	*stack = NULL;
}
