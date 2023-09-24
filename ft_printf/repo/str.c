/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 14:39:45 by andeviei          #+#    #+#             */
/*   Updated: 2023/09/24 17:49:09 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	pf_strlen(char *str)
{
	size_t	len;

	len = 0;
	if (str != NULL)
	{
		while (str[len] != '\0')
			len++;
	}
	return (len);
}

void	pf_strfree(char *str)
{
	if (str != NULL)
		free(str);
}

void	pf_strcpy(char *dest, char *src)
{
	size_t	i;

	if (dest != NULL && src != NULL)
	{
		i = 0;
		while (src[i] != '\0')
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
}

char	*pf_strdup(char *str)
{
	char	*result;

	result = malloc(pf_strlen(str) + 1);
	if (result != NULL)
		pf_strcpy(result, str);
	return (result);
}

char	*pf_strjoin(char *str1, char *str2)
{
	char	*result;
	size_t	len1;

	len1 = pf_strlen(str1);
	result = malloc(len1 + pf_strlen(str2) + 1);
	if (result != NULL)
	{
		pf_strcpy(result, str1);
		pf_strcpy(result + len1, str2);
	}
	pf_strfree(str1);
	pf_strfree(str2);
	return (result);
}
