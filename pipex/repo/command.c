/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:38:37 by andeviei          #+#    #+#             */
/*   Updated: 2023/11/22 16:00:50 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	**px_getpath(char **env)
{
	size_t	i;

	i = 0;
	while (env[i] != NULL)
	{
		if (px_strstarts(env[i], PATH_PREF))
		{
			return (px_split(env[i] + px_strlen(PATH_PREF), ENV_DELIM));
		}
		i++;
	}
	return (NULL);
}

static char	*px_cmd_pname(char *name, t_pipex *px)
{
	char	**path;
	char	*pname;
	size_t	i;

	if (px_strhas(name, PATH_DELIM))
		return (name);
	path = px_getpath(px->env);
	if (path == NULL)
		return (NULL);
	i = 0;
	while (path[i] != NULL)
	{
		pname = px_strjoin(path[i], name);
		if (pname == NULL || access(pname, X_OK) == 0)
			return (free(path), pname);
		free(pname);
		if (errno != ENOENT)
			break ;
		i++;
	}
	return (px_err_func(px->pname, name), free(path), NULL);
}

void	px_cmd_run(char *cmd, int *fd, t_pipex *px)
{
	pid_t	pid;
	char	**argv;
	char	*pname;

	pid = fork();
	if (pid != 0)
	{
		waitpid(pid, NULL, 0);
		close(fd[0]);
		close(fd[1]);
	}
	else
	{
		argv = px_split(cmd, -1);
		pname = px_cmd_pname(argv[0], px);
		if (pname == NULL)
			exit(0);
		dup2(fd[0], STDOUT_FILENO);
		dup2(fd[1], STDIN_FILENO);
		execve(pname, argv, px->env);
		px_err_func(px->pname, "execve");
		exit(0);
	}
}
