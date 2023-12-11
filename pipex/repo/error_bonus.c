/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:21:26 by andeviei          #+#    #+#             */
/*   Updated: 2023/12/11 14:36:52 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	av_printusage(char *pname)
{
	ft_printstr(STDOUT_FILENO, "Usage: \n");
	ft_printstr(STDOUT_FILENO, pname);
	ft_printstr(STDOUT_FILENO, " <infile> <cmd1> <...> <cmdN> <outfile>\n");
	ft_printstr(STDOUT_FILENO, pname);
	ft_printstr(STDOUT_FILENO, \
		" here_doc <end sequence> <cmd1> <...> <cmdN> <outfile>\n");
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
