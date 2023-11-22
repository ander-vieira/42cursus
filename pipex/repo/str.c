/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:08:07 by andeviei          #+#    #+#             */
/*   Updated: 2023/11/22 16:20:28 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	px_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

t_bool	px_strstarts(char *str, char *pref)
{
	size_t	str_len;
	size_t	pref_len;
	size_t	i;

	str_len = px_strlen(str);
	pref_len = px_strlen(pref);
	if (str_len < pref_len)
		return (FALSE);
	i = 0;
	while (i < pref_len)
	{
		if (str[i] != pref[i])
			return (FALSE);
		i++;
	}
	return (TRUE);
}

void	px_strncpy(char *dst, char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
}

char	*px_strjoin(char *str1, char *str2)
{
	char	*result;
	size_t	len1;
	size_t	len2;

	len1 = px_strlen(str1);
	len2 = px_strlen(str2);
	result = (char *)malloc(sizeof(char) * (len1 + len2 + 2));
	if (result == NULL)
		return (NULL);
	px_strncpy(result, str1, len1);
	result[len1] = PATH_DELIM;
	px_strncpy(result + len1 + 1, str2, len2);
	result[len1 + len2 + 1] = '\0';
	return (result);
}
