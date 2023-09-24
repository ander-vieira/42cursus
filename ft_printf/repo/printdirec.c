/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printdirec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 22:24:41 by andeviei          #+#    #+#             */
/*   Updated: 2023/09/24 16:38:52 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*pf_printnbr(t_direc direc, va_list args)
{
	char	*str;
	long	num;

	if (direc.t == 'u')
		str = pf_strnum(va_arg(args, unsigned int), BASE_DEC);
	else if (direc.t == 'x' || direc.t == 'X')
	{
		num = va_arg(args, unsigned int);
		str = pf_strnum(num, BASE_HEX);
		if ((direc.f & FLAG_ALTER) && num != 0)
			str = pf_strjoin(pf_strdup(PREFIX_HEX), str);
		if (direc.t == 'X')
			str = pf_strupper(str);
	}
	else
	{
		num = va_arg(args, int);
		str = pf_strjoin(pf_strsign(num, direc.f), pf_strnum(num, BASE_DEC));
	}
	return (str);
}

static char	*pf_printptr(void *ptr)
{
	if (ptr == NULL)
		return (pf_strdup(PTR_NULL));
	return (pf_strjoin(pf_strdup(PREFIX_HEX), pf_strnum((long)ptr, BASE_HEX)));
}

static char	*pf_padstr(char *str, t_direc direc)
{
	direc.f++;
	return (str);
}

void	pf_printdirec(t_direc direc, t_pdata *pdata, va_list args)
{
	char	*str;
	ssize_t	len;

	if (direc.t == 'c')
		str = pf_strchar(va_arg(args, int));
	else if (direc.t == 's')
		str = pf_strdup(va_arg(args, char *));
	else if (direc.t == 'd' || direc.t == 'i' || direc.t == 'u'
		|| direc.t == 'x' || direc.t == 'X')
		str = pf_printnbr(direc, args);
	else if (direc.t == 'p')
		str = pf_printptr(va_arg(args, void *));
	else if (direc.t == '%')
		str = pf_strchar('%');
	else
		str = pf_strjoin(pf_strchar('%'), pf_strchar(direc.t));
	str = pf_padstr(str, direc);
	len = write(STDOUT_FILENO, str, pf_strlen(str));
	pf_strfree(str);
	if (len == -1)
		pdata->s = -1;
	pdata->l += len;
}
