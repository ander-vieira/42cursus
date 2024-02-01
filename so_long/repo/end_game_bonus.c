/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:29:50 by andeviei          #+#    #+#             */
/*   Updated: 2024/02/01 17:30:42 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	end_game(t_uint	status)
{
	if (status == END_WIN)
		ft_printf(STDOUT_FILENO, "YOU WIN... FOR NOW\n");
	else if (status == END_CLOSE)
		ft_printf(STDOUT_FILENO, "WHY QUIT? ARE YOU SCARED?\n");
	else if (status == END_LOSE)
		ft_printf(STDOUT_FILENO, "GAME OVER, YOU LOSER!\n");
	map_free(g_sl()->map);
	exit(0);
}
