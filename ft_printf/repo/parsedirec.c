/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsedirec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 20:28:48 by andeviei          #+#    #+#             */
/*   Updated: 2023/10/19 14:37:30 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_direc	pf_parsedirec(t_print *print)
{
	t_direc	result;

	result.t = print->s[1];
	if (result.t != '\0')
		print->s += 2;
	else
		print->s += 1;
	return (result);
}
