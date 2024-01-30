/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:36:56 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/30 17:39:01 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	print_error(char *msg)
{
	if (msg == NULL)
		msg = strerror(errno);
	ft_printf(STDERR_FILENO, "Error\n%s: %s\n", g_sl()->pname, msg);
}
