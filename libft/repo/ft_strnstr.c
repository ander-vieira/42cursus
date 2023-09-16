/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:06:17 by andeviei          #+#    #+#             */
/*   Updated: 2023/09/16 20:54:35 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *h, const char *n, size_t len)
{
	size_t	i;
	size_t	n_len;
	size_t	h_len;

	if (len == 0 && h == NULL)
		return (NULL);
	n_len = ft_strlen(n);
	if (n_len == 0)
		return ((char *)h);
	h_len = ft_strlen(h);
	i = 0;
	while (i + n_len <= len && i + n_len <= h_len)
	{
		if (!ft_strncmp(h + i, n, n_len))
			return ((char *)h + i);
		i++;
	}
	return (NULL);
}
