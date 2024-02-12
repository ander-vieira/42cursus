/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:56:06 by andeviei          #+#    #+#             */
/*   Updated: 2024/02/12 19:48:55 by andeviei         ###   ########.fr       */
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

void	do_oper(t_op op)
{
	if (op == OP_PA && *g_b() != NULL)
		stack_push(g_a(), stack_pop(g_b()));
	if (op == OP_RA)
		stack_rotate(g_a());
	if (op == OP_RRA)
		stack_rrotate(g_a());
	if (op == OP_PB && *g_a() != NULL)
		stack_push(g_b(), stack_pop(g_a()));
	if (op == OP_RB)
		stack_rotate(g_b());
	if (op == OP_RRB)
		stack_rrotate(g_b());
}

static t_bool	read_args(int argc, char **argv)
{
	int		i;

	i = argc - 1;
	while (i > 0)
	{
		stack_push(g_a(), ft_parsenum(argv[i], BASE_DEC));
		i--;
	}
	return (TRUE);
}

int	main(int argc, char **argv)
{
	read_args(argc, argv);
	stack_print(*g_a());
	stack_rotate(g_a());
	stack_print(*g_a());
	stack_rrotate(g_a());
	stack_rrotate(g_a());
	stack_rrotate(g_a());
	stack_print(*g_a());
	stack_free(*g_a());
	return (EXIT_SUCCESS);
}
