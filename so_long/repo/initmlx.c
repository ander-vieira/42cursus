/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initmlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:23:23 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/25 17:22:53 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	close_window(void *p)
{
	(void)p;
	exit(EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

static int	handle_key(int keycode, void *p)
{
	(void)p;
	ft_printf(STDOUT_FILENO, "%d\n", keycode);
	if (keycode == KEY_ESC)
		exit(0);
	else if (keycode == KEY_UP || keycode == KEY_W)
		ft_printstr(STDOUT_FILENO, "MOVE UP\n");
	else if (keycode == KEY_LEFT || keycode == KEY_A)
		ft_printstr(STDOUT_FILENO, "MOVE LEFT\n");
	else if (keycode == KEY_DOWN || keycode == KEY_S)
		ft_printstr(STDOUT_FILENO, "MOVE DOWN\n");
	else if (keycode == KEY_RIGHT || keycode == KEY_D)
		ft_printstr(STDOUT_FILENO, "MOVE RIGHT\n");
	return (0);
}

void	init_mlx(void)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
	mlx_hook(win, EVT_KEYDN, 0, (void *)&handle_key, NULL);
	mlx_hook(win, EVT_DSTRY, 0, (void *)&close_window, NULL);
	mlx_loop(mlx);
}
