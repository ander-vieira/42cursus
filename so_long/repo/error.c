/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:36:56 by andeviei          #+#    #+#             */
/*   Updated: 2023/11/30 16:50:00 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	av_printerror(char *pname, char *func, char *msg)
{
	ft_printstr(STDERR_FILENO, "Error\n");
	if (pname != NULL)
		ft_printf(STDERR_FILENO, "%s: ", pname);
	if (func != NULL)
		ft_printf(STDERR_FILENO, "%s: ", func);
	if (msg == NULL)
		msg = strerror(errno);
	ft_printf(STDERR_FILENO, "%s\n", msg);
}
