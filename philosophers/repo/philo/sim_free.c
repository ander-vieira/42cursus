/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sim_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:03:59 by andeviei          #+#    #+#             */
/*   Updated: 2024/09/15 21:03:59 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	sim_freeforks(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->param.num)
	{
		pthread_mutex_destroy(data->sim.forks + i);
		i++;
	}
	free(data->sim.forks);
	data->sim.forks = NULL;
}

static void	sim_freeprint(t_data *data)
{
	pthread_mutex_destroy(&(data->sim.mutex_print));
}

void	sim_free(t_data *data)
{
	sim_freeforks(data);
	sim_freeprint(data);
}
