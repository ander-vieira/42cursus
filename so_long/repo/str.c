/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 12:59:48 by andeviei          #+#    #+#             */
/*   Updated: 2023/10/10 12:59:48 by andeviei         ###   ########.fr       */
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

char	sl_strends(char *str, char *end)
{
	size_t	str_len;
	size_t	end_len;
	size_t	i;

	str_len = sl_strlen(str);
	end_len = sl_strlen(end);
	i = 0;
	while (i < end_len)
	{
		if (str[str_len - end_len + i] != end[i])
			return (0);
		i++;
	}
	return (1);
}
