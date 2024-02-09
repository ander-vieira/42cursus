/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:56:36 by andeviei          #+#    #+#             */
/*   Updated: 2024/02/09 19:00:53 by andeviei         ###   ########.fr       */
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

void	stack_insert(t_stack **stack, int num);
void	stack_free(t_stack *stack);
void	stack_print(t_stack *stack);

#endif