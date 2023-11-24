/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getargv_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:20:49 by andeviei          #+#    #+#             */
/*   Updated: 2023/11/25 00:22:51 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static size_t	av_getargc(char *str)
{
	size_t	i;
	size_t	result;

	i = 0;
	result = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && ft_isspace(str[i]))
			i++;
		if (str[i] != '\0')
			result += 1;
		while (str[i] != '\0' && !ft_isspace(str[i]))
			i++;
	}
	return (result);
}

static char	*av_getparam(t_pipex *px, char **str)
{
	char	*param;
	size_t	len;
	size_t	i;

	while (**str != '\0' && ft_isspace(**str))
		*str += 1;
	len = 0;
	while ((*str)[len] != '\0' && !ft_isspace((*str)[len]))
		len++;
	param = (char *)malloc(sizeof(char) * (len + 1));
	if (param == NULL)
		return (av_printerror(px->pname, "malloc", NULL), NULL);
	i = 0;
	while (i < len)
	{
		param[i] = (*str)[i];
		i++;
	}
	param[len] = '\0';
	*str += len;
	return (param);
}

char	**av_getargv(t_pipex *px, size_t i)
{
	char	**argv;
	size_t	argc;
	size_t	j;

	argc = av_getargc(px->cmds[i].cmd);
	argv = (char **)malloc(sizeof(char *) * (argc + 1));
	if (argv == NULL)
		return (av_printerror(px->pname, "malloc", NULL), NULL);
	j = 0;
	while (j < argc)
	{
		argv[j] = av_getparam(px, &(px->cmds[i].cmd));
		if (argv[j] == NULL)
			return (av_freeargv(argv), NULL);
		j++;
	}
	argv[argc] = NULL;
	return (argv);
}

void	av_freeargv(char **argv)
{
	size_t	i;

	if (argv != NULL)
	{
		i = 0;
		while (argv[i] != NULL)
		{
			free(argv[i]);
			i++;
		}
		free(argv);
	}
}
