/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trimname.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 12:55:42 by andeviei          #+#    #+#             */
/*   Updated: 2023/11/26 14:48:35 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
 *	Trim path name to remove unnecessary slashes
 */
char	*ft_trimname(char *name)
{
	size_t	trim_len;

	trim_len = ft_strlen(name);
	while (trim_len > 1 && name[trim_len - 1] == PATH_DELIM)
		trim_len--;
	return (ft_strsub(name, trim_len));
}
