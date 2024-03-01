/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:28:21 by andeviei          #+#    #+#             */
/*   Updated: 2024/03/01 03:47:51 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	oper_do(t_oper oper, t_algo *algo)
{
	size_t	i;

	i = 0;
	while (i < oper.l)
	{
		op_do(oper.o[i], algo);
		i++;
	}
}

void	oper_print(t_oper oper, t_fd fd)
{
	size_t	i;

	i = 0;
	while (i < oper.l)
	{
		op_print(oper.o[i], fd);
		i++;
	}
}
