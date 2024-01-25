/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:48:56 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/25 16:34:22 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_bool	validate_args(int argc, char **argv)
{
	g_sl()->pname = argv[0];
	if (argc != 2)
		return (print_error("Program must have exactly one argument"), FALSE);
	g_sl()->mapname = argv[1];
	if (!ft_strsuffix(g_sl()->mapname, MAP_SUFFIX))
		return (print_error("Filename must have the .ber extension"), FALSE);
	return (TRUE);
}
