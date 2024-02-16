/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:28:21 by andeviei          #+#    #+#             */
/*   Updated: 2024/02/16 14:15:52 by andeviei         ###   ########.fr       */
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

void	oper_add_n(t_oper **oper, t_op op, t_uint n)
{
	t_uint	i;

	i = 0;
	while (i < n)
	{
		oper_add(oper, op);
		i++;
	}
}

void	oper_join(t_oper **oper, t_oper *new)
{
	if (oper == NULL)
		return ;
	while (*oper != NULL)
		oper = &((*oper)->n);
	*oper = new;
}
