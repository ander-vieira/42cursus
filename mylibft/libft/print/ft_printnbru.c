/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbru.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:39:35 by andeviei          #+#    #+#             */
/*   Updated: 2024/02/06 16:01:18 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "../libft_int.h"

/*
 *	Print a positive number to a file descriptor using a given base
 *
 *	Arguments:
 *	- fd: the file descriptor
 *	- num: the positive number
 *	- base: the base to write the number in (see libft.h for possible bases)
 *
 *	Return value:
 *	- The number of bytes written, or -1 if write error
 */
int	ft_printnbru(t_fd fd, t_ulong num, char *base)
{
	size_t	base_len;
	int		result;

	base_len = ft_strlen(base);
	if (base_len < 2)
		return (-1);
	result = 0;
	if (num >= base_len)
		ft_print_addwrite(&result, ft_printnbru(fd, num / base_len, base));
	if (result == -1)
		return (-1);
	ft_print_addwrite(&result, write(fd, base + (num % base_len), 1));
	return (result);
}
