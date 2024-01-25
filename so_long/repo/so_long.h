/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:29:36 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/25 17:23:05 by andeviei         ###   ########.fr       */
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

typedef struct s_vec2
{
	t_uint	x;
	t_uint	y;
}	t_vec2;

typedef struct s_sl
{
	char	*pname;
	char	*mapname;
	char	*map;
	t_vec2	dims;
}	t_sl;

t_sl	*g_sl(void);

void	print_error(char *msg);

t_vec2	vec2_new(t_uint x, t_uint y);
t_vec2	vec2_add(t_vec2 v1, t_vec2 v2);

char	tile_get(t_vec2 pos);
void	tile_set(t_vec2 pos, char c);

void	map_print(void);
size_t	map_count(char c);

t_bool	validate_args(int argc, char **argv);
t_bool	read_map(void);
t_bool	validate_map(void);

void	init_mlx(void);

#endif