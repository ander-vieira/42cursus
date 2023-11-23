/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getpath.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:36:47 by andeviei          #+#    #+#             */
/*   Updated: 2023/11/23 18:13:06 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*av_envpath(t_pipex *px)
{
	size_t	i;

	i = 0;
	while (px->env[i] != NULL)
	{
		if (av_strstarts(px->env[i], PATH_PREF))
			return (px->env[i] + av_strlen(PATH_PREF));
		i++;
	}
	return (NULL);
}

static char	*av_joinpath(char *cmd, char *path, size_t *i, t_pipex *px)
{
	char	*fullcmd;
	size_t	cmd_len;
	size_t	len;

	cmd_len = av_strlen(cmd);
	len = 0;
	while (path[*i + len] != '\0' && path[*i + len] != ENV_DELIM)
		len++;
	fullcmd = (char *)malloc(sizeof(char) * (len + cmd_len + 2));
	if (fullcmd == NULL)
		return (av_printerror(px->pname, "malloc", NULL), NULL);
	av_strncpy(fullcmd, path + *i, len);
	fullcmd[len] = PATH_DELIM;
	av_strncpy(fullcmd + len + 1, cmd, cmd_len);
	fullcmd[len + cmd_len + 1] = '\0';
	*i += len;
	return (fullcmd);
}

char	*av_getpath(char *cmd, t_pipex *px)
{
	char	*path;
	char	*fullcmd;
	size_t	i;

	path = av_envpath(px);
	if (cmd == NULL || path == NULL)
		return (av_printerror(px->pname, cmd, "command not found"), NULL);
	i = 0;
	while (path[i] != '\0')
	{
		while (path[i] == ENV_DELIM)
			i++;
		if (path[i] == '\0')
			break ;
		fullcmd = av_joinpath(cmd, path, &i, px);
		if (fullcmd == NULL || access(fullcmd, X_OK) == 0)
			return (fullcmd);
		if (errno != ENOENT)
			return (av_printerror(px->pname, fullcmd, NULL),
				free(fullcmd), NULL);
		free(fullcmd);
	}
	return (av_printerror(px->pname, cmd, "command not found"), NULL);
}
