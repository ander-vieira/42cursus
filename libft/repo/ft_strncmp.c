/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 11:42:46 by andeviei          #+#    #+#             */
/*   Updated: 2023/09/16 20:39:17 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t len)
{
	size_t	i;

	if (len == 0)
		return (0);
	i = 0;
	while (i + 1 < len && ((unsigned char *)str1)[i] != '\0'
		&& ((unsigned char *)str1)[i] == ((unsigned char *)str2)[i])
	{
		i++;
	}
	return ((int)(((unsigned char *)str1)[i])
		- (int)(((unsigned char *)str2)[i]));
}
