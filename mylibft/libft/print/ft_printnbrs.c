/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbrs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:39:35 by andeviei          #+#    #+#             */
/*   Updated: 2024/02/06 16:01:16 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "../libft_int.h"

/*
 *	Print a signed (+/-) number to a file descriptor using a given base
 *
 *	Arguments:
 *	- fd: the file descriptor
 *	- num: the signed number
 *	- base: the base to write the number in (see libft.h for possible bases)
 *
 *	Return value:
 *	- The number of bytes written, or -1 if write error
 */
int	ft_printnbrs(t_fd fd, long num, char *base)
{
	int	result;

	result = 0;
	if (num < 0)
		ft_print_addwrite(&result, write(fd, "-", 1));
	if (result == -1)
		return (-1);
	ft_print_addwrite(&result, ft_printnbru(fd, ft_abs(num), base));
	return (result);
}
