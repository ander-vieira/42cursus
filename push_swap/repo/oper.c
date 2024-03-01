/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:14:20 by andeviei          #+#    #+#             */
/*   Updated: 2024/03/01 13:38:40 by andeviei         ###   ########.fr       */
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

t_oper	*oper_add(t_oper *oper, t_op op, size_t n)
{
	size_t	i;

	if (n == 0)
		return (oper);
	while (oper->l + n > oper->s)
		oper_realloc(oper);
	i = 0;
	while (i < n)
	{
		oper->o[oper->l + i] = op;
		i++;
	}
	oper->l += n;
	return (oper);
}

void	oper_join(t_oper *oper, t_oper new)
{
	size_t	i;

	while (oper->l + new.l > oper->s)
		oper_realloc(oper);
	i = 0;
	while (i < new.l)
	{
		oper->o[oper->l + i] = new.o[i];
		i++;
	}
	oper->l += new.l;
}

void	oper_free(t_oper *oper)
{
	free(oper->o);
	oper->o = NULL;
	oper->l = 0;
	oper->s = 0;
}
