/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:34:22 by andeviei          #+#    #+#             */
/*   Updated: 2023/11/04 18:39:26 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_printstr(char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	write(STDOUT_FILENO, str, len);
}

void	sl_printnbr(t_uint num)
{
	char	c;

	if (num >= 10)
		sl_printnbr(num / 10);
	c = '0' + (num % 10);
	write(STDOUT_FILENO, &c, 1);
}
