/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 09:40:30 by andeviei          #+#    #+#             */
/*   Updated: 2024/02/19 14:33:00 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char c, const char *charset)
{
	size_t	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(const char *str, const char *charset)
{
	char	*result;
	size_t	str_len;
	size_t	start;
	size_t	end;

	if (str == NULL || charset == NULL)
		return (NULL);
	str_len = ft_strlen(str);
	start = 0;
	while (start < str_len && is_in_set(str[start], charset))
		start++;
	end = str_len;
	while (end > start && is_in_set(str[end - 1], charset))
		end--;
	result = (char *)malloc(sizeof(char) * (end - start + 1));
	if (result != NULL)
	{
		ft_memcpy(result, str + start, end - start);
		result[end - start] = '\0';
	}
	return (result);
}
