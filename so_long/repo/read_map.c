/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:02:23 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/16 19:30:58 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*read_file(t_sl *sl)
{
	char	*file;
	t_fd	fd;

	fd = open(sl->mapname, O_RDONLY);
	if (fd == -1)
		return (NULL);
	file = ft_readfull(fd, NULL);
	close(fd);
	return (file);
}

static t_bool	get_dims(t_sl *sl, char *file)
{
	size_t	x;
	ssize_t	pos;

	pos = ft_strchr(file, '\n');
	if (pos == -1)
		return (FALSE);
	sl->dims.x = (t_uint)pos;
	sl->dims.y = 1;
	x = sl->dims.x + 1;
	while (file[x] != '\0')
	{
		pos = ft_strchr(file, '\n');
		if (pos == -1 || (t_uint)pos != sl->dims.x)
			return (FALSE);
		sl->dims.y += 1;
		x += sl->dims.x + 1;
	}
	return (TRUE);
}

static t_bool	split_file(t_sl *sl, char *file)
{
	t_uint	y;

	sl->map = ft_strsplit(file, '\n');
	free(file);
	if (sl->map == NULL)
		return (FALSE);
	sl->dims.y = 0;
	while (sl->map[sl->dims.y] != NULL)
		sl->dims.y += 1;
	if (sl->dims.y == 0)
		return (FALSE);
	sl->dims.x = ft_strlen(sl->map[0]);
	y = 1;
	while (y < sl->dims.y)
	{
		if (ft_strlen(sl->map[y]) != sl->dims.x)
			return (FALSE);
		y++;
	}
	return (TRUE);
}

t_bool	read_map(t_sl *sl)
{
	char	*file;

	file = read_file(sl);
	if (file == NULL)
		return (av_printerror(sl, "Error while reading the map file"), FALSE);
	if (!split_file(sl, file))
		return (av_printerror(sl, "The map isn't shaped correctly"), FALSE);
	return (TRUE);
}
