/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:21:26 by andeviei          #+#    #+#             */
/*   Updated: 2023/11/30 16:48:16 by andeviei         ###   ########.fr       */
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
	ft_printstr(STDERR_FILENO, "Error\n");
	if (pname != NULL)
		ft_printf(STDERR_FILENO, "%s: ", pname);
	if (func != NULL)
		ft_printf(STDERR_FILENO, "%s: ", func);
	if (msg == NULL)
		msg = strerror(errno);
	ft_printf(STDERR_FILENO, "%s\n", msg);
}
