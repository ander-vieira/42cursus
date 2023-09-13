/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:08:16 by andeviei          #+#    #+#             */
/*   Updated: 2023/09/13 10:08:16 by andeviei         ###   ########.fr       */
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
