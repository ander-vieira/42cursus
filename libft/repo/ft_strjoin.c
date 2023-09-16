/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 09:33:12 by andeviei          #+#    #+#             */
/*   Updated: 2023/09/16 20:46:15 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *str1, const char *str2)
{
	char	*result;
	size_t	len1;
	size_t	len2;

	if (str1 == NULL || str2 == NULL)
		return (NULL);
	len1 = ft_strlen(str1);
	len2 = ft_strlen(str2);
	result = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (result != NULL)
	{
		ft_memcpy(result, str1, len1);
		ft_memcpy(result + len1, str2, len2);
		result[len1 + len2] = '\0';
	}
	return (result);
}
