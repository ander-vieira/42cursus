/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:28:48 by andeviei          #+#    #+#             */
/*   Updated: 2023/11/04 21:16:29 by andeviei         ###   ########.fr       */
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
		sl_printstr("MOVE UP\n");
	else if (keycode == KEY_LEFT || keycode == KEY_A)
		sl_printstr("MOVE LEFT\n");
	else if (keycode == KEY_DOWN || keycode == KEY_S)
		sl_printstr("MOVE DOWN\n");
	else if (keycode == KEY_RIGHT || keycode == KEY_D)
		sl_printstr("MOVE RIGHT\n");
	return (0);
}

static void	sl_initmlx(t_sl *sl)
{
	sl->mlx = mlx_init();
	sl->win = mlx_new_window(sl->mlx, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
	mlx_hook(sl->win, EVT_KEYDN, 0, (void *)&sl_handlekey, &sl);
	mlx_hook(sl->win, EVT_DSTRY, 0, (void *)&sl_closewindow, &sl);
	mlx_loop(sl->mlx);
}

int	main(int argc, char **argv)
{
	t_sl	sl;

	if (argc != 2 || !sl_strends(argv[1], MAP_SUF))
		sl_printstr(MSG_ERROR);
	else
	{
		if (sl_readfile(argv[1], &sl) && sl_validmap(&sl))
			sl_initmlx(&sl);
		else
			sl_printstr(MSG_ERROR);
	}
	return (0);
}
