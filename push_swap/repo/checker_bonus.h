/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 13:14:58 by andeviei          #+#    #+#             */
/*   Updated: 2024/03/01 14:12:09 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# include "libft/libft.h"

typedef enum e_op
{
	OP_BAD,
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
}	t_algo;

t_op	op_parse(char *line);
void	op_do(t_op op, t_algo *algo);

t_stack	stack_init(size_t s);
void	stack_free(t_stack *stack);
void	stack_push(t_stack *stack, int num);
int		stack_pop(t_stack *stack);
int		stack_get(t_stack stack, size_t i);
void	stack_set(t_stack stack, size_t i, int num);
t_bool	stack_has(t_stack stack, int num);
t_bool	stack_ordered(t_stack stack);
void	stack_move(t_stack *stack1, t_stack *stack2);
void	stack_swap(t_stack *stack);
void	stack_rotate(t_stack *stack);
void	stack_rrotate(t_stack *stack);

size_t	wrap_add(size_t a, size_t b, size_t max);
size_t	wrap_sub(size_t a, size_t b, size_t max);

t_stack	read_args(int argc, char **argv);

#endif