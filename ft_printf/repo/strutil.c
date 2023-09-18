/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strutil.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 22:13:14 by andeviei          #+#    #+#             */
/*   Updated: 2023/09/18 17:46:55 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	pf_findchar(const char *str, char c, size_t *len)
{
	*len = 0;
	while (str[*len] != '\0')
	{
		if (str[*len] == c)
			return (1);
		(*len)++;
	}
	return (0);
}

char	pf_findnotchar(const char *str, const char *charset, size_t *len)
{
	size_t	i;

	*len = 0;
	while (str[*len] != '\0')
	{
		i = 0;
		while (charset[i] != '\0' && charset[i] != str[*len])
			i++;
		if (charset[i] == '\0')
			return (1);
		(*len)++;
	}
	return (0);
}
