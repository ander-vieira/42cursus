/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printdirec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:07:22 by andeviei          #+#    #+#             */
/*   Updated: 2023/10/19 14:37:50 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	pf_printnbr(t_direc direc, t_print *print)
{
	if (direc.t == 'd' || direc.t == 'i')
		pf_putnbr(va_arg(print->a, int), BASE_DEC, print);
	else if (direc.t == 'u')
		pf_putunbr(va_arg(print->a, unsigned int), BASE_DEC, print);
	else if (direc.t == 'x')
		pf_putunbr(va_arg(print->a, unsigned int), BASE_HEXL, print);
	else if (direc.t == 'X')
		pf_putunbr(va_arg(print->a, unsigned int), BASE_HEXU, print);
}

static void	pf_printptr(t_direc direc, t_print *print)
{
	void	*ptr;

	ptr = va_arg(print->a, void *);
	if (ptr == NULL)
		pf_putstr(PTR_NULL, print);
	else
	{
		pf_putstr(PRE_HEXL, print);
		pf_putunbr((unsigned long)ptr, BASE_HEXL, print);
	}
	(void)direc;
}

void	pf_printdirec(t_direc direc, t_print *print)
{
	if (direc.t == 'c')
		pf_putchar(va_arg(print->a, int), print);
	else if (direc.t == 's')
		pf_putstr(va_arg(print->a, char *), print);
	else if (direc.t == 'd' || direc.t == 'i' || direc.t == 'u'
		|| direc.t == 'x' || direc.t == 'X')
		pf_printnbr(direc, print);
	else if (direc.t == 'p')
		pf_printptr(direc, print);
	else if (direc.t == '%')
		pf_putchar('%', print);
	else
	{
		pf_putchar('%', print);
		pf_putchar(direc.t, print);
	}
}
