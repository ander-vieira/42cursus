/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsedirec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 16:25:36 by andeviei          #+#    #+#             */
/*   Updated: 2023/09/24 18:03:15 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	pf_parseflags(t_direc *direc, t_pdata *pdata)
{
	while (*(pdata->f) != '\0')
	{
		if (*(pdata->f) == '-')
			direc->f |= FLAG_LEFT;
		else if (*(pdata->f) == '0')
			direc->f |= FLAG_ZERO;
		else if (*(pdata->f) == '#')
			direc->f |= FLAG_ALTER;
		else if (*(pdata->f) == ' ')
			direc->f |= FLAG_BLANK;
		else if (*(pdata->f) == '+')
			direc->f |= FLAG_SIGN;
		else
			break ;
		(pdata->f)++;
	}
}

static void	pf_parsewidth(t_direc *direc, t_pdata *pdata)
{
	direc->w = pf_strreadint(&(pdata->f));
	if (*(pdata->f) == '.')
	{
		(pdata->f)++;
		direc->f |= FLAG_PREC;
		direc->p = pf_strreadint(&(pdata->f));
	}
	else
		direc->p = 0;
}

void	pf_parsedirec(t_direc *direc, t_pdata *pdata)
{
	direc->f = 0x00;
	(pdata->f)++;
	pf_parseflags(direc, pdata);
	pf_parsewidth(direc, pdata);
	direc->t = *(pdata->f);
	(pdata->f)++;
	if (pdata->f[0] == '\0')
		pdata->s = 0;
}
