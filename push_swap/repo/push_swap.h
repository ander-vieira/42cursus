/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:56:36 by andeviei          #+#    #+#             */
/*   Updated: 2024/03/01 13:50:17 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

# include "libft/libft.h"

# define OPER_CHUNK	15

typedef enum e_op
{
	OP_PA,
	OP_SA,
	OP_RA,
	OP_RRA,
	OP_PB,
	OP_SB,
	OP_RB,
	OP_RRB,
	OP_RR,
	OP_RRR
}	t_op;

typedef struct s_oper
{
	t_op	*o;
	size_t	l;
	size_t	s;
}	t_oper;

typedef struct s_stack
{
	int		*n;
	size_t	s;
	size_t	i;
	size_t	l;
}	t_stack;

typedef struct s_algo
{
	t_stack	a;
	t_stack	b;
	t_oper	oper;
}	t_algo;

t_algo	algo_init(t_stack a);
void	algo_free(t_algo algo);
void	algo_oper(t_algo *algo, t_oper oper);
void	algo_op_n(t_algo *algo, t_op op, size_t n);

size_t	cmp_max(size_t a, size_t b);
size_t	cmp_min(size_t a, size_t b);
size_t	cmp_diff(size_t a, size_t b);

void	op_do(t_op op, t_algo *algo);
void	op_do_n(t_op op, size_t n, t_algo *algo);
void	op_print(t_op op, t_fd fd);
t_op	op_choose(t_bool b, t_op op1, t_op op2);

t_oper	oper_init(void);
t_oper	*oper_add(t_oper *oper, t_op op, size_t n);
void	oper_join(t_oper *oper, t_oper new);
void	oper_free(t_oper *oper);
void	oper_do(t_oper oper, t_algo *algo);
void	oper_print(t_oper oper, t_fd fd);

t_stack	stack_init(size_t s);
void	stack_free(t_stack *stack);
t_stack	stack_clone(t_stack stack);
void	stack_push(t_stack *stack, int num);
int		stack_pop(t_stack *stack);
int		stack_get(t_stack stack, size_t i);
void	stack_set(t_stack stack, size_t i, int num);
t_bool	stack_has(t_stack stack, int num);
void	stack_print(t_stack stack, t_fd fd);
size_t	stack_max(t_stack stack);
size_t	stack_target(t_stack stack, int num);
t_bool	stack_ordered(t_stack stack);
void	stack_move(t_stack *stack1, t_stack *stack2);
void	stack_swap(t_stack *stack);
void	stack_rotate(t_stack *stack);
void	stack_rrotate(t_stack *stack);

size_t	target_count_steps(t_algo algo, size_t target_a);
t_oper	target_get_steps(t_algo algo, size_t target_a);

size_t	wrap_add(size_t a, size_t b, size_t max);
size_t	wrap_sub(size_t a, size_t b, size_t max);

t_oper	algo_any(t_stack a);
t_oper	algo_five(t_stack a);
t_oper	algo_three(t_stack a);
t_oper	algo_two(t_stack a);

t_stack	read_args(int argc, char **argv);
t_oper	pick_algo(t_stack a);

#endif