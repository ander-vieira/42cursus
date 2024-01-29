/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:29:50 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/29 18:41:21 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	end_game(t_uint	status)
{
	if (status == END_WIN)
		ft_printf(STDOUT_FILENO, "YOU WIN... FOR NOW\n");
	else if (status == END_CLOSE)
		ft_printf(STDOUT_FILENO, "WHY QUIT? ARE YOU SCARED?\n");
	map_free(g_sl()->map);
	exit(0);
}
