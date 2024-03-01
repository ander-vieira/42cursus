/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:14:20 by andeviei          #+#    #+#             */
/*   Updated: 2024/03/01 03:47:49 by andeviei         ###   ########.fr       */
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

	s_old = oper->s;
	oper->s += OPER_CHUNK;
	o_old = oper->o;
	oper->o = (t_op *)malloc(sizeof(t_op) * oper->s);
	if (o_old != NULL)
	{
		ft_memcpy(oper->o, o_old, sizeof(t_op) * s_old);
		free(o_old);
	}
}

t_oper	*oper_add(t_oper *oper, t_op op, size_t n)
{
	size_t	i;

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
	while (oper->l + new.l > oper->s)
		oper_realloc(oper);
	ft_memcpy(oper->o + oper->l, new.o, new.l);
	oper->l += new.l;
}

void	oper_free(t_oper *oper)
{
	free(oper->o);
	oper->o = NULL;
	oper->l = 0;
	oper->s = 0;
}
