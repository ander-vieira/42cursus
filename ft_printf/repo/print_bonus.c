/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 18:52:21 by andeviei          #+#    #+#             */
/*   Updated: 2023/10/19 19:05:37 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_printstr(t_direc direc, t_print *print)
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
	{
		if (direc.f & FLAG_PLUS)
			pf_putchar('+', print);
		else if (direc.f & FLAG_SPACE)
			pf_putchar(' ', print);
		pf_putnbr(num, BASE_DEC, print);
	}
}

void	pf_printunbr(t_direc direc, t_print *print, char *base, char *prefix)
{
	unsigned int	num;

	num = va_arg(print->a, unsigned int);
	if ((direc.f & FLAG_ALTER) && num != 0)
		pf_putstr(prefix, print);
	pf_putnbr(num, base, print);
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
		pf_putunbr((unsigned long)ptr, BASE_HEXL, print);
	}
	(void)direc;
}
