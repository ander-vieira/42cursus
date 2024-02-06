/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:51:44 by andeviei          #+#    #+#             */
/*   Updated: 2024/02/06 16:05:59 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static t_fd	av_readerror(t_fd fd, t_pipex *px)
{
	if (ft_geterror() == FTERR_MALLOC)
		return (av_printerror(px->pname, "malloc", NULL), close(fd), -1);
	else if (ft_geterror() == FTERR_READ)
		return (av_printerror(px->pname, "read", NULL), close(fd), -1);
	else
		return (av_printerror(px->pname, "warning",
				"here-document delimited by end-of-file"), fd);
}

t_fd	av_heredoc(t_pipex *px)
{
	char	*line;
	char	*delim;
	t_fd	fd[2];

	delim = ft_strjoin(2, px->infile, "\n");
	if (delim == NULL)
		return (av_printerror(px->pname, "malloc", NULL), -1);
	if (pipe(fd) == -1)
		return (av_printerror(px->pname, "pipe", NULL), free(delim), -1);
	while (1)
	{
		line = ft_readline(STDIN_FILENO);
		if (line == NULL)
			return (free(delim), close(fd[1]), av_readerror(fd[0], px));
		if (ft_strcmp(line, delim))
			return (free(delim), close(fd[1]), fd[0]);
		if (write(fd[1], line, ft_strlen(line)) == -1)
			return (av_printerror(px->pname, "write", NULL),
				free(line), free(delim), close(fd[0]), close(fd[1]), -1);
		free(line);
	}
}
