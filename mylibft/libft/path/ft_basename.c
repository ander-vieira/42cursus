/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basename.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 12:46:49 by andeviei          #+#    #+#             */
/*   Updated: 2023/11/26 15:06:30 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
 *	Get the base name (without the directory part) of the given pathname
 *
 *	Arguments:
 *	- name: the pathname
 *
 *	Return value:
 *	- The base name as a FREEABLE string
 *
 *	Examples:
 *	- "/home/user/" returns "user"
 */
char	*ft_basename(char *name)
{
	char	*trimname;

	trimname = ft_trimname(name);
	if (trimname == NULL)
		return (NULL);
	if (ft_strcmp(trimname, PATH_ROOT))
		return (ft_strdup(PATH_ROOT));
	return (ft_strdup(trimname + ft_strrchr(trimname, '/') + 1));
}
