/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:02:48 by andeviei          #+#    #+#             */
/*   Updated: 2023/11/30 16:42:42 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_bool	av_getdims(t_sl *sl)
{
	(void)sl;
	return (TRUE);
}

//TODO
t_bool	av_readmap(t_sl *sl)
{
	if (!av_getdims(sl))
		return (FALSE);
	return (TRUE);
}

//TODO
void	av_freemap(t_sl *sl)
{
	(void)sl;
}
