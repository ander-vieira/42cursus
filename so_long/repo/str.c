/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 19:50:28 by andeviei          #+#    #+#             */
/*   Updated: 2023/11/04 19:56:46 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	sl_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	sl_strends(char *str, char *suf)
{
	size_t	str_len;
	size_t	suf_len;
	size_t	i;

	str_len = sl_strlen(str);
	suf_len = sl_strlen(suf);
	if (suf_len > str_len)
		return (0);
	i = 0;
	while (i < suf_len)
	{
		if (str[str_len - suf_len + i] != suf[i])
			return (0);
		i++;
	}
	return (1);
}
