/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 12:42:24 by andeviei          #+#    #+#             */
/*   Updated: 2023/10/10 12:42:24 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_putstr(char *str)
{
	write(STDOUT_FILENO, str, sl_strlen(str));
}

void	sl_putnbr(unsigned int nbr)
{
	char	c;

	if (nbr >= 10)
		sl_putnbr(nbr / 10);
	c = '0' + (nbr % 10);
	write(STDOUT_FILENO, &c, 1);
}
