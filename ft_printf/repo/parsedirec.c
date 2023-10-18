/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsedirec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 20:28:48 by andeviei          #+#    #+#             */
/*   Updated: 2023/10/18 20:32:24 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_direc	pf_parsedirec(t_print *print)
{
	t_direc	result;

	result.t = print->f[1];
	if (print->f[1] == '\0')
		print->f += 2;
	else
		print->f += 1;
	return result;
}