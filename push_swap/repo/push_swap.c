/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:56:06 by andeviei          #+#    #+#             */
/*   Updated: 2024/02/15 18:18:19 by andeviei         ###   ########.fr       */
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
	read_args(argc, argv);
	stack_print(*g_a(), "A");
	stack_print(*g_b(), "B");
	op_do(OP_PB);
	op_do(OP_PB);
	op_do(OP_PB);
	stack_print(*g_a(), "A");
	stack_print(*g_b(), "B");
	op_do(OP_PA);
	stack_print(*g_a(), "A");
	stack_print(*g_b(), "B");
	stack_free(g_a());
	stack_free(g_b());
	return (EXIT_SUCCESS);
}
