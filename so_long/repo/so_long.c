/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:28:48 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/25 19:19:45 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_sl	*g_sl(void)
{
	static t_sl	sl;

	return (&sl);
}

int	main(int argc, char **argv)
{
	if (!validate_args(argc, argv) || !read_map() || !validate_map())
		return (map_free(g_sl()->map), EXIT_FAILURE);
	init_mlx();
	return (EXIT_FAILURE);
}
