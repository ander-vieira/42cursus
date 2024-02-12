/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:21:26 by andeviei          #+#    #+#             */
/*   Updated: 2024/02/12 19:29:54 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	av_printusage(char *pname)
{
	ft_printf(STDOUT_FILENO,
		"Usage: \n%s <infile> <cmd1> <cmd2> <outfile>\n", pname);
}

void	av_printerror(char *pname, char *func, char *msg)
{
	if (pname != NULL)
		ft_printf(STDERR_FILENO, "%s: ", pname);
	if (func != NULL)
		ft_printf(STDERR_FILENO, "%s: ", func);
	if (msg == NULL)
		msg = strerror(errno);
	ft_printf(STDERR_FILENO, "%s\n", msg);
}
