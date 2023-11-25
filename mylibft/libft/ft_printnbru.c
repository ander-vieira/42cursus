/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbru.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:39:35 by andeviei          #+#    #+#             */
/*   Updated: 2023/11/25 17:18:37 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printnbru(t_fd fd, t_ulong num, char *base)
{
	size_t	base_len;
	int		result;

	base_len = ft_strlen(base);
	if (base_len < 2)
		return (-1);
	result = 0;
	if (num > base_len)
		ft_print_addwrite(&result, ft_printnbru(fd, num / base_len, base));
	if (result == -1)
		return (-1);
	ft_print_addwrite(&result, write(fd, base + (num % base_len), 1));
	return (result);
}
