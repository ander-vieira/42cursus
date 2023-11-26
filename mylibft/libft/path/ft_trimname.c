/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trimname.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 12:55:42 by andeviei          #+#    #+#             */
/*   Updated: 2023/11/26 14:57:57 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
 *	Trim a pathname to remove trailing slashes
 *	Arguments:
 *	- name: the pathname to be trimmed
 */
char	*ft_trimname(char *name)
{
	size_t	trim_len;

	trim_len = ft_strlen(name);
	while (trim_len > 1 && name[trim_len - 1] == PATH_DELIM)
		trim_len--;
	return (ft_strsub(name, trim_len));
}
