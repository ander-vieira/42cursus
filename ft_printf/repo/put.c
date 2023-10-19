/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:08:54 by andeviei          #+#    #+#             */
/*   Updated: 2023/10/19 20:04:07 by andeviei         ###   ########.fr       */
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
	pf_write(str, pf_strlen(str), print);
}

void	pf_putnbr(unsigned long num, char *base, size_t prec, t_print *print)
{
	size_t	base_len;

	base_len = pf_strlen(base);
	if (num >= base_len)
		pf_putnbr(num / base_len, base, prec, print);
	pf_write(base + (num % base_len), 1, print);
}
