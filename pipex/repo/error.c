/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:21:26 by andeviei          #+#    #+#             */
/*   Updated: 2023/11/30 11:38:03 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	av_putstr(char *str, int fd)
{
	write(fd, str, ft_strlen(str));
}

void	av_printusage(char *pname)
{
	av_putstr("Usage: \n", STDOUT_FILENO);
	av_putstr(pname, STDOUT_FILENO);
	av_putstr(" <infile> <cmd1> <cmd2> <outfile>\n",
		STDOUT_FILENO);
}

void	av_printerror(char *pname, char *func, char *msg)
{
	if (pname != NULL)
	{
		av_putstr(pname, STDERR_FILENO);
		av_putstr(": ", STDERR_FILENO);
	}
	if (func != NULL)
	{
		av_putstr(func, STDERR_FILENO);
		av_putstr(": ", STDERR_FILENO);
	}
	if (msg != NULL)
		av_putstr(msg, STDERR_FILENO);
	else
		av_putstr(strerror(errno), STDERR_FILENO);
	av_putstr("\n", STDERR_FILENO);
}
