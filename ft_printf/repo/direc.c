/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 22:24:41 by andeviei          #+#    #+#             */
/*   Updated: 2023/09/23 18:38:14 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static ssize_t	pf_printnbr(t_pdirec direc, va_list args)
{
	ssize_t	len;
	int		num;

	if (direc.t == 'u')
		len = pf_putnbr_base(va_arg(args, unsigned int), BASE_DEC);
	else if (direc.t == 'x')
		len = pf_putnbr_base(va_arg(args, unsigned int), BASE_HEX_L);
	else if (direc.t == 'X')
		len = pf_putnbr_base(va_arg(args, unsigned int), BASE_HEX_U);
	else
	{
		num = va_arg(args, int);
		len = pf_putsign(num);
		if (direc.t == 'd' || direc.t == 'i')
			len += pf_putnbr_base(num, BASE_DEC);
	}
	return (len);
}

static ssize_t	pf_printptr(void *ptr, t_pdirec direc)
{
	ssize_t	len;

	direc.t++;
	if (ptr == NULL)
		return (pf_putstr("(nil)"));
	len = pf_putstr("0x");
	len += pf_putnbr_base((long)ptr, BASE_HEX_L);
	return (len);
}

void	pf_parseflags(t_pdirec *direc, t_pdata *pdata)
{
	size_t	len;

	direc->f = 0x00;
	len = 1;
	while (pdata->f[len] != '\0')
	{
		if (pdata->f[len] == '-')
			direc->f |= FLAG_LEFT;
		else if (pdata->f[len] == '0')
			direc->f |= FLAG_ZERO;
		else if (pdata->f[len] == '.')
			direc->f |= FLAG_PREC;
		else if (pdata->f[len] == '#')
			direc->f |= FLAG_ALTER;
		else if (pdata->f[len] == ' ')
			direc->f |= FLAG_BLANK;
		else if (pdata->f[len] == '+')
			direc->f |= FLAG_SIGN;
		else
			break ;
		len++;
	}
	direc->t = pdata->f[len];
	pdata->f += len + 1;
}

void	pf_direc(t_pdirec direc, t_pdata *pdata, va_list args)
{
	ssize_t	len;

	if (direc.t == 'c')
		len = pf_putchar(va_arg(args, int));
	else if (direc.t == 's')
		len = pf_putstr(va_arg(args, char *));
	else if (direc.t == 'd' || direc.t == 'i' || direc.t == 'u'
		|| direc.t == 'x' || direc.t == 'X')
		len = pf_printnbr(direc, args);
	else if (direc.t == 'p')
		len = pf_printptr(va_arg(args, void *), direc);
	else if (direc.t == '%')
		len = pf_putchar('%');
	else
	{
		len = pf_putchar('%');
		len += pf_putchar(direc.t);
	}
	if (len == -1)
		pdata->s = -1;
	pdata->l += len;
}
