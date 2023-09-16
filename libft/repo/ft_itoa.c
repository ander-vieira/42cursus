/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 10:00:29 by andeviei          #+#    #+#             */
/*   Updated: 2023/09/16 20:45:03 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_number_len(int num)
{
	size_t	result;

	if (num == 0)
		return (1);
	result = 0;
	if (num < 0)
		result++;
	while (num != 0)
	{
		num /= 10;
		result++;
	}
	return (result);
}

static char	get_last_digit(int num)
{
	char	result;

	result = num % 10;
	if (result < 0)
		result = -result;
	return ('0' + result);
}

char	*ft_itoa(int num)
{
	char		*result;
	size_t		result_len;
	size_t		i;

	result_len = get_number_len(num);
	result = (char *)malloc(sizeof(char) * (result_len + 1));
	if (result != NULL)
	{
		if (num == 0)
			result[0] = '0';
		if (num < 0)
			result[0] = '-';
		i = 0;
		while (num != 0)
		{
			result[result_len - 1 - i] = get_last_digit(num);
			num /= 10;
			i++;
		}
		result[result_len] = '\0';
	}
	return (result);
}
