/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:21:26 by andeviei          #+#    #+#             */
/*   Updated: 2023/11/22 17:15:19 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	av_err_usage(char *pname)
{
	av_putstr("Usage: \n", STDOUT_FILENO);
	av_putstr(pname, STDOUT_FILENO);
	av_putstr(" <infile> <command1> <...> <commandN> <outfile>\n",
		STDOUT_FILENO);
	av_putstr(pname, STDOUT_FILENO);
	av_putstr(" here_doc <end sequence> <command1> <...> <commandN> <outfile>\n",
		STDOUT_FILENO);
}

void	av_err_generic(char *pname, char *func, char *msg)
{
	av_putstr(pname, STDERR_FILENO);
	av_putstr(": ", STDERR_FILENO);
	av_putstr(func, STDERR_FILENO);
	av_putstr(": ", STDERR_FILENO);
	av_putstr(msg, STDERR_FILENO);
	av_putstr("\n", STDERR_FILENO);
}

void	av_err_func(char *pname, char *func)
{
	av_putstr(pname, STDERR_FILENO);
	av_putstr(": ", STDERR_FILENO);
	av_putstr(func, STDERR_FILENO);
	av_putstr(": ", STDERR_FILENO);
	av_putstr(strerror(errno), STDERR_FILENO);
	av_putstr("\n", STDERR_FILENO);
}
