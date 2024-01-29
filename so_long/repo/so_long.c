/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:28:48 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/29 18:43:28 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_sl	*g_sl(void)
{
	static t_sl	sl;

	return (&sl);
}

static t_bool	validate_args(int argc, char **argv)
{
	g_sl()->pname = argv[0];
	if (argc != 2)
		return (print_error("Program must have exactly one argument"), FALSE);
	g_sl()->mapname = argv[1];
	if (!ft_strsuffix(g_sl()->mapname, MAP_SUFFIX))
		return (print_error("Filename must have the .ber extension"), FALSE);
	return (TRUE);
}

int	main(int argc, char **argv)
{
	if (!validate_args(argc, argv) || !read_map() || !validate_map())
		return (map_free(g_sl()->map), EXIT_FAILURE);
	init_mlx();
	return (EXIT_FAILURE);
}
