/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:56:06 by andeviei          #+#    #+#             */
/*   Updated: 2024/02/16 15:16:18 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	**g_a(void)
{
	static t_stack	*a;

	return (&a);
}

t_stack	**g_b(void)
{
	static t_stack	*b;

	return (&b);
}

int	main(int argc, char **argv)
{
	t_oper	*oper;

	read_args(argc, argv);
	while (*g_a() != NULL)
		oper_join(&oper, next_move());
	order_b(&oper);
	oper_print(oper);
	stack_free(g_a());
	stack_free(g_b());
	return (EXIT_SUCCESS);
}
