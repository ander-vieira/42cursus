/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:21:26 by andeviei          #+#    #+#             */
/*   Updated: 2023/11/30 15:27:20 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	av_printusage(char *pname)
{
	ft_printstr(STDOUT_FILENO, "Usage: \n");
	ft_printstr(STDOUT_FILENO, pname);
	ft_printstr(STDOUT_FILENO, " <infile> <cmd1> <cmd2> <outfile>\n");
}

void	av_printerror(char *pname, char *func, char *msg)
{
	if (pname != NULL)
	{
		ft_printstr(STDERR_FILENO, pname);
		ft_printstr(STDERR_FILENO, ": ");
	}
	if (func != NULL)
	{
		ft_printstr(STDERR_FILENO, func);
		ft_printstr(STDERR_FILENO, ": ");
	}
	if (msg != NULL)
		ft_printstr(STDERR_FILENO, msg);
	else
		ft_printstr(STDERR_FILENO, strerror(errno));
	ft_printstr(STDERR_FILENO, "\n");
}
