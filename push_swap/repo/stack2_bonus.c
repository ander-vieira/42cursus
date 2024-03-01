/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 14:07:15 by andeviei          #+#    #+#             */
/*   Updated: 2024/03/01 14:08:36 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static size_t	get_stack_pos(t_stack stack, size_t i)
{
	return (wrap_sub(wrap_add(stack.i, stack.l, stack.s),
			wrap_add(i, 1, stack.s), stack.s));
}

int	stack_get(t_stack stack, size_t i)
{
	if (stack.l == 0)
		return (0);
	return (stack.n[get_stack_pos(stack, i)]);
}

void	stack_set(t_stack stack, size_t i, int num)
{
	if (stack.l == 0)
		return ;
	stack.n[get_stack_pos(stack, i)] = num;
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
