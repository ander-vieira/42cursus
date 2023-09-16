/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:17:31 by andeviei          #+#    #+#             */
/*   Updated: 2023/09/16 20:33:20 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_memrcpy(void *dest, const void *src, size_t len)
{
	size_t	i;

	i = len - 1;
	while (i + 1 > 0)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i--;
	}
}

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	if (dest == NULL && src == NULL && len != 0)
		return (NULL);
	if (dest < src || src + len <= dest)
		ft_memcpy(dest, src, len);
	else if (dest != src)
		ft_memrcpy(dest, src, len);
	return (dest);
}
