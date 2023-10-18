/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsegame.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:08:04 by andeviei          #+#    #+#             */
/*   Updated: 2023/10/10 13:08:04 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	parse_entities(t_game *game)
{
	game->p = NULL;
	game->e = NULL;
	game->c = NULL;
	return (1);
}

t_game	*sl_parsegame(char *file)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	if (game == NULL)
		return (NULL);
	if (!read_map(game, file))
		return (sl_free(game));
	if (!parse_entities(game))
		return (sl_free(game));
	return (game);
}

void	*sl_freegame(t_game *game)
{
	if (game != NULL)
	{
		if (game->m != NULL)
			free(game->m);
		if (game->p != NULL)
			free(game->p);
		if (game->e != NULL)
			free(game->e);
		if (game->c != NULL)
			free(game->c);
		free(game);
	}
	return (NULL);
}
