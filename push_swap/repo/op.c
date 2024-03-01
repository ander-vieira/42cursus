/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:39:25 by andeviei          #+#    #+#             */
/*   Updated: 2024/03/01 03:02:21 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_do(t_op op, t_algo *algo)
{
	if (op == OP_PA)
		stack_move(&(algo->b), &(algo->a));
	if (op == OP_SA)
		stack_swap(&(algo->a));
	if (op == OP_RA || op == OP_RR)
		stack_rotate(&(algo->a));
	if (op == OP_RRA || op == OP_RRR)
		stack_rrotate(&(algo->a));
	if (op == OP_PB)
		stack_move(&(algo->a), &(algo->b));
	if (op == OP_SB)
		stack_swap(&(algo->b));
	if (op == OP_RB || op == OP_RR)
		stack_rotate(&(algo->b));
	if (op == OP_RRB || op == OP_RRR)
		stack_rrotate(&(algo->b));
}

void	op_do_n(t_op op, size_t n, t_algo *algo)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		op_do(op, algo);
		i++;
	}
}

void	op_print(t_op op, t_fd fd)
{
	if (op == OP_PA)
		ft_printf(fd, "pa\n");
	if (op == OP_SA)
		ft_printf(fd, "sa\n");
	if (op == OP_RA)
		ft_printf(fd, "ra\n");
	if (op == OP_RRA)
		ft_printf(fd, "rra\n");
	if (op == OP_PB)
		ft_printf(fd, "pb\n");
	if (op == OP_SB)
		ft_printf(fd, "sb\n");
	if (op == OP_RB)
		ft_printf(fd, "rb\n");
	if (op == OP_RRB)
		ft_printf(fd, "rrb\n");
	if (op == OP_RR)
		ft_printf(fd, "rr\n");
	if (op == OP_RRR)
		ft_printf(fd, "rrr\n");
}

t_op	op_choose(t_bool b, t_op op1, t_op op2)
{
	if (b)
		return (op1);
	else
		return (op2);
}
