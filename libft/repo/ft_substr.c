/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 09:17:16 by andeviei          #+#    #+#             */
/*   Updated: 2023/09/16 20:46:39 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*result;
	size_t	str_len;
	size_t	result_len;

	if (str == NULL)
		return (NULL);
	str_len = ft_strlen(str);
	if (start >= str_len)
		result_len = 0;
	else
		result_len = str_len - start;
	if (len < result_len)
		result_len = len;
	result = (char *)malloc(sizeof(char) * (result_len + 1));
	if (result != NULL)
	{
		ft_memcpy(result, str + start, result_len);
		result[result_len] = '\0';
	}
	return (result);
}
