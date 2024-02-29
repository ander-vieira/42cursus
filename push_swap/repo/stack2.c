/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:25:37 by andeviei          #+#    #+#             */
/*   Updated: 2024/03/01 00:33:45 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	stack_print(t_stack stack, t_fd fd)
{
	size_t	i;

	i = 0;
	while (i < stack.l)
	{
		ft_printf(fd, "%d\n", stack_get(stack, i));
		i++;
	}
}
