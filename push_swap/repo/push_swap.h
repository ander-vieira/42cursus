/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:56:36 by andeviei          #+#    #+#             */
/*   Updated: 2024/02/16 15:13:48 by andeviei         ###   ########.fr       */
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
	OP_SA,
	OP_RA,
	OP_RRA,
	OP_PB,
	OP_SB,
	OP_RB,
	OP_RRB
}	t_op;

typedef struct s_oper
{
	t_op			o;
	struct s_oper	*n;
}	t_oper;

typedef struct s_stack
{
	int				i;
	struct s_stack	*n;
}	t_stack;

void	op_print(t_op op);
void	op_do(t_op op);

void	oper_add(t_oper **oper, t_op op);
void	oper_print(t_oper *oper);
void	oper_do(t_oper *oper);
void	oper_free(t_oper **oper);
t_uint	oper_length(t_oper *oper);
void	oper_add_n(t_oper **oper, t_op op, t_uint n);
void	oper_join(t_oper **oper, t_oper *new);

t_stack	*stack_clone(t_stack *stack);
void	stack_push(t_stack **stack, int num);
int		stack_pop(t_stack **stack);
int		stack_peek(t_stack *stack);
t_uint	stack_length(t_stack *stack);
int		stack_get(t_stack *stack, t_uint i);
t_bool	stack_find(t_stack *stack, t_uint *i, int num);
void	stack_print(t_stack *stack);
void	stack_free(t_stack **stack);
void	stack_rotate(t_stack **stack);
void	stack_rrotate(t_stack **stack);
void	stack_swap(t_stack **stack);
void	stack_move(t_stack **stack1, t_stack **stack2);
t_uint	stack_max(t_stack *stack);
t_uint	stack_target(t_stack *stack, int num);

void	read_args(int argc, char **argv);
t_oper	*next_move(void);
void	order_b(t_oper **oper);

t_stack	**g_a(void);
t_stack	**g_b(void);

#endif