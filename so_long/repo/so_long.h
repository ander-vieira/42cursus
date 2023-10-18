/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 12:38:30 by andeviei          #+#    #+#             */
/*   Updated: 2023/10/10 12:38:30 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 32

typedef struct s_point {
	size_t			x;
	size_t			y;
	struct s_point	*next;
}	t_point;

typedef struct s_game {
	char	*m;
	size_t	w;
	size_t	h;
	t_point	*p;
	t_point	*e;
	t_point	*c;
}	t_game;

t_game	*sl_parse_game(char *file);
void	*sl_free_game(t_game *game);

#endif
