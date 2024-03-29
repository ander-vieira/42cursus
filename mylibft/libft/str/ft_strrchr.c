/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:26:32 by andeviei          #+#    #+#             */
/*   Updated: 2024/02/06 16:01:52 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "../libft_int.h"

ssize_t	ft_strrchr(char *str, char c)
{
	ssize_t	i;
	ssize_t	result;

	result = -1;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			result = i;
		i++;
	}
	return (result);
}
