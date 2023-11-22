/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:08:07 by andeviei          #+#    #+#             */
/*   Updated: 2023/11/22 16:36:10 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	av_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

t_bool	av_strstarts(char *str, char *pref)
{
	size_t	str_len;
	size_t	pref_len;
	size_t	i;

	str_len = av_strlen(str);
	pref_len = av_strlen(pref);
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

void	av_strncpy(char *dst, char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
}

char	*av_strjoin(char *str1, char *str2)
{
	char	*result;
	size_t	len1;
	size_t	len2;

	len1 = av_strlen(str1);
	len2 = av_strlen(str2);
	result = (char *)malloc(sizeof(char) * (len1 + len2 + 2));
	if (result == NULL)
		return (NULL);
	av_strncpy(result, str1, len1);
	result[len1] = PATH_DELIM;
	av_strncpy(result + len1 + 1, str2, len2);
	result[len1 + len2 + 1] = '\0';
	return (result);
}
