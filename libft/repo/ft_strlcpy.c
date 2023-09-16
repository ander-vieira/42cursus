/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:17:31 by andeviei          #+#    #+#             */
/*   Updated: 2023/09/16 20:38:44 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(const char *dest, const char *src, size_t len)
{
	size_t	i;
	size_t	src_len;

	src_len = ft_strlen(src);
	i = 0;
	while (i < len && i <= src_len)
	{
		if (i < len - 1)
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		else
			((unsigned char *)dest)[i] = '\0';
		i++;
	}
	return (src_len);
}
