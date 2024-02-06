/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:02:23 by andeviei          #+#    #+#             */
/*   Updated: 2024/02/06 16:07:55 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static char	*read_file(void)
{
	char	*file;
	t_fd	fd;

	fd = open(g_sl()->mapname, O_RDONLY);
	if (fd == -1)
		return (print_error(NULL), NULL);
	file = ft_readfull(fd);
	close(fd);
	if (file == NULL)
		return (print_error(NULL), NULL);
	return (file);
}

static t_bool	get_dims(char *file)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	(g_sl())->map.d = (t_vec2){0, 0};
	while (file[i] != '\0')
	{
		if (file[i] == '\n')
		{
			if (i == 0 || (g_sl()->map.d.x != 0
					&& i - j != g_sl()->map.d.x + 1))
				return (print_error("The map isn't well shaped"), FALSE);
			if (g_sl()->map.d.x == 0)
				g_sl()->map.d.x = i;
			g_sl()->map.d.y += 1;
			j = i;
		}
		i++;
	}
	if (i - j == g_sl()->map.d.x + 1)
		g_sl()->map.d.y += 1;
	else if (i - j != 1)
		return (print_error("The map isn't well shaped"), FALSE);
	return (TRUE);
}

static t_bool	split_file(char *file)
{
	t_vec2	pos;

	map_alloc(&(g_sl()->map));
	if (g_sl()->map.t == NULL)
		return (print_error(NULL), FALSE);
	pos.y = 0;
	while (pos.y < g_sl()->map.d.y)
	{
		pos.x = 0;
		while (pos.x < g_sl()->map.d.x)
		{
			map_settile(g_sl()->map, pos,
				file[pos.y * (g_sl()->map.d.x + 1) + pos.x]);
			pos.x++;
		}
		pos.y++;
	}
	return (TRUE);
}

t_bool	read_map(void)
{
	char	*file;

	file = read_file();
	if (file == NULL)
		return (FALSE);
	if (!get_dims(file) || !split_file(file))
		return (free(file), FALSE);
	return (free(file), TRUE);
}
