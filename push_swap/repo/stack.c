/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:46:32 by andeviei          #+#    #+#             */
/*   Updated: 2024/02/09 19:31:30 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_new(int num, t_stack *next)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	stack->i = num;
	stack->n = next;
	return (stack);
}

void	stack_insert(t_stack **stack, int num)
{
	if (stack == NULL)
		return ;
	while (*stack != NULL)
		stack = &((*stack)->n);
	*stack = stack_new(num, *stack);
}

void	stack_free(t_stack *stack)
{
	if (stack == NULL)
		return ;
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

t_stack	*stack_get(t_stack *stack, t_uint i)
{
	size_t	j;

	j = 0;
	while (j < i && stack != NULL)
		stack = stack->n;
	return (stack);
}

t_bool	stack_has(t_stack *stack, int num)
{
	while (stack != NULL)
	{
		if (stack->i == num)
			return (TRUE);
		stack = stack->n;
	}
	return (FALSE);
}

void	stack_print(t_stack *stack)
{
	while (stack != NULL)
	{
		ft_printf(STDOUT_FILENO, "%d\n", stack->i);
		stack = stack->n;
	}
}

// void	stack_rotate(t_stack **stack)
// {
// 	t_stack	**last;

// 	if (stack == NULL || *stack == NULL)
// 		return ;
// 	last = stack;
// 	while ((*last)->n != NULL)
// 		*last = &((*last)->n);
// 	(*last)->n = *stack;
// 	*stack = *last;
// 	last = NULL;
// }

// void	stack_rrotate(t_stack **stack)
// {
// 	t_stack	**last;

// 	if (stack == NULL || *stack == NULL)
// 		return ;
// 	last = stack;
// 	while ((*last)->n != NULL)
// 		*last = &((*last)->n);
// 	(*last)->n = *stack;
// 	*stack = *last;
// 	last = NULL;
// }
