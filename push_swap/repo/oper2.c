/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:28:21 by andeviei          #+#    #+#             */
/*   Updated: 2024/02/29 18:02:14 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_uint	oper_length(t_oper *oper)
{
	t_uint	len;

	len = 0;
	while (oper != NULL)
	{
		len++;
		oper = oper->n;
	}
	return (len);
}

t_oper	*oper_get_n(t_op op, t_uint n)
{
	t_oper	*oper;
	t_uint	i;

	oper = NULL;
	i = 0;
	while (i < n)
	{
		oper_add(&oper, op);
		i++;
	}
	return (oper);
}

void	oper_join(t_oper **oper, t_oper *new)
{
	if (oper == NULL)
		return ;
	while (*oper != NULL)
		oper = &((*oper)->n);
	*oper = new;
}
