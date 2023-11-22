/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:28:48 by andeviei          #+#    #+#             */
/*   Updated: 2023/11/09 17:43:33 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_bool	sl_validargs(int argc, char **argv)
{
	if (argc != 2)
		return (sl_printerr(ERR_USAGE), FALSE);
	if (!sl_strends(argv[1], MAP_SUF))
		return (sl_printerr(ERR_EXT), FALSE);
	return (TRUE);
}

int	main(int argc, char **argv)
{
	t_sl	sl;

	if (sl_validargs(argc, argv) && sl_readfile(argv[1], &(sl.map))
		&& sl_validmap(&(sl.map)))
		sl_initmlx(&sl);
	return (0);
}
