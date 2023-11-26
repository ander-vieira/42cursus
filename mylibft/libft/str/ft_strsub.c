/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:20:10 by andeviei          #+#    #+#             */
/*   Updated: 2023/11/26 15:04:16 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
 *	Returns a freeable substring of the given size from the given string
 *
 *	Arguments:
 *	- str: the given string (substring is taken from the beginning)
 *	- len: the size of the substring
 */
char	*ft_strsub(char *str, size_t len)
{
	char	*sub;
	size_t	str_len;

	if (str == NULL)
		return (NULL);
	str_len = ft_strlen(str);
	if (str_len < len)
		len = str_len;
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (sub == NULL)
		return (NULL);
	ft_memcpy(sub, str, len);
	sub[len] = '\0';
	return (sub);
}
