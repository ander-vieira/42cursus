/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   runcmd_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:00:09 by andeviei          #+#    #+#             */
/*   Updated: 2023/11/26 18:12:11 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static t_bool	av_updatefdin(t_pipex *px, size_t i)
{
	if (px->here)
	{
		if (px->cmds[i].fd_in == -1)
			px->cmds[i].fd_in = av_heredoc(px);
		if (px->cmds[i].fd_in == -1)
			return (FALSE);
	}
	else
	{
		if (px->cmds[i].fd_in == -1)
			px->cmds[i].fd_in = open(px->infile, O_RDONLY);
		if (px->cmds[i].fd_in == -1)
			return (av_printerror(px->pname, px->infile, NULL), FALSE);
	}
	if (dup2(px->cmds[i].fd_in, STDIN_FILENO) == -1)
		return (av_printerror(px->pname, "dup2", NULL),
			close(px->cmds[i].fd_in), FALSE);
	return (close(px->cmds[i].fd_in), TRUE);
}

static t_bool	av_updatefdout(t_pipex *px, size_t i)
{
	if (px->cmds[i].fd_out == -1)
	{
		if (px->here)
			px->cmds[i].fd_out = open(px->outfile,
					O_WRONLY | O_CREAT | O_APPEND, 0664);
		else
			px->cmds[i].fd_out = open(px->outfile,
					O_WRONLY | O_CREAT | O_TRUNC, 0664);
	}
	if (px->cmds[i].fd_out == -1)
		return (av_printerror(px->pname, px->outfile, NULL), FALSE);
	if (dup2(px->cmds[i].fd_out, STDOUT_FILENO) == -1)
		return (av_printerror(px->pname, "dup2", NULL),
			close(px->cmds[i].fd_out), FALSE);
	return (close(px->cmds[i].fd_out), TRUE);
}

static int	av_runcmd_child(t_pipex *px, size_t i)
{
	char	**argv;
	char	*pname;

	if (!av_updatefdin(px, i))
		return (av_freepipex(px), EXIT_FAILURE);
	if (!av_updatefdout(px, i))
		return (av_freepipex(px), EXIT_FAILURE);
	argv = av_getargv(px, i);
	if (argv == NULL)
		return (av_freepipex(px), EXIT_FAILURE);
	pname = av_getpath(argv[0], px);
	if (pname == NULL)
		return (av_freeargv(argv), av_freepipex(px), EXIT_FAILURE);
	execve(pname, argv, px->env);
	av_printerror(px->pname, "execve", NULL);
	return (free(pname), av_freeargv(argv), av_freepipex(px), EXIT_FAILURE);
}

t_bool	av_runcmd(t_pipex *px, size_t i)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == -1)
		return (av_printerror(px->pname, "fork", NULL), FALSE);
	else if (pid == 0)
		exit(av_runcmd_child(px, i));
	else
	{
		if (px->cmds[i].fd_in != -1)
			close(px->cmds[i].fd_in);
		if (px->cmds[i].fd_out != -1)
			close(px->cmds[i].fd_out);
		waitpid(pid, &status, 0);
		if (status != 0)
			return (FALSE);
		return (TRUE);
	}
}
