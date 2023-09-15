/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ander <ander@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 22:24:41 by ander             #+#    #+#             */
/*   Updated: 2023/09/16 00:10:58 by ander            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	pf_direc_char(t_pdata *pdata, va_list args)
{
	int	c;

	c = va_arg(args, int);
	if (write(STDOUT_FILENO, &c, sizeof(char)) == -1)
		pdata->s = -1;
	pdata->l += 1;
}

static void	pf_direc_int(t_pdata *pdata, va_list args)
{
	int		i;
	char	c;

	i = va_arg(args, int);
	c = '0';
	if (i >= 0 && i <= 9)
		c += i;
	if (write(STDOUT_FILENO, &c, sizeof(char)) == -1)
		pdata->s = -1;
	pdata->l += 1;
}

static void	pf_direc(t_pdata *pdata, size_t flags_len, va_list args)
{
	if (pdata->f[flags_len + 1] == 'c')
		pf_direc_char(pdata, args);
	else if (pdata->f[flags_len + 1] == 'd')
		pf_direc_int(pdata, args);
	else
	{
		if (write(STDOUT_FILENO, pdata->f, flags_len + 2) == -1)
		{
			pdata->s = -1;
			return ;
		}
		pdata->l += flags_len + 2;
	}
	pdata->f += flags_len + 2;
}
