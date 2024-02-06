/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basename.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 12:46:49 by andeviei          #+#    #+#             */
/*   Updated: 2024/02/06 16:01:05 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "../libft_int.h"

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
	char	*basename;
	char	*trimname;

	trimname = ft_trimname(name);
	if (trimname == NULL)
		return (NULL);
	if (ft_strcmp(trimname, PATH_ROOT))
		return (free(trimname), ft_strjoin(1, PATH_ROOT));
	basename = ft_strjoin(1, trimname + ft_strrchr(trimname, '/') + 1);
	return (free(trimname), basename);
}
