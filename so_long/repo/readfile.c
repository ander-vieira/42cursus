/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 20:14:27 by andeviei          #+#    #+#             */
/*   Updated: 2023/11/04 21:15:03 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	sl_readx(int fd, t_sl *sl, t_buf *buf)
{
	sl->w = 0;
	while (buf->m > 0)
	{
		while (buf->i < buf->m)
		{
			if (buf->b[buf->i] == '\n')
				return (1);
			sl->w += 1;
			buf->i += 1;
		}
		buf->m = read(fd, buf->b, MAP_BUFSIZ);
		buf->i = 0;
	}
	return (0);
}

static char	sl_ready(int fd, t_sl *sl, t_buf *buf)
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
					return (0);
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

static char	sl_readdims(char *file, t_sl *sl)
{
	int		fd;
	t_buf	buf;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	buf.m = read(fd, buf.b, MAP_BUFSIZ);
	buf.i = 0;
	if (!sl_readx(fd, sl, &buf))
		return (close(fd), 0);
	buf.i += 1;
	if (!sl_ready(fd, sl, &buf))
		return (close(fd), 0);
	return (close(fd), 1);
}

static char	sl_readmap(char *file, t_sl *sl)
{
	int		fd;
	t_uint	y;
	char	c;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		free(sl->m);
		return (0);
	}
	y = 0;
	while (y < sl->h)
	{
		if (read(fd, sl->m + (sl->w * y), sl->w) == -1)
			return (close(fd), 0);
		if (read(fd, &c, 1) == -1)
			return (close(fd), 0);
		y++;
	}
	return (close(fd), 1);
}

char	sl_readfile(char *file, t_sl *sl)
{
	if (!sl_readdims(file, sl))
		return (0);
	sl->m = (char *)malloc(sl->w * sl->h);
	if (sl->m == NULL)
		return (0);
	if (!sl_readmap(file, sl))
	{
		free(sl->m);
		return (0);
	}
	return (1);
}
