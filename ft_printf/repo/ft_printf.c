/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:51:38 by andeviei          #+#    #+#             */
/*   Updated: 2023/10/18 20:29:47 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	pf_direc(t_print *print)
{
	t_direc	direc;

	direc = pf_parsedirec();
}

static void	pf_text(t_print *print)
{
	size_t	len;
	ssize_t	wrt;

	len = 0;
	while (print->f != '\0' && print->f != '%')
		len++;
	wrt = write(STDOUT_FILENO, print->f, len);
	if (wrt == -1)
		print->r = -1;
	else
		print->r += wrt;
}

int	ft_printf(char const *f, ...)
{
	t_print print;
	
	va_start(print.a, f);
	print.f = f;
	print.r = 0;
	while (print.r != -1 && print.f[0] != '\0')
	{
		if (print.f[0] == '%')
			pf_direc(&print);
		else
			pf_text(&print);
	}
	va_end(print.a);
}