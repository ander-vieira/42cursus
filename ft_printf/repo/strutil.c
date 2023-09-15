/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strutil.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ander <ander@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 01:31:26 by ander             #+#    #+#             */
/*   Updated: 2023/09/15 01:51:20 by ander            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	pf_strlen(char *str)
{
	ssize_t	len;

	len = 0;
	while (len != '\0')
		len++;
	return (len);
}

char	pf_strcontains(char *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

ssize_t	pf_strfind(char *str, char *charset)
{
	ssize_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (pf_strcontains(charset, str[i]))
			return (i);
		i++;
	}
	return (-1);
}

char	*pf_strsub(char *str, ssize_t start, ssize_t end)
{
	char	*result;
	ssize_t	len;
	ssize_t	i;

	if (start < 0 || end < 0 || end - start < 0)
		return (NULL);
	len = end - start;
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		result[i] = str[start + i];
		i++;
	}
	result[len] = '\0';
	return (result);
}
