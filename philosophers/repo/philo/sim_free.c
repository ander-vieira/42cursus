/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sim_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:03:59 by andeviei          #+#    #+#             */
/*   Updated: 2024/09/16 10:15:52 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	sim_freephilos(t_data *data)
{
	t_ulong	i;

	state_set(data, STATE_DIE);
	i = 0;
	while (i < data->param.num)
	{
		pthread_join(data->sim.philos[i].thrd, NULL);
		i++;
	}
	i = 0;
	while (i < data->param.num)
	{
		pthread_mutex_destroy(&(data->sim.philos[i].fork));
		i++;
	}
	free(data->sim.philos);
	data->sim.philos = NULL;
}

void	sim_free(t_data *data)
{
	sim_freephilos(data);
	pthread_mutex_destroy(&(data->sim.mutex_print));
	pthread_mutex_destroy(&(data->sim.mutex_check));
}
