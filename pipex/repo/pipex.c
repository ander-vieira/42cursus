/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:01:40 by andeviei          #+#    #+#             */
/*   Updated: 2023/11/22 17:16:56 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static t_pipex	av_initdata(char **argv, char **envp)
{
	t_pipex	px;

	px.pname = argv[0];
	px.infile = argv[1];
	px.c_1 = argv[2];
	px.c_2 = argv[3];
	px.outfile = argv[4];
	px.env = envp;
	return (px);
}

static void	av_cmd_run(char *cmd, int *fd, t_pipex *px)
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
		argv = av_split(cmd, -1);
		pname = av_getpath(argv[0], px);
		if (pname == NULL)
			exit(0);
		dup2(fd[0], STDOUT_FILENO);
		dup2(fd[1], STDIN_FILENO);
		execve(pname, argv, px->env);
		av_err_func(px->pname, "execve");
		exit(0);
	}
}

static int	av_initpipes(t_pipex *px)
{
	int	fd[4];

	fd[3] = open(px->infile, O_RDONLY);
	if (fd[3] == -1)
		return (av_err_func(px->pname, px->infile), -1);
	fd[0] = open(px->outfile, O_WRONLY | O_CREAT | O_TRUNC,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	if (fd[0] == -1)
		return (av_err_func(px->pname, px->outfile), -1);
	if (pipe(fd + 1) == -1)
		return (av_err_func(px->pname, "pipe"), -1);
	av_cmd_run(px->c_1, fd + 2, px);
	av_cmd_run(px->c_2, fd, px);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	px;

	if (argc != 5)
		return (av_err_usage(argv[0]), 0);
	px = av_initdata(argv, envp);
	av_initpipes(&px);
	return (0);
}
