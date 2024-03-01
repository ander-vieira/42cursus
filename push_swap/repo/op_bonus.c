/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 13:59:23 by andeviei          #+#    #+#             */
/*   Updated: 2024/03/01 14:21:23 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

t_op	op_parse(char *line)
{
	if (ft_strcmp(line, "pa\n"))
		return (OP_PA);
	if (ft_strcmp(line, "sa\n"))
		return (OP_SA);
	if (ft_strcmp(line, "ra\n"))
		return (OP_RA);
	if (ft_strcmp(line, "rra\n"))
		return (OP_RRA);
	if (ft_strcmp(line, "pb\n"))
		return (OP_PB);
	if (ft_strcmp(line, "sb\n"))
		return (OP_SB);
	if (ft_strcmp(line, "rb\n"))
		return (OP_RB);
	if (ft_strcmp(line, "rrb\n"))
		return (OP_RRB);
	if (ft_strcmp(line, "rr\n"))
		return (OP_RR);
	if (ft_strcmp(line, "rrr\n"))
		return (OP_RRR);
	return (OP_BAD);
}

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
