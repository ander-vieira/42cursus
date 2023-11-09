/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:36:56 by andeviei          #+#    #+#             */
/*   Updated: 2023/11/09 17:21:37 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_printerr(char *errormsg)
{
	sl_printstr(ERR_GENERIC, STDERR_FILENO);
	sl_printstr(errormsg, STDERR_FILENO);
}

void	sl_printerr_open(char *file)
{
	sl_printstr(ERR_GENERIC, STDERR_FILENO);
	sl_printstr(ERR_OPEN, STDERR_FILENO);
	sl_printstr(file, STDERR_FILENO);
	sl_printstr(COLON, STDERR_FILENO);
	sl_printstr(strerror(errno), STDERR_FILENO);
	sl_printstr(NEWLINE, STDERR_FILENO);
}

void	sl_printerr_read(char *file)
{
	sl_printstr(ERR_GENERIC, STDERR_FILENO);
	sl_printstr(ERR_READ, STDERR_FILENO);
	sl_printstr(file, STDERR_FILENO);
	sl_printstr(COLON, STDERR_FILENO);
	sl_printstr(strerror(errno), STDERR_FILENO);
	sl_printstr(NEWLINE, STDERR_FILENO);
}
