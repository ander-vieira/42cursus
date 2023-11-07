/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:38:37 by andeviei          #+#    #+#             */
/*   Updated: 2023/11/07 19:02:44 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	**px_cmd_argv(char *cmd)
{
	char	**argv;

	argv = (char **)malloc(sizeof(char *) * 2);
	argv[0] = cmd;
	argv[1] = NULL;
	return (argv);
}

static char	*px_cmd_pname(char *cmd, char **env)
{
	(void)env;
	return (cmd);
}

void	px_cmd_run(char *cmd, int fdi, int fdo, char **env)
{
	pid_t	pid;

	pid = fork();
	if (pid != 0)
	{
		waitpid(pid, NULL, 0);
		close(fdi);
		close(fdo);
	}
	else
	{
		dup2(fdi, STDIN_FILENO);
		dup2(fdo, STDOUT_FILENO);
		execve(px_cmd_pname(cmd, env), px_cmd_argv(cmd), env);
	}
}
