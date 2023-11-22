/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:29:36 by andeviei          #+#    #+#             */
/*   Updated: 2023/11/09 17:43:17 by andeviei         ###   ########.fr       */
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

# include "bool.h"
# include "msg.h"

# define MAP_SUF	".ber"
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

typedef unsigned int	t_uint;

/*
 *	The buffer used to read the map file
 */
typedef struct s_buf {
	char	b[MAP_BUFSIZ];
	ssize_t	i;
	ssize_t	m;
}	t_buf;

typedef struct s_map {
	char	*m;
	t_uint	w;
	t_uint	h;
}	t_map;

/*
 *	The generic structure that contains the application's data
 */
typedef struct s_sl {
	void	*mlx;
	void	*win;
	t_map	map;
}	t_sl;

size_t	sl_strlen(char *str);
char	sl_strends(char *str, char *suf);

void	sl_printstr(char *str, int fd);
void	sl_printnbr(t_uint num, int fd);
void	sl_printnnl(t_uint num);

void	sl_printerr(char *errormsg);
void	sl_printerr_open(char *file);
void	sl_printerr_read(char *file);

t_bool	sl_readfile(char *file, t_map *map);

t_bool	sl_validmap(t_map *map);

void	sl_initmlx(t_sl *sl);

#endif