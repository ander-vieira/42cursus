/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 20:14:27 by andeviei          #+#    #+#             */
/*   Updated: 2023/11/09 17:29:49 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_bool	sl_readx(int fd, t_sl *sl, t_buf *buf)
{
	sl->w = 0;
	while (buf->m > 0)
	{
		while (buf->i < buf->m)
		{
			if (buf->b[buf->i] == '\n')
				return (TRUE);
			sl->w += 1;
			buf->i += 1;
		}
		buf->m = read(fd, buf->b, MAP_BUFSIZ);
		buf->i = 0;
	}
	return (FALSE);
}

static t_bool	sl_ready(int fd, t_sl *sl, t_buf *buf)
{
	t_uint	w;

	w = 0;
	sl->h = 1;
	while (buf->m > 0)
	{
		while (buf->i < buf->m)
		{
			if (buf->b[buf->i] == '\n')
			{
				if (w != sl->w)
					return (FALSE);
				sl->h += 1;
				w = -1;
			}
			w += 1;
			buf->i += 1;
		}
		buf->m = read(fd, buf->b, MAP_BUFSIZ);
		buf->i = 0;
	}
	if (w == sl->w)
		sl->h += 1;
	return (w == 0 || w == sl->w);
}

static t_bool	sl_readdims(char *file, t_sl *sl)
{
	int		fd;
	t_buf	buf;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (sl_printerr_open(file), FALSE);
	buf.m = read(fd, buf.b, MAP_BUFSIZ);
	buf.i = 0;
	if (!sl_readx(fd, sl, &buf))
		return (sl_printerr(ERR_MAPSTR), close(fd), FALSE);
	buf.i += 1;
	if (!sl_ready(fd, sl, &buf))
		return (sl_printerr(ERR_MAPSTR), close(fd), FALSE);
	return (close(fd), TRUE);
}

static t_bool	sl_readmap(char *file, t_sl *sl)
{
	int		fd;
	t_uint	y;
	char	c;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		free(sl->m);
		return (sl_printerr_open(file), FALSE);
	}
	y = 0;
	while (y < sl->h)
	{
		if (read(fd, sl->m + (sl->w * y), sl->w) == -1)
			return (sl_printerr_read(file), close(fd), FALSE);
		if (read(fd, &c, 1) == -1)
			return (sl_printerr_read(file), close(fd), FALSE);
		y++;
	}
	return (close(fd), TRUE);
}

t_bool	sl_readfile(char *file, t_sl *sl)
{
	if (!sl_readdims(file, sl))
		return (FALSE);
	sl->m = (char *)malloc(sl->w * sl->h);
	if (sl->m == NULL)
		return (sl_printerr(strerror(errno)), FALSE);
	if (!sl_readmap(file, sl))
		return (free(sl->m), FALSE);
	return (TRUE);
}
