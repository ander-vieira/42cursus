/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:33:50 by andeviei          #+#    #+#             */
/*   Updated: 2024/02/01 16:11:48 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_image	load_image(char *path)
{
	char	*dirname;
	char	*fullpath;
	t_image	img;

	dirname = ft_dirname(g_sl()->pname);
	fullpath = ft_strformat("%s/textures/%s.xpm", dirname, path);
	free(dirname);
	img.i = mlx_xpm_file_to_image(g_sl()->mlx, fullpath, &(img.w), &(img.h));
	free(fullpath);
	return (img);
}

t_bool	load_images(void)
{
	g_sl()->img_floor = load_image("floor");
	if (g_sl()->img_floor.i == NULL)
		return (print_error("Error loading floor texture"), FALSE);
	g_sl()->img_wall = load_image("wall");
	if (g_sl()->img_wall.i == NULL)
		return (print_error("Error loading wall texture"), FALSE);
	g_sl()->img_player = load_image("player0");
	if (g_sl()->img_player.i == NULL)
		return (print_error("Error loading player texture"), FALSE);
	g_sl()->img_item = load_image("item0");
	if (g_sl()->img_item.i == NULL)
		return (print_error("Error loading item texture"), FALSE);
	g_sl()->img_exit = load_image("exit0");
	if (g_sl()->img_exit.i == NULL)
		return (print_error("Error loading exit texture 1"), FALSE);
	g_sl()->img_exit_active = load_image("exit1");
	if (g_sl()->img_exit_active.i == NULL)
		return (print_error("Error loading exit texture 2"), FALSE);
	return (TRUE);
}
