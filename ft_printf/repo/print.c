/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 18:47:43 by andeviei          #+#    #+#             */
/*   Updated: 2023/10/19 19:06:01 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_printchar(t_direc direc, t_print *print)
{
	char	c;

	c = va_arg(print->a, int);
	pf_putchar(c, print);
	(void)direc;
}

void	pf_printstr(t_direc direc, t_print *print)
{
	char	*str;

	str = va_arg(print->a, char *);
	if (str == NULL)
		pf_putstr(STR_NULL, print);
	else
		pf_putstr(str, print);
	(void)direc;
}

void	pf_printnbr(t_direc direc, t_print *print)
{
	int	num;

	num = va_arg(print->a, int);
	if (num < 0)
	{
		pf_putchar('-', print);
		pf_putnbr((unsigned int)(-num), BASE_DEC, print);
	}
	else
		pf_putnbr(num, BASE_DEC, print);
	(void)direc;
}

void	pf_printunbr(t_direc direc, t_print *print, char *base, char *prefix)
{
	unsigned int	num;

	num = va_arg(print->a, unsigned int);
	pf_putnbr(num, base, print);
	(void)direc;
	(void)prefix;
}

void	pf_printptr(t_direc direc, t_print *print)
{
	void	*ptr;

	ptr = va_arg(print->a, void *);
	if (ptr == NULL)
		pf_putstr(PTR_NULL, print);
	else
	{
		pf_putstr(PRE_HEXL, print);
		pf_putnbr((unsigned long)ptr, BASE_HEXL, print);
	}
	(void)direc;
}
