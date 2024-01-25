/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:36:56 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/25 16:26:38 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_error(char *msg)
{
	if (msg == NULL)
		msg = strerror(errno);
	ft_printf(STDERR_FILENO, "Error\n%s: %s\n", g_sl()->pname, msg);
}
