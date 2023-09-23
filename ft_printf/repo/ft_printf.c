/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 00:18:49 by andeviei          #+#    #+#             */
/*   Updated: 2023/09/23 18:30:02 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	init_pdata(t_pdata *pdata, const char *format)
{
	pdata->f = (char *)format;
	pdata->l = 0;
	pdata->s = 1;
}

static void	parse_text(t_pdata *pdata)
{
	size_t	len;

	len = 0;
	while (pdata->f[len] != '\0' && pdata->f[len] != '%')
		len++;
	if (write(STDOUT_FILENO, pdata->f, len) == -1)
	{
		pdata->s = -1;
		return ;
	}
	pdata->f += len;
	pdata->l += len;
	if (pdata->f[0] == '\0')
		pdata->s = 0;
}

static void	parse_direc(t_pdata *pdata, va_list args)
{
	t_pdirec	direc;

	pf_parseflags(&direc, pdata);
	pf_direc(direc, pdata, args);
	if (pdata->f[0] == '\0')
		pdata->s = 0;
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	t_pdata	pdata;

	va_start(args, format);
	init_pdata(&pdata, format);
	while (pdata.s == 1)
	{
		parse_text(&pdata);
		if (pdata.s != 1)
			break ;
		parse_direc(&pdata, args);
	}
	if (pdata.s == -1)
		return (-1);
	return (pdata.l);
}
