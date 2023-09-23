/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 11:52:45 by andeviei          #+#    #+#             */
/*   Updated: 2023/09/23 18:30:09 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

ssize_t	pf_putchar(char c)
{
	return (write(STDOUT_FILENO, &c, sizeof(char)));
}

ssize_t	pf_putstr(char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (write(STDOUT_FILENO, str, sizeof(char) * len));
}

ssize_t	pf_putsign(int num)
{
	ssize_t	len;

	len = 0;
	if (num < 0)
		len += pf_putchar('-');
	return (len);
}

ssize_t	pf_putnbr_base(long num, char *base)
{
	ssize_t	len;
	int		base_l;

	base_l = 0;
	while (base[base_l] != '\0')
		base_l++;
	len = 0;
	if (num < 0)
	{
		if (num <= -base_l)
			len += pf_putnbr_base(-(num / base_l), base);
		len += pf_putchar(base[-(num % base_l)]);
	}
	else
	{
		if (num >= base_l)
			len += pf_putnbr_base(num / base_l, base);
		len += pf_putchar(base[num % base_l]);
	}
	return (len);
}
