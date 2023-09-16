/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:51:56 by andeviei          #+#    #+#             */
/*   Updated: 2023/09/11 19:04:40 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	return (c == ' ' || c == '\n' || c == '\t'
		|| c == '\r' || c == '\f' || c == '\v');
}

static int	get_sign(char c, int *i)
{
	if (c == '+' || c == '-')
		*i += 1;
	if (c == '-')
		return (-1);
	return (1);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	sign = get_sign(str[i], &i);
	result = 0;
	while (ft_isdigit(str[i]))
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	return (sign * result);
}
