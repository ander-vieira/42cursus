/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:21:26 by andeviei          #+#    #+#             */
/*   Updated: 2023/11/07 22:20:09 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	px_err_usage(char *pname)
{
	px_putstr(MSG_USAGE_1, STDOUT_FILENO);
	px_putstr(pname, STDOUT_FILENO);
	px_putstr(MSG_USAGE_2, STDOUT_FILENO);
}

void	px_err_open(char *pname, char *fname)
{
	px_putstr(pname, STDERR_FILENO);
	px_putstr(MSG_OPEN_1, STDERR_FILENO);
	px_putstr(fname, STDERR_FILENO);
	px_putstr(MSG_COLON, STDERR_FILENO);
	px_putstr(strerror(errno), STDERR_FILENO);
	px_putstr(MSG_NL, STDERR_FILENO);
}

void	px_err_func(char *pname, char *func)
{
	px_putstr(pname, STDERR_FILENO);
	px_putstr(MSG_COLON, STDERR_FILENO);
	px_putstr(func, STDERR_FILENO);
	px_putstr(MSG_COLON, STDERR_FILENO);
	px_putstr(strerror(errno), STDERR_FILENO);
	px_putstr(MSG_NL, STDERR_FILENO);
}
