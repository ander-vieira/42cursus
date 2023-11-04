/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:29:36 by andeviei          #+#    #+#             */
/*   Updated: 2023/11/04 21:16:54 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>

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

# define MSG_ERROR	"Error\n"

typedef unsigned int	t_uint;

typedef struct s_buf {
	char	b[MAP_BUFSIZ];
	ssize_t	i;
	ssize_t	m;
}	t_buf;

typedef struct s_sl {
	void	*mlx;
	void	*win;
	char	*m;
	t_uint	w;
	t_uint	h;
}	t_sl;

size_t	sl_strlen(char *str);
char	sl_strends(char *str, char *suf);

void	sl_printstr(char *str);
void	sl_printnbr(t_uint num);
void	sl_printnnl(t_uint num);

char	sl_readfile(char *file, t_sl *sl);

char	sl_validmap(t_sl *sl);

#endif