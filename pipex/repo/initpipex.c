/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initpipex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:27:46 by andeviei          #+#    #+#             */
/*   Updated: 2023/11/23 15:52:01 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static t_bool	av_initpipes(t_pipex *px)
{
	t_fd	fd[2];
	size_t	i;
	t_bool	ok;

	i = 0;
	ok = TRUE;
	while (i < px->cmd_num)
	{
		px->cmds[i].fd_in = -1;
		if (ok && i != 0)
			px->cmds[i].fd_in = fd[0];
		px->cmds[i].fd_out = -1;
		if (ok && i != px->cmd_num - 1)
		{
			if (pipe(fd) == -1)
			{
				av_printerror(px->pname, "pipe", NULL);
				ok = FALSE;
			}
			px->cmds[i].fd_out = fd[1];
		}
		i++;
	}
	return (ok);
}

static t_bool	av_initcmds(char **cmds, t_pipex *px)
{
	size_t	i;

	px->cmds = (t_cmd *)malloc(sizeof(t_cmd) * px->cmd_num);
	if (px->cmds == NULL)
		return (av_printerror(px->pname, "malloc", NULL), FALSE);
	i = 0;
	while (i < px->cmd_num)
	{
		px->cmds[i].cmd = cmds[i];
		i++;
	}
	if (!av_initpipes(px))
		return (FALSE);
	return (TRUE);
}

t_bool	av_initpipex(t_pipex *px, int argc, char **argv, char **envp)
{
	t_bool	here_doc;

	here_doc = (argc >= 2 && av_strcmp(argv[1], "here_doc"));
	if (argc < 5 || (here_doc && argc < 6))
		return (av_printusage(argv[0]), FALSE);
	px->pname = argv[0];
	if (here_doc)
	{
		px->infile = argv[2];
		px->cmd_num = (size_t)(argc - 4);
		if (!av_initcmds(argv + 3, px))
			return (FALSE);
	}
	else
	{
		px->infile = argv[1];
		px->cmd_num = (size_t)(argc - 3);
		if (!av_initcmds(argv + 2, px))
			return (FALSE);
	}
	px->outfile = argv[argc - 1];
	px->env = envp;
	return (TRUE);
}

void	av_freepipex(t_pipex *px)
{
	size_t	i;

	if (px->cmds != NULL)
	{
		i = 0;
		while (i < px->cmd_num)
		{
			if (px->cmds[i].fd_in != -1)
				close(px->cmds[i].fd_in);
			if (px->cmds[i].fd_out != -1)
				close(px->cmds[i].fd_out);
			i++;
		}
		free(px->cmds);
		px->cmds = NULL;
	}
}
