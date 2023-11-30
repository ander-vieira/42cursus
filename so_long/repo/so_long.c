/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:28:48 by andeviei          #+#    #+#             */
/*   Updated: 2023/11/30 17:22:20 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_bool	av_validargs(int argc, char **argv, t_sl *sl)
{
	sl->pname = argv[0];
	if (argc != 2)
		return (av_printerror(sl->pname, NULL,
				"Program must have exactly one argument"), FALSE);
	sl->mapname = argv[1];
	if (!ft_strsuffix(sl->mapname, MAP_SUFFIX))
		return (av_printerror(sl->pname, NULL,
				"Argument must have the .ber extension"), FALSE);
	return (TRUE);
}

int	main(int argc, char **argv)
{
	t_sl	sl;

	if (av_validargs(argc, argv, &sl) && av_readmap(&sl))
		av_initmlx(&sl);
	return (EXIT_FAILURE);
}
