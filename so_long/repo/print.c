/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:34:22 by andeviei          #+#    #+#             */
/*   Updated: 2023/11/09 15:37:25 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_printstr(char *str, int fd)
{
	write(fd, str, sl_strlen(str));
}

void	sl_printnbr(t_uint num, int fd)
{
	char	c;

	if (num >= 10)
		sl_printnbr(num / 10, fd);
	c = '0' + (num % 10);
	write(fd, &c, 1);
}

void	sl_printnnl(t_uint num)
{
	sl_printnbr(num, STDOUT_FILENO);
	sl_printstr("\n", STDOUT_FILENO);
}
