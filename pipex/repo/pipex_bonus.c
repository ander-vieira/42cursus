/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:01:40 by andeviei          #+#    #+#             */
/*   Updated: 2023/11/25 00:23:06 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static t_bool	av_runcmds(t_pipex *px)
{
	t_bool	ok;
	size_t	i;

	i = 0;
	while (i < px->cmd_num)
	{
		ok = av_runcmd(px, i);
		i++;
	}
	return (ok);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	px;

	if (!av_initpipex(&px, argc, argv, envp))
		return (EXIT_FAILURE);
	if (!av_runcmds(&px))
		return (av_freepipex(&px), EXIT_FAILURE);
	return (av_freepipex(&px), EXIT_SUCCESS);
}
