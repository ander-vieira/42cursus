/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 10:31:42 by andeviei          #+#    #+#             */
/*   Updated: 2023/09/16 20:46:12 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *str, char (*fun)(unsigned int, char))
{
	char	*result;
	size_t	str_len;
	size_t	i;

	if (str == NULL || fun == NULL)
		return (NULL);
	str_len = ft_strlen(str);
	result = (char *)malloc(sizeof(char) * (str_len + 1));
	if (result != NULL)
	{
		i = 0;
		while (i < str_len)
		{
			result[i] = fun(i, str[i]);
			i++;
		}
		result[str_len] = '\0';
	}
	return (result);
}
