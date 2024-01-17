/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 10:31:42 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/17 16:58:50 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *str, void (*fun)(unsigned int, char*))
{
	unsigned int	i;

	if (str != NULL && fun != NULL)
	{
		i = 0;
		while (str[i] != '\0')
		{
			fun(i, (char *)str + i);
			i++;
		}
	}
}
