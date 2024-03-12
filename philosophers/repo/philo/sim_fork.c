/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sim_fork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:06:07 by andeviei          #+#    #+#             */
/*   Updated: 2024/03/12 20:28:07 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	sim_fork_lock(t_philo *p, t_ulong i)
{
	pthread_mutex_lock(p->s.fk + (i % p->d.n));
}

void	sim_fork_unlock(t_philo *p, t_ulong i)
{
	pthread_mutex_unlock(p->s.fk + (i % p->d.n));
}
