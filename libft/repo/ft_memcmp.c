/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:06:17 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/26 10:30:31 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *mem1, const void *mem2, size_t len)
{
	size_t	i;

	if (len == 0 || (mem1 == NULL && mem2 == NULL))
		return (0);
	i = 0;
	while (i + 1 < len
		&& ((unsigned char *)mem1)[i] == ((unsigned char *)mem2)[i])
	{
		i++;
	}
	return ((int)(((unsigned char *)mem1)[i])
		- (int)(((unsigned char *)mem2)[i]));
}
