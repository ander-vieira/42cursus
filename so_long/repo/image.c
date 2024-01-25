/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 19:56:41 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/25 20:17:39 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_image	image_load(char *path)
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

void	image_draw(t_image img, t_vec2 pos)
{
	mlx_put_image_to_window(g_sl()->mlx, g_sl()->win, img.i,
		pos.x * TILE_WIDTH, pos.y * TILE_HEIGHT);
}
