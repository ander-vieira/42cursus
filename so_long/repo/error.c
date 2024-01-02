/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:36:56 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/02 15:50:23 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	av_printerror(t_sl *sl, char *msg)
{
	if (msg == NULL)
		msg = strerror(errno);
	ft_printf(STDERR_FILENO, "Error\n%s: %s\n", sl->pname, msg);
}
