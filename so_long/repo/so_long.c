/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 12:41:12 by andeviei          #+#    #+#             */
/*   Updated: 2023/10/10 12:41:12 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc == 2 && sl_strends(argv[1]))
	{
		game = sl_parsegame(argv[1]);
		sl_freegame(game);
	}
	else
		sl_putstr("Error\n");
	return (0);
}
