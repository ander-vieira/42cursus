/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:48:56 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/02 15:56:01 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_bool	av_validargs(int argc, char **argv, t_sl *sl)
{
	sl->pname = argv[0];
	if (argc != 2)
		return (av_printerror(sl,
				"Program must have exactly one argument"), FALSE);
	sl->mapname = argv[1];
	if (!ft_strsuffix(sl->mapname, MAP_SUFFIX))
		return (av_printerror(sl,
				"Filename must have the .ber extension"), FALSE);
	return (TRUE);
}
