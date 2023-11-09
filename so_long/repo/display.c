/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:23:23 by andeviei          #+#    #+#             */
/*   Updated: 2023/11/09 15:26:33 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	sl_closewindow(void *p)
{
	(void)p;
	exit(0);
	return (0);
}

static int	sl_handlekey(int keycode, void *p)
{
	t_sl	*sl;

	sl = (t_sl *)p;
	sl_printnnl((unsigned int)keycode);
	if (keycode == KEY_ESC)
		exit(0);
	else if (keycode == KEY_UP || keycode == KEY_W)
		sl_printstr("MOVE UP\n", STDOUT_FILENO);
	else if (keycode == KEY_LEFT || keycode == KEY_A)
		sl_printstr("MOVE LEFT\n", STDOUT_FILENO);
	else if (keycode == KEY_DOWN || keycode == KEY_S)
		sl_printstr("MOVE DOWN\n", STDOUT_FILENO);
	else if (keycode == KEY_RIGHT || keycode == KEY_D)
		sl_printstr("MOVE RIGHT\n", STDOUT_FILENO);
	return (0);
}

void	sl_initmlx(t_sl *sl)
{
	sl->mlx = mlx_init();
	sl->win = mlx_new_window(sl->mlx, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
	mlx_hook(sl->win, EVT_KEYDN, 0, (void *)&sl_handlekey, &sl);
	mlx_hook(sl->win, EVT_DSTRY, 0, (void *)&sl_closewindow, &sl);
	mlx_loop(sl->mlx);
}
