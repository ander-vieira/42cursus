/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsedirec_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 20:28:48 by andeviei          #+#    #+#             */
/*   Updated: 2023/10/19 20:26:07 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	pf_parseflags(t_direc *direc, t_print *print)
{
	direc->f = 0x00;
	while (1)
	{
		if (print->s[0] == '#')
			direc->f |= FLAG_ALTER;
		else if (print->s[0] == '+')
			direc->f |= FLAG_PLUS;
		else if (print->s[0] == ' ')
			direc->f |= FLAG_SPACE;
		else if (print->s[0] == '-')
			direc->f |= FLAG_MINUS;
		else if (print->s[0] == '0')
			direc->f |= FLAG_ZERO;
		else
			break ;
		print->s += 1;
	}
}

static void	pf_parsewidth(t_direc *direc, t_print *print)
{
	direc->w = 0;
	direc->p = 1;
	while (print->s[0] >= '0' && print->s[0] <= '9')
	{
		direc->w = direc->w * 10 + (print->s[0] - '0');
		print->s += 1;
	}
	if (print->s[0] == '.')
	{
		direc->f |= FLAG_PREC;
		direc->f &= ~FLAG_ZERO;
		print->s += 1;
		direc->p = 0;
		while (print->s[0] >= '0' && print->s[0] <= '9')
		{
			direc->p = direc->p * 10 + (print->s[0] - '0');
			print->s += 1;
		}
	}
}

t_direc	pf_parsedirec(t_print *print)
{
	t_direc	direc;

	print->s += 1;
	pf_parseflags(&direc, print);
	pf_parsewidth(&direc, print);
	direc.t = print->s[0];
	if (direc.t != '\0')
		print->s += 1;
	return (direc);
}
