/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:29:36 by andeviei          #+#    #+#             */
/*   Updated: 2023/11/30 17:06:08 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/errno.h>
# include <mlx.h>

# include "libft/libft.h"

# define MAP_SUFFIX	".ber"
# define MAP_BUFSIZ	256

# define WIN_WIDTH	1920
# define WIN_HEIGHT	1080
# define WIN_TITLE	"So Long!"

# define EVT_KEYDN	2
# define EVT_DSTRY	17

# define KEY_ESC	53
# define KEY_LEFT	123
# define KEY_RIGHT	124
# define KEY_UP		126
# define KEY_DOWN	125
# define KEY_W		13
# define KEY_A		0
# define KEY_S		1
# define KEY_D		2

# define NEWLINE		"\n"
# define COLON			": "

# ifdef PEPIPO
#  define ERR_MAPSTR		"Map doesn't have the correct file structure\n"
#  define ERR_OPEN		"open: cannot access file "
# endif

typedef struct s_map
{
	char	*map;
	size_t	x;
	size_t	y;
}	t_map;

typedef struct s_sl
{
	char	*pname;
	char	*mapname;
	t_map	map;
}	t_sl;

void	av_printerror(char *pname, char *func, char *msg);

t_bool	av_readmap(t_sl *sl);
void	av_freemap(t_sl *sl);

void	av_initmlx(t_sl *sl);

#endif