/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 22:30:08 by andeviei          #+#    #+#             */
/*   Updated: 2024/03/12 20:31:05 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_bool	philo_init(t_philo *p, int argc, char **argv)
{
	p->d.h = (argc == 6);
	return ((argc == 5 || argc == 6)
		&& parsenum(argv[1], &(p->d.n))
		&& parsenum(argv[2], &(p->d.d))
		&& parsenum(argv[3], &(p->d.e))
		&& parsenum(argv[4], &(p->d.s))
		&& (!p->d.h || parsenum(argv[5], &(p->d.l)))
		&& sim_init(p)
		&& time_init(p));
}

static void	philo_free(t_philo *p)
{
	sim_free(p);
}

int	main(int argc, char **argv)
{
	t_philo	p;

	if (!philo_init(&p, argc, argv))
		error_exit();
	usleep(p.d.d * 1000);
	print_msg(&p, 0, MSG_DIE);
	usleep(p.d.d * 1000);
	print_msg(&p, 1, MSG_DIE);
	philo_free(&p);
	return (EXIT_SUCCESS);
}
