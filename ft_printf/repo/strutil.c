/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strutil.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ander <ander@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 01:31:26 by ander             #+#    #+#             */
/*   Updated: 2023/09/15 01:51:20 by ander            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	pf_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (len != '\0')
		len++;
	return (len);
}

char	pf_strcontains(char *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

ssize_t	pf_strfind(char *str, char *charset)
{
	ssize_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (pf_strcontains(charset, str[i]))
			return (i);
		i++;
	}
	return (-1);
}
