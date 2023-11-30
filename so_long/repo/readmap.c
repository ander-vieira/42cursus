/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:02:48 by andeviei          #+#    #+#             */
/*   Updated: 2023/11/30 17:26:37 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	av_gnlerror(t_error error, t_sl *sl)
{
	if (error == ERR_READ)
		av_printerror(sl->pname, "read", NULL);
	else if (error == ERR_MALLOC)
		av_printerror(sl->pname, "malloc", NULL);
}

t_bool	av_getdims(t_sl *sl)
{
	t_fd	fd;
	t_error	error;
	char	*line;

	fd = open(sl->mapname, O_RDONLY);
	if (fd == -1)
		return (av_printerror(sl->pname, sl->mapname, NULL), FALSE);
	sl->map.x = 0;
	sl->map.y = 0;
	while (1)
	{
		line = ft_gnl(fd, &error);
		if (line == NULL || ft_strlen(line) == 1)
			break ;
		if (sl->map.x == 0)
			sl->map.x = ft_strlen(line) - 1;
		sl->map.y += 1;
		free(line);
	}
	if (error != ERR_OK)
		return (av_gnlerror(error, sl), close(fd), FALSE);
	if (sl->map.x == 0 || sl->map.y == 0)
		return (av_printerror(sl->pname, sl->mapname, "Map cannot be empty"),
			close(fd), FALSE);
	return (close(fd), TRUE);
}

t_bool	av_getmap(t_sl *sl)
{
	t_fd	fd;
	t_error	error;
	char	*line;
	size_t	i;

	fd = open(sl->mapname, O_RDONLY);
	if (fd == -1)
		return (av_printerror(sl->pname, sl->mapname, NULL), FALSE);
	sl->map.map = (char *)malloc((sizeof(char) * sl->map.x * sl->map.y));
	if (sl->map.map == NULL)
		return (av_printerror(sl->pname, "malloc", NULL), close(fd), FALSE);
	i = 0;
	while (i < sl->map.y)
	{
		line = ft_gnl(fd, &error);
		if (line == NULL)
			return ();
		free(line);
		i++;
	}
}

//TODO
t_bool	av_readmap(t_sl *sl)
{
	if (!av_getdims(sl))
		return (FALSE);
	return (TRUE);
}

//TODO
void	av_freemap(t_sl *sl)
{
	(void)sl;
}
