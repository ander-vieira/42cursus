/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basename.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 12:46:49 by andeviei          #+#    #+#             */
/*   Updated: 2023/11/26 14:49:06 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

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