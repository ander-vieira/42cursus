/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnbru.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 19:02:21 by andeviei          #+#    #+#             */
/*   Updated: 2023/11/26 19:14:02 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static size_t	ft_strnbru_len(t_ulong num, size_t base_len)
{
	size_t	len;

	len = 1;
	while (num >= base_len)
	{
		len++;
		num /= base_len;
	}
	return (len);
}

char	*ft_strnbru(t_ulong num, char *base)
{
	char	*result;
	size_t	len;
	size_t	base_len;
	size_t	i;

	base_len = ft_strlen(base);
	if (base_len < 2)
		return (NULL);
	len = ft_strnbru_len(num, base_len);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		result[len - i - 1] = base[num % base_len];
		num /= base_len;
	}
	result[len] = '\0';
	return (result);
}
