/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sim_fork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:06:07 by andeviei          #+#    #+#             */
/*   Updated: 2024/09/15 20:57:29 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	sim_fork_lock(t_data *data, t_ulong i)
{
	pthread_mutex_lock(data->sim.forks + (i % data->param.num));
}

void	sim_fork_unlock(t_data *data, t_ulong i)
{
	pthread_mutex_unlock(data->sim.forks + (i % data->param.num));
}
