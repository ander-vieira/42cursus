/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dirname.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 12:41:19 by andeviei          #+#    #+#             */
/*   Updated: 2023/11/26 15:02:02 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
 *	Get the path to the directory containing the given pathname
 *
 *	Arguments:
 *	- name: the pathname
 *
 *	Examples:
 *	- "/home/user/" returns "/home"
 */
char	*ft_dirname(char *name)
{
	char	*trimname;
	ssize_t	slash_len;

	trimname = ft_trimname(name);
	if (trimname == NULL)
		return (NULL);
	slash_len = ft_strrchr(trimname, PATH_DELIM);
	if (slash_len == -1)
		return (ft_strdup(PATH_CURRENT));
	if (slash_len == 0)
		return (ft_strdup(PATH_ROOT));
	return (ft_strsub(trimname, slash_len));
}
