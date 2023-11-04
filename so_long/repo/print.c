/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:34:22 by andeviei          #+#    #+#             */
/*   Updated: 2023/11/04 19:55:04 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_printstr(char *str)
{
	write(STDOUT_FILENO, str, sl_strlen(str));
}

void	sl_printnbr(t_uint num)
{
	char	c;

	if (num >= 10)
		sl_printnbr(num / 10);
	c = '0' + (num % 10);
	write(STDOUT_FILENO, &c, 1);
}

void	sl_printnnl(t_uint num)
{
	sl_printnbr(num);
	sl_printstr("\n");
}
