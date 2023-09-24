/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 00:18:49 by andeviei          #+#    #+#             */
/*   Updated: 2023/09/24 16:30:16 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	init_pdata(t_pdata *pdata, const char *format)
{
	pdata->f = (char *)format;
	pdata->l = 0;
	pdata->s = 1;
}

static void	pf_text(t_pdata *pdata)
{
	size_t	len;
	ssize_t	len2;

	len = 0;
	while (pdata->f[len] != '\0' && pdata->f[len] != '%')
		len++;
	len2 = write(STDOUT_FILENO, pdata->f, len);
	pdata->f += len;
	if (pdata->f[0] == '\0')
		pdata->s = 0;
	pdata->l += len2;
	if (len2 == -1)
		pdata->s = -1;
}

static void	pf_direc(t_pdata *pdata, va_list args)
{
	t_direc	direc;

	pf_parsedirec(&direc, pdata);
	pf_printdirec(direc, pdata, args);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	t_pdata	pdata;

	va_start(args, format);
	init_pdata(&pdata, format);
	while (pdata.s == 1)
	{
		pf_text(&pdata);
		if (pdata.s != 1)
			break ;
		pf_direc(&pdata, args);
	}
	if (pdata.s == -1)
		return (-1);
	return (pdata.l);
}
