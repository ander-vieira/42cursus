/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:25:37 by andeviei          #+#    #+#             */
/*   Updated: 2024/02/29 20:34:41 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_get(t_stack stack, size_t i)
{
	if (stack.l == 0)
		return (0);
	return (stack.n[wrap_sub(wrap_add(stack.i, stack.l - 1, stack.s), i, stack.s)]);
}

void	stack_set(t_stack stack, size_t i, int num)
{
	if (stack.l == 0)
		return ;
	stack.n[wrap_sub(wrap_add(stack.i, stack.l - 1, stack.s), i, stack.s)] = num;
}

t_bool	stack_has(t_stack stack, int num)
{
	size_t	i;

	if (stack.l == 0)
		return (FALSE);
	i = 0;
	while (i < stack.l)
	{
		if (stack_get(stack, i) == num)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

void	stack_print(t_stack stack)
{
	size_t	i;

	i = 0;
	while (i < stack.l)
	{
		ft_printf(STDOUT_FILENO, "%d\n", stack_get(stack, i));
		i++;
	}
}
