/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 18:52:21 by andeviei          #+#    #+#             */
/*   Updated: 2023/10/19 20:27:43 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_printchar(t_direc direc, t_print *print)
{
	char	c;

	c = va_arg(print->a, int);
	if (!(direc.f & FLAG_MINUS))
		pf_putpad(' ', direc.w, 1, print);
	pf_putchar(c, print);
	if (direc.f & FLAG_MINUS)
		pf_putpad(' ', direc.w, 1, print);
}

void	pf_printstr(t_direc direc, t_print *print)
{
	char	*str;
	size_t	len;

	str = va_arg(print->a, char *);
	if (str == NULL)
	{
		str = STR_NULL;
		len = pf_strlen(str);
		if ((direc.f & FLAG_PREC) && direc.p < len)
			len = 0;
	}
	else
	{
		len = pf_strlen(str);
		if ((direc.f & FLAG_PREC) && direc.p < len)
			len = direc.p;
	}
	if (!(direc.f & FLAG_MINUS))
		pf_putpad(' ', direc.w, len, print);
	pf_write(str, len, print);
	if (direc.f & FLAG_MINUS)
		pf_putpad(' ', direc.w, len, print);
}

void	pf_printnbr(t_direc direc, t_print *print)
{
	int				num;
	unsigned int	unum;
	size_t			len;

	num = va_arg(print->a, int);
	unum = pf_abs(num);
	len = pf_countnbr(unum, direc.p, pf_strlen(BASE_DEC));
	if (num < 0 || (direc.f & (FLAG_PLUS | FLAG_SPACE)))
		len += 1;
	if (!(direc.f & FLAG_MINUS) && !(direc.f & FLAG_ZERO))
		pf_putpad(' ', direc.w, len, print);
	if (num < 0)
		pf_putchar('-', print);
	else if (direc.f & FLAG_PLUS)
		pf_putchar('+', print);
	else if (direc.f & FLAG_SPACE)
		pf_putchar(' ', print);
	if (!(direc.f & FLAG_MINUS) && (direc.f & FLAG_ZERO))
		pf_putpad('0', direc.w, len, print);
	pf_putnbr(unum, BASE_DEC, direc.p, print);
	if (direc.f & FLAG_MINUS)
		pf_putpad(' ', direc.w, len, print);
}

void	pf_printunbr(t_direc direc, t_print *print, char *base, char *prefix)
{
	unsigned int	num;
	size_t			len;

	num = va_arg(print->a, unsigned int);
	len = pf_countnbr(num, direc.p, pf_strlen(base));
	if ((direc.f & FLAG_ALTER) && num != 0)
		len += pf_strlen(prefix);
	if (!(direc.f & FLAG_MINUS) && !(direc.f & FLAG_ZERO))
		pf_putpad(' ', direc.w, len, print);
	if ((direc.f & FLAG_ALTER) && num != 0)
		pf_putstr(prefix, print);
	if (!(direc.f & FLAG_MINUS) && (direc.f & FLAG_ZERO))
		pf_putpad('0', direc.w, len, print);
	pf_putnbr(num, base, direc.p, print);
	if (direc.f & FLAG_MINUS)
		pf_putpad(' ', direc.w, len, print);
}

void	pf_printptr(t_direc direc, t_print *print)
{
	void	*ptr;
	size_t	len;

	ptr = va_arg(print->a, void *);
	if (ptr == NULL)
		len = pf_strlen(PTR_NULL);
	else
		len = pf_strlen(PRE_HEXL)
			+ pf_countnbr((unsigned long)ptr, 1, pf_strlen(BASE_HEXL));
	if (!(direc.f & FLAG_MINUS))
		pf_putpad(' ', direc.w, len, print);
	if (ptr == NULL)
		pf_putstr(PTR_NULL, print);
	else
	{
		pf_putstr(PRE_HEXL, print);
		pf_putnbr((unsigned long)ptr, BASE_HEXL, 1, print);
	}
	if (direc.f & FLAG_MINUS)
		pf_putpad(' ', direc.w, len, print);
}
