/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aries.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:19:10 by andeviei          #+#    #+#             */
/*   Updated: 2024/02/29 17:50:46 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_oper	*get_oper(int num0, int num1, int num2)
{
	t_oper	*oper;

	oper = NULL;
	if (num0 < num2 && num2 < num1)
	{
		oper_add(&oper, OP_SA);
		oper_add(&oper, OP_RA);
	}
	else if (num1 < num0 && num0 < num2)
		oper_add(&oper, OP_SA);
	else if (num1 < num2 && num2 < num0)
		oper_add(&oper, OP_RA);
	else if (num2 < num0 && num0 < num1)
		oper_add(&oper, OP_RRA);
	else if (num2 < num1 && num1 < num0)
	{
		oper_add(&oper, OP_RA);
		oper_add(&oper, OP_SA);
	}
	return (oper);
}

t_oper	*aries(t_stack *a)
{
	if (stack_length(a) != 3)
		return (NULL);
	return (get_oper(stack_get(a, 0), stack_get(a, 1), stack_get(a, 2)));
}
