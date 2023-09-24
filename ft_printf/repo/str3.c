/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 17:31:52 by andeviei          #+#    #+#             */
/*   Updated: 2023/09/24 18:04:48 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	pf_strreadint(char **str)
{
	int	i;

	i = 0;
	while (**str >= '0' && **str <= '9')
	{
		i = i * 10 + (**str - '0');
		(*str)++;
	}
	return (i);
}

char	*pf_strpad(char *str, t_direc direc)
{
	int	pad;

	pad = direc.w - pf_strlen(str);
	if (pad > 0)
	{
		if (direc.f & FLAG_LEFT)
			str = pf_strjoin(str, pf_strfill(' ', pad));
		else if ((direc.f & FLAG_ZERO) && direc.p == 0)
			str = pf_strjoin(pf_strfill('0', pad), str);
		else
			str = pf_strjoin(pf_strfill(' ', pad), str);
	}
	return (str);
}

char	*pf_strcut(char *str, int len)
{
	char	*result;
	int		i;

	if ((int)pf_strlen(str) < len)
		return (str);
	result = malloc(len + 1);
	if (result != NULL)
	{
		i = 0;
		while (i < len)
		{
			result[i] = str[i];
			i++;
		}
		result[len] = '\0';
	}
	pf_strfree(str);
	return (result);
}
