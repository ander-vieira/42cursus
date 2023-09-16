/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 10:43:40 by andeviei          #+#    #+#             */
/*   Updated: 2023/09/16 21:05:36 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int num, int fd)
{
	if (num < 0)
	{
		ft_putchar_fd('-', fd);
		if (num <= -10)
			ft_putnbr_fd(-(num / 10), fd);
		ft_putchar_fd('0' - (num % 10), fd);
	}
	else
	{
		if (num >= 10)
			ft_putnbr_fd(num / 10, fd);
		ft_putchar_fd('0' + (num % 10), fd);
	}
}
