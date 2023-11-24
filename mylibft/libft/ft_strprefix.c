/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strprefix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:29:25 by andeviei          #+#    #+#             */
/*   Updated: 2023/11/24 14:32:59 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	av_strprefix(char *str, char *prefix)
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
