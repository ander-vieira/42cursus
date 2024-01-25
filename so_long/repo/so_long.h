/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:29:36 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/25 20:27:22 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/errno.h>

# include "mlx/mlx.h"
# include "libft/libft.h"

# define MAP_SUFFIX	".ber"
# define MAP_BUFSIZ	256

# define WIN_WIDTH	1920
# define WIN_HEIGHT	1080
# define WIN_TITLE	"So Long!"

# define TILE_WIDTH		32
# define TILE_HEIGHT	32

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

# define TILE_FLOOR		'0'
# define TILE_WALL		'1'
# define TILE_PLAYER	'P'
# define TILE_ITEM		'C'
# define TILE_EXIT		'E'
# define TILE_FLOOD		'F'

# define IMG_FLOOR	"textures/floor.xpm"
# define IMG_WALL	"textures/wall.xpm"
# define IMG_PLAYER	"textures/player.xpm"
# define IMG_ITEM	"textures/item.xpm"
# define IMG_EXIT	"textures/exit.xpm"

/*
 *	Represents a two-dimensional vector with fields x and y
 */
typedef struct s_vec2
{
	t_uint	x;
	t_uint	y;
}	t_vec2;

/*
 *	Represents the game map:
 *	- field t contains the map tiles in a one-dimensional array
 *	- field d contains the map dimensions as a t_vec2 (two-dimensional vector)
 */
typedef struct s_map
{
	char	*t;
	t_vec2	d;
}	t_map;

/*
 *	Represents a MinilibX image
 *	- Field i is a pointer to the image data
 *	- Fields w and h are the image's dimensions stored as (int)
 */
typedef struct s_image
{
	void	*i;
	int		w;
	int		h;
}	t_image;

/*
 *	This structure is used to hold all of the game's metadata
 *	- pname: the program's name as given by argv[0]
 *	- mapname: the map filename given by the user as argv[1]
 *	- map: the game's map as a t_map
 *	- mlx: a pointer to the MinilibX instance used for handling graphics/events
 *	- win: a pointer to the MLX window the game creates
 *	- img_floor: the MLX texture for floor tiles
 *	- img_wall: the MLX texture for wall tiles
 *	- img_player: the MLX texture for the player
 *	- img_item: the MLX texture for items
 *	- img_exit: the MLX texture for the exit
 */
typedef struct s_sl
{
	char	*pname;
	char	*mapname;
	t_map	map;
	void	*mlx;
	void	*win;
	t_image	img_floor;
	t_image	img_wall;
	t_image	img_player;
	t_image	img_item;
	t_image	img_exit;
}	t_sl;

t_sl	*g_sl(void);

void	print_error(char *msg);

t_vec2	vec2_new(t_uint x, t_uint y);
t_vec2	vec2_move(t_vec2 v, t_uint x, t_uint y);

char	map_gettile(t_map map, t_vec2 pos);
void	map_settile(t_map map, t_vec2 pos, char c);
void	map_print(t_map map);
size_t	map_count(t_map map, char c);
void	map_alloc(t_map *map);
t_map	map_duplicate(t_map map);
t_vec2	map_find(t_map map, char c);
void	map_flood(t_map map, t_vec2 pos);
size_t	map_countedges(t_map map, char c);
void	map_free(t_map map);

t_image	image_load(char *path);
void	image_draw(t_image img, t_vec2 pos);

t_bool	validate_args(int argc, char **argv);
t_bool	read_map(void);
t_bool	validate_map(void);

void	init_mlx(void);

#endif