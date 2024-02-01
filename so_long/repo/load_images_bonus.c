/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:33:50 by andeviei          #+#    #+#             */
/*   Updated: 2024/02/01 16:19:20 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

static t_anim	load_animation(char *path, t_uint n)
{
	char	*framepath;
	t_anim	anim;
	t_uint	i;

	anim.n = n;
	anim.i = (t_image *)malloc(sizeof(t_image) * n);
	if (anim.i == NULL)
		return (anim);
	i = 0;
	while (i < n)
	{
		framepath = ft_strformat("%s%u", path, i);
		anim.i[i] = load_image(framepath);
		free(framepath);
		i++;
	}
	return (anim);
}

t_bool	load_images(void)
{
	g_sl()->img_floor = load_image("floor");
	if (g_sl()->img_floor.i == NULL)
		return (print_error("Error loading floor texture"), FALSE);
	g_sl()->img_wall = load_image("wall");
	if (g_sl()->img_wall.i == NULL)
		return (print_error("Error loading wall texture"), FALSE);
	g_sl()->anim_player = load_animation("player", 2);
	if (g_sl()->anim_player.i == NULL)
		return (print_error("Error loading player textures"), FALSE);
	g_sl()->anim_item = load_animation("item", 4);
	if (g_sl()->anim_item.i == NULL)
		return (print_error("Error loading item textures"), FALSE);
	g_sl()->img_exit[0] = load_image("exit0");
	if (g_sl()->img_exit[0].i == NULL)
		return (print_error("Error loading exit texture 1"), FALSE);
	g_sl()->img_exit[1] = load_image("exit1");
	if (g_sl()->img_exit[1].i == NULL)
		return (print_error("Error loading exit texture 2"), FALSE);
	return (TRUE);
}
