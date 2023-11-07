/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:01:40 by andeviei          #+#    #+#             */
/*   Updated: 2023/11/07 19:28:54 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static t_pipex	px_initdata(char **argv, char **envp)
{
	t_pipex	px;

	px.name = argv[0];
	px.i_f = argv[1];
	px.c_1 = argv[2];
	px.c_2 = argv[3];
	px.o_f = argv[4];
	px.env = envp;
	return (px);
}

static int	px_initpipes(t_pipex *px)
{
	int	fd[4];

	fd[3] = open(px->i_f, O_RDONLY);
	if (fd[3] == -1)
		return (px_err_open(px->name, px->i_f), -1);
	fd[0] = open(px->o_f, O_WRONLY | O_CREAT | O_TRUNC,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	if (fd[0] == -1)
		return (px_err_open(px->name, px->o_f), -1);
	if (pipe(fd + 1) == -1)
		return (px_err_func(px->name, "pipe"), -1);
	px_cmd_run(px->c_1, fd + 2, px);
	px_cmd_run(px->c_2, fd, px);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	px;

	if (argc != 5)
		return (px_err_usage(argv[0]), 0);
	px = px_initdata(argv, envp);
	px_initpipes(&px);
	return (0);
}
