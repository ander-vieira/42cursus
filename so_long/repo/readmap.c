/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:04:04 by andeviei          #+#    #+#             */
/*   Updated: 2023/10/10 14:04:04 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	get_mapsize(t_game *game, char *file)
{
	int		fd;
	char	c;
	char	*buf;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	c = 0;
	game->w = 0;
	while (read(fd, &c, 1) == 1 && c != '\n')
		(game->w)++;
	if (c != '\n')
		return (0);
	buf = (char *)malloc(game->w + 1);
	while (read(fd, buf, game->w + 1) == game->w + 1 && sl_memchr(buf, '\n', game->w + 1) == game->w)
		
	close(fd);
	return (1);
}

char	read_map(t_game *game, char *file)
{
	game->m = NULL;
	return (1);
}
