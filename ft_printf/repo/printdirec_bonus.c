/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printdirec_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:07:22 by andeviei          #+#    #+#             */
/*   Updated: 2023/10/30 12:33:20 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	pf_printpercent(t_direc direc, t_print *print)
{
	if (!(direc.f & FLAG_MINUS))
		pf_putpad(' ', direc.w, 1, print);
	pf_putchar('%', print);
	if (direc.f & FLAG_MINUS)
		pf_putpad(' ', direc.w, 1, print);
}

void	pf_printdirec(t_direc direc, t_print *print)
{
	if (direc.t == 'c')
		pf_printchar(direc, print);
	else if (direc.t == 's')
		pf_printstr(direc, print);
	else if (direc.t == 'd' || direc.t == 'i')
		pf_printnbr(direc, print);
	else if (direc.t == 'u')
		pf_printunbr(direc, print, BASE_DEC, "");
	else if (direc.t == 'x')
		pf_printunbr(direc, print, BASE_HEXL, PRE_HEXL);
	else if (direc.t == 'X')
		pf_printunbr(direc, print, BASE_HEXU, PRE_HEXU);
	else if (direc.t == 'p')
		pf_printptr(direc, print);
	else if (direc.t == '%')
		pf_printpercent(direc, print);
	else
	{
		pf_putchar('%', print);
		pf_putchar(direc.t, print);
	}
}
