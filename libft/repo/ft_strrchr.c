/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:06:17 by andeviei          #+#    #+#             */
/*   Updated: 2023/09/16 20:58:14 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t	i;
	char	*result;

	i = 0;
	result = NULL;
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			result = ((char *)str + i);
		i++;
	}
	if ((char)c == '\0')
		result = ((char *)str + i);
	return (result);
}
