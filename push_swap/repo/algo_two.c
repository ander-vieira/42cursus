/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 13:42:48 by andeviei          #+#    #+#             */
/*   Updated: 2024/03/01 13:44:27 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_oper	algo_two(t_stack a)
{
	t_oper	oper;

	oper = oper_init();
	if (a.l == 2)
		oper_add(&oper, OP_SA, 1);
	return (oper);
}
