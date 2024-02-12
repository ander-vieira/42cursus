/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:56:36 by andeviei          #+#    #+#             */
/*   Updated: 2024/02/12 16:03:34 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

# include "libft/libft.h"

typedef enum e_op
{
	OP_PA,
	OP_RA,
	OP_RRA,
	OP_PB,
	OP_RB,
	OP_RRB
}	t_op;

typedef struct s_oper
{
	t_op			v;
	struct s_oper	*n;
}	t_oper;

typedef struct s_stack
{
	int				i;
	struct s_stack	*n;
}	t_stack;

void	stack_push(t_stack **stack, int num);
int		stack_pop(t_stack **stack);
void	stack_free(t_stack *stack);
t_uint	stack_length(t_stack *stack);
void	stack_rotate(t_stack **stack);
void	stack_rrotate(t_stack **stack);
void	stack_print(t_stack *stack);

#endif