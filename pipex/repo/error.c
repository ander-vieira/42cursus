/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:21:26 by andeviei          #+#    #+#             */
/*   Updated: 2023/11/07 18:24:05 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	px_err_usage(char *pname)
{
	px_putstr("Usage: ", STDOUT_FILENO);
	px_putstr(pname, STDOUT_FILENO);
	px_putstr(" infile command1 command2 outfile\n", STDOUT_FILENO);
}

void	px_err_open(char *pname, char *fname)
{
	px_putstr(pname, STDERR_FILENO);
	px_putstr(": ", STDERR_FILENO);
	px_putstr(fname, STDERR_FILENO);
	px_putstr(": ", STDERR_FILENO);
	px_putstr(strerror(errno), STDERR_FILENO);
	px_putstr("\n", STDERR_FILENO);
}

void	px_err_pipe(char *pname)
{
	px_putstr(pname, STDERR_FILENO);
	px_putstr(": ", STDERR_FILENO);
	px_putstr(strerror(errno), STDERR_FILENO);
	px_putstr("\n", STDERR_FILENO);
}
