/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ander <ander@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 00:18:49 by ander             #+#    #+#             */
/*   Updated: 2023/09/15 23:58:58 by ander            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	init_pdata(t_pdata *pdata, const char *format)
{
	pdata->f = (char *)format;
	pdata->l = 0;
	pdata->s = 1;
}

static void	parse_text(t_pdata *pdata)
{
	size_t	len;
	char	result;

	result = pf_findchar(pdata->f, DIREC_START, &len);
	if (write(STDOUT_FILENO, pdata->f, len) == -1)
	{
		pdata->s = -1;
		return ;
	}
	pdata->f += len;
	pdata->l += len;
	if (result == 0)
		pdata->s = 0;
}

static void	parse_direc(t_pdata *pdata, va_list args)
{
	size_t	flags_len;

	if (!pf_findnotchar(pdata->f + 1, DIREC_FLAG, &flags_len))
	{
		write(STDOUT_FILENO, "%", 1);
		pdata->f += 1;
		pdata->l += 1;
		return ;
	}
	pf_direc(pdata, flags_len, args);
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
