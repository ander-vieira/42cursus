/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:14:20 by andeviei          #+#    #+#             */
/*   Updated: 2024/03/01 21:27:10 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_oper	oper_init(void)
{
	t_oper	oper;

	oper.o = NULL;
	oper.l = 0;
	oper.s = 0;
	return (oper);
}

static void	oper_realloc(t_oper *oper)
{
	size_t	s_old;
	t_op	*o_old;
	size_t	i;

	s_old = oper->s;
	oper->s += OPER_CHUNK;
	o_old = oper->o;
	oper->o = (t_op *)malloc(sizeof(t_op) * oper->s);
	i = 0;
	while (i < s_old)
	{
		oper->o[i] = o_old[i];
		i++;
	}
	free(o_old);
}

void	oper_add(t_oper *oper, t_op op, size_t n)
{
	size_t	i;

	if (n == 0)
		return ;
	while (oper->l + n > oper->s)
		oper_realloc(oper);
	i = 0;
	while (i < n)
	{
		oper->o[oper->l + i] = op;
		i++;
	}
	oper->l += n;
}

void	oper_free(t_oper *oper)
{
	free(oper->o);
	oper->o = NULL;
	oper->l = 0;
	oper->s = 0;
}

void	oper_print(t_oper oper, t_fd fd)
{
	size_t	i;

	i = 0;
	while (i < oper.l)
	{
		op_print(oper.o[i], fd);
		i++;
	}
}
