/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:19:57 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/10 17:37:19 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static t_bool	ft_strsplit_ischar(char c, void *ctx)
{
	return (c == *((char *)ctx));
}

char	**ft_strsplit(char *str, char c)
{
	return (ft_strsplit_magic(str, &ft_strsplit_ischar, &c));
}
