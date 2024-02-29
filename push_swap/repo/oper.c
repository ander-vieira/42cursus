/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:14:20 by andeviei          #+#    #+#             */
/*   Updated: 2024/02/29 16:58:28 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_oper	*oper_new(t_op op)
{
	t_oper	*oper;

	oper = (t_oper *)malloc(sizeof(t_oper));
	if (oper == NULL)
		return (NULL);
	oper->o = op;
	oper->n = NULL;
	return (oper);
}

void	oper_add(t_oper **oper, t_op op)
{
	if (oper == NULL)
		return ;
	while (*oper != NULL)
		oper = &((*oper)->n);
	*oper = oper_new(op);
}

void	oper_print(t_oper *oper)
{
	while (oper != NULL)
	{
		op_print(oper->o);
		oper = oper->n;
	}
}

void	oper_do(t_algo *algo, t_oper *oper)
{
	while (oper != NULL)
	{
		op_do(algo, oper->o);
		oper = oper->n;
	}
}

void	oper_free(t_oper **oper)
{
	if (oper == NULL || *oper == NULL)
		return ;
	oper_free(&((*oper)->n));
	free(*oper);
	*oper = NULL;
}
