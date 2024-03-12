/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sim_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:03:59 by andeviei          #+#    #+#             */
/*   Updated: 2024/03/12 20:30:02 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	sim_freeforks(t_philo *p)
{
	size_t	i;

	i = 0;
	while (i < p->d.n)
	{
		pthread_mutex_destroy(p->s.fk + i);
		i++;
	}
	free(p->s.fk);
	p->s.fk = NULL;
}

static void	sim_freeguys(t_philo *p)
{
	free(p->s.g);
	p->s.g = NULL;
}

static void	sim_freeprint(t_philo *p)
{
	pthread_mutex_destroy(&(p->s.mx_p));
}

void	sim_free(t_philo *p)
{
	sim_freeforks(p);
	sim_freeguys(p);
	sim_freeprint(p);
}
