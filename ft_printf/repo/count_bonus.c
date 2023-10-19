/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 19:24:39 by andeviei          #+#    #+#             */
/*   Updated: 2023/10/19 20:29:30 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	pf_countnbr(unsigned long num, size_t prec, size_t base_len)
{
	size_t	result;

	if (num == 0 && prec == 0)
		return (0);
	result = 1;
	while (num >= base_len || prec > 1)
	{
		if (prec > 1)
			prec -= 1;
		num /= base_len;
		result += 1;
	}
	return (result);
}
