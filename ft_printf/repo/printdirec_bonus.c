/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printdirec_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:07:22 by andeviei          #+#    #+#             */
/*   Updated: 2023/10/19 16:40:03 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	pf_printstr(t_direc direc, t_print *print)
{
	char	*str;
	size_t	len;

	str = va_arg(print->a, char *);
	if (str == NULL)
		pf_putstr(STR_NULL, print);
	else
	{
		len = pf_strlen(str);
		while (len < direc.w)
		{
			pf_putchar(' ', print);
			len++;
		}
		pf_putstr(str, print);
	}
	(void)direc;
}

static void	pf_printnbr(t_direc direc, t_print *print)
{
	int	num;

	num = va_arg(print->a, int);
	if ((direc.f & FLAG_PLUS) && num >= 0)
		pf_putchar('+', print);
	else if ((direc.f & FLAG_SPACE) && num >= 0)
		pf_putchar(' ', print);
	pf_putnbr(num, BASE_DEC, print);
}

static void	pf_printunbr(t_direc direc, t_print *print)
{
	unsigned int	num;

	num = va_arg(print->a, unsigned int);
	if (direc.t == 'u')
		pf_putunbr(num, BASE_DEC, print);
	else if (direc.t == 'x')
	{
		if ((direc.f & FLAG_ALTER) && num != 0)
			pf_putstr(PRE_HEXL, print);
		pf_putunbr(num, BASE_HEXL, print);
	}
	else if (direc.t == 'X')
	{
		if ((direc.f & FLAG_ALTER) && num != 0)
			pf_putstr(PRE_HEXU, print);
		pf_putunbr(num, BASE_HEXU, print);
	}
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
		pf_printstr(direc, print);
	else if (direc.t == 'd' || direc.t == 'i')
		pf_printnbr(direc, print);
	else if (direc.t == 'u' || direc.t == 'x' || direc.t == 'X')
		pf_printunbr(direc, print);
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
