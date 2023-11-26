/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dirname.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 12:41:19 by andeviei          #+#    #+#             */
/*   Updated: 2023/11/26 14:28:11 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_dirname(char *name)
{
	char	*trimname;
	ssize_t	slash_len;

	trimname = ft_trimname(name);
	if (trimname == NULL)
		return (NULL);
	slash_len = ft_strrchr(trimname, '/');
	if (slash_len == -1)
		return (ft_strdup("."));
	if (slash_len == 0)
		return (ft_strdup("/"));
	return (ft_strsub(trimname, slash_len));
}