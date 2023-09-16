/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 19:11:33 by andeviei          #+#    #+#             */
/*   Updated: 2023/09/16 20:45:26 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	str_len;
	char	*result;
	size_t	i;

	str_len = ft_strlen(str);
	result = malloc(str_len + 1);
	if (result != NULL)
	{
		i = 0;
		while (i <= str_len)
		{
			result[i] = str[i];
			i++;
		}
	}
	return (result);
}
