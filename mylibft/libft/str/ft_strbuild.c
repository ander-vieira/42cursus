/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strbuild.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 18:47:06 by andeviei          #+#    #+#             */
/*   Updated: 2024/02/06 16:01:30 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "../libft_int.h"

/*
 *	Returns a string comprised of the same character repeated a number of times.
 *
 *	Arguments:
 *	- c: the character to repeat
 *	- len: the number of characters in the string
 *
 *	Return value:
 *	- The repeated FREEABLE string
 */
char	*ft_strbuild(char c, size_t len)
{
	char	*result;
	size_t	i;

	result = (char *)malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		result[i] = c;
		i++;
	}
	result[len] = '\0';
	return (result);
}
