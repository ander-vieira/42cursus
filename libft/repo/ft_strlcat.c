/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:17:31 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/17 16:42:41 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_null(const char *str, size_t len)
{
	if (len == 0 && str == NULL)
		return (0);
	return (ft_strlen(str));
}

size_t	ft_strlcat(char *dest, const char *src, size_t len)
{
	size_t	i;
	size_t	dest_len;
	size_t	src_len;

	dest_len = ft_strlen_null(dest, len);
	src_len = ft_strlen_null(src, len);
	i = 0;
	while (i + dest_len < len && i <= src_len)
	{
		if (i + dest_len < len - 1)
			((unsigned char *)dest)[i + dest_len] = ((unsigned char *)src)[i];
		else
			((unsigned char *)dest)[i + dest_len] = '\0';
		i++;
	}
	if (dest_len < len)
		return (dest_len + src_len);
	else
		return (len + src_len);
}
