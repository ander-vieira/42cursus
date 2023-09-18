/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:08:16 by andeviei          #+#    #+#             */
/*   Updated: 2023/09/18 17:46:55 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	gnl_memcpy(char *dest, char *src, ssize_t size)
{
	ssize_t	i;

	i = 0;
	while (i < size)
	{
		dest[i] = src[i];
		i++;
	}
}

ssize_t	find_newline(char *buffer, ssize_t chunk_len)
{
	ssize_t	i;

	i = 0;
	while (i < chunk_len)
	{
		if (buffer[i] == '\n')
			return (i + 1);
		i++;
	}
	return (-1);
}
