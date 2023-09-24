/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 14:55:51 by andeviei          #+#    #+#             */
/*   Updated: 2023/09/24 19:15:06 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*pf_strfill(char c, size_t len)
{
	char	*result;
	size_t	i;

	result = malloc(len + 1);
	if (result != NULL)
	{
		i = 0;
		while (i < len)
		{
			result[i] = c;
			i++;
		}
		result[len] = '\0';
	}
	return (result);
}

char	*pf_strupper(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		i++;
	}
	return (str);
}

char	*pf_strsign(long num, t_flag flags)
{
	char	*result;

	if (num < 0)
		result = pf_strfill('-', 1);
	else if (flags & FLAG_SIGN)
		result = pf_strfill('+', 1);
	else if (flags & FLAG_BLANK)
		result = pf_strfill(' ', 1);
	else
		result = pf_strdup("");
	return (result);
}

static size_t	numlen(long num, int base_l, int min)
{
	size_t	len;

	if (num == 0 && min != 0)
		return (1);
	len = 0;
	while ((int)len < min || num != 0)
	{
		num /= base_l;
		len++;
	}
	return (len);
}

char	*pf_strnum(long num, char *base, int min)
{
	char	*result;
	int		base_l;
	size_t	len;
	size_t	i;

	if (num < 0)
		num *= -1;
	base_l = pf_strlen(base);
	len = numlen(num, base_l, min);
	result = malloc(len + 1);
	if (result != NULL)
	{
		i = 0;
		while (i < len)
		{
			result[len - 1 - i] = base[num % base_l];
			num /= base_l;
			i++;
		}
		result[len] = '\0';
	}
	return (result);
}
