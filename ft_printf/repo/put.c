/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:08:54 by andeviei          #+#    #+#             */
/*   Updated: 2023/10/19 13:34:54 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_write(void *buf, size_t len, t_print *print)
{
	ssize_t	wrt;

	if (print->r == -1)
		return ;
	wrt = write(STDOUT_FILENO, buf, len);
	if (wrt == -1)
		print->r = -1;
	else
		print->r += wrt;
}

void	pf_putchar(char c, t_print *print)
{
	pf_write(&c, 1, print);
}

void	pf_putstr(char *str, t_print *print)
{
	if (str == NULL)
		pf_putstr(STR_NULL, print);
	else
		pf_write(str, pf_strlen(str), print);
}

void	pf_putnbr(long num, char *base, t_print *print)
{
	if (num < 0)
	{
		pf_write("-", 1, print);
		pf_putunbr(-num, base, print);
	}
	else
		pf_putunbr(num, base, print);
}

void	pf_putunbr(unsigned long num, char *base, t_print *print)
{
	size_t	base_len;

	base_len = pf_strlen(base);
	if (num >= base_len)
		pf_putunbr(num / base_len, base, print);
	pf_write(base + (num % base_len), 1, print);
}
