/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:39:25 by andeviei          #+#    #+#             */
/*   Updated: 2024/02/13 17:43:15 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_print(t_op op)
{
	if (op == OP_PA)
		ft_printf(STDOUT_FILENO, "pa\n");
	else if (op == OP_SA)
		ft_printf(STDOUT_FILENO, "sa\n");
	else if (op == OP_RA)
		ft_printf(STDOUT_FILENO, "ra\n");
	else if (op == OP_RRA)
		ft_printf(STDOUT_FILENO, "rra\n");
	else if (op == OP_PB)
		ft_printf(STDOUT_FILENO, "pb\n");
	else if (op == OP_SB)
		ft_printf(STDOUT_FILENO, "sb\n");
	else if (op == OP_RB)
		ft_printf(STDOUT_FILENO, "rb\n");
	else if (op == OP_RRB)
		ft_printf(STDOUT_FILENO, "rrb\n");
}

void	op_do(t_op op)
{
	if (op == OP_PA)
		stack_move(g_b(), g_a());
	else if (op == OP_SA)
		stack_swap(g_a());
	else if (op == OP_RA)
		stack_rotate(g_a());
	else if (op == OP_RRA)
		stack_rrotate(g_a());
	else if (op == OP_PB)
		stack_move(g_a(), g_b());
	else if (op == OP_SB)
		stack_swap(g_b());
	else if (op == OP_RB)
		stack_rotate(g_b());
	else if (op == OP_RRB)
		stack_rrotate(g_b());
}
