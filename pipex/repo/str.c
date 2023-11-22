/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:08:07 by andeviei          #+#    #+#             */
/*   Updated: 2023/11/22 17:44:15 by andeviei         ###   ########.fr       */
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

t_bool	av_strcmp(char *str1, char *str2)
{
	size_t	i;

	i = 0;
	while (str1[i] != '\0' || str2[i] != '\0')
	{
		if (str1[i] != str2[i])
			return (FALSE);
		i++;
	}
	return (TRUE);
}

char	**av_sublist(char **list, size_t len)
{
	char	**result;
	size_t	i;

	result = (char **)malloc(sizeof(char *) * (len + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		result[i] = list[i];
		i++;
	}
	result[len] = NULL;
	return (result);
}
