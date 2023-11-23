/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:01:40 by andeviei          #+#    #+#             */
/*   Updated: 2023/11/23 15:52:13 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static t_bool	av_runcmds(t_pipex *px)
{
	t_bool	ok;
	size_t	i;

	ok = TRUE;
	i = 0;
	while (i < px->cmd_num)
	{
		if (!av_runcmd(px, i))
			ok = FALSE;
		i++;
	}
	return (TRUE);
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
