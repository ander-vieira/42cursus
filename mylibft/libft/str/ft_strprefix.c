/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strprefix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:29:25 by andeviei          #+#    #+#             */
/*   Updated: 2023/11/26 16:57:37 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
 *	Check if a string starts with a given prefix
 *
 *	Arguments:
 *	- str: the string
 *	- prefix: the prefix
 *
 *	Return value:
 *	- TRUE if the string starts with the prefix, FALSE otherwise
 */
t_bool	ft_strprefix(char *str, char *prefix)
{
	size_t	str_len;
	size_t	pref_len;
	size_t	i;

	if (str == NULL || prefix == NULL)
		return (FALSE);
	str_len = ft_strlen(str);
	pref_len = ft_strlen(prefix);
	if (str_len < pref_len)
		return (FALSE);
	i = 0;
	while (i < pref_len)
	{
		if (str[i] != prefix[i])
			return (FALSE);
		i++;
	}
	return (TRUE);
}
