/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbrs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:39:35 by andeviei          #+#    #+#             */
/*   Updated: 2023/11/25 17:10:27 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
