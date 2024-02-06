/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsuffix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:58:42 by andeviei          #+#    #+#             */
/*   Updated: 2024/02/06 16:02:04 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "../libft_int.h"

t_bool	ft_strsuffix(char *str, char *suffix)
{
	size_t	str_len;
	size_t	suf_len;
	size_t	i;

	if (str == NULL || suffix == NULL)
		return (FALSE);
	str_len = ft_strlen(str);
	suf_len = ft_strlen(suffix);
	if (str_len < suf_len)
		return (FALSE);
	i = 0;
	while (i < suf_len)
	{
		if (str[str_len - suf_len + i] != suffix[i])
			return (FALSE);
		i++;
	}
	return (TRUE);
}
