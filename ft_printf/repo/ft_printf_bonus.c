/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:51:38 by andeviei          #+#    #+#             */
/*   Updated: 2023/10/19 18:50:50 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	pf_direc(t_print *print)
{
	t_direc	direc;

	direc = pf_parsedirec(print);
	pf_printdirec(direc, print);
}

static void	pf_text(t_print *print)
{
	size_t	len;

	len = 0;
	while (print->s[len] != '\0' && print->s[len] != '%')
		len++;
	pf_write(print->s, len, print);
	print->s += len;
}

int	ft_printf(char const *f, ...)
{
	t_print	print;

	va_start(print.a, f);
	print.s = (char *)f;
	print.r = 0;
	while (print.r != -1 && print.s[0] != '\0')
	{
		if (print.s[0] == '%')
			pf_direc(&print);
		else
			pf_text(&print);
	}
	va_end(print.a);
	return (print.r);
}
