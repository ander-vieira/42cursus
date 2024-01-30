/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:33:50 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/30 17:39:05 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static t_image	load_image(char *path)
{
	char	*dirname;
	char	*fullpath;
	t_image	img;

	dirname = ft_dirname(g_sl()->pname);
	fullpath = ft_strjoin(3, dirname, "/", path);
	free(dirname);
	img.i = mlx_xpm_file_to_image(g_sl()->mlx, fullpath, &(img.w), &(img.h));
	free(fullpath);
	return (img);
}

t_bool	load_images(void)
{
	g_sl()->img_floor = load_image(IMG_FLOOR);
	if (g_sl()->img_floor.i == NULL)
		return (print_error("Error loading floor texture"), FALSE);
	g_sl()->img_wall = load_image(IMG_WALL);
	if (g_sl()->img_wall.i == NULL)
		return (print_error("Error loading wall texture"), FALSE);
	g_sl()->img_player = load_image(IMG_PLAYER);
	if (g_sl()->img_player.i == NULL)
		return (print_error("Error loading player texture"), FALSE);
	g_sl()->img_item = load_image(IMG_ITEM);
	if (g_sl()->img_item.i == NULL)
		return (print_error("Error loading item texture"), FALSE);
	g_sl()->img_exit = load_image(IMG_EXIT);
	if (g_sl()->img_exit.i == NULL)
		return (print_error("Error loading exit texture 1"), FALSE);
	g_sl()->img_exit_active = load_image(IMG_EXIT_ACTIVE);
	if (g_sl()->img_exit_active.i == NULL)
		return (print_error("Error loading exit texture 2"), FALSE);
	return (TRUE);
}
