/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 23:21:54 by andeviei          #+#    #+#             */
/*   Updated: 2024/09/16 14:47:16 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_state	state_get(t_data *data)
{
	t_state	state;

	pthread_mutex_lock(&(data->sim.mutex_check));
	state = data->sim.state;
	pthread_mutex_unlock(&(data->sim.mutex_check));
	return (state);
}

void	state_set(t_data *data, t_state state)
{
	pthread_mutex_lock(&(data->sim.mutex_check));
	data->sim.state = state;
	pthread_mutex_unlock(&(data->sim.mutex_check));
}

void	state_update(t_data *data)
{
	t_ulong	i;
	t_ulong	now;
	t_bool	sated;

	pthread_mutex_lock(&(data->sim.mutex_check));
	now = time_get(data);
	sated = data->param.limited;
	i = 0;
	while (i < data->param.num)
	{
		sated = sated && (data->sim.philos[i].times_eat >= data->param.limit);
		if (now - data->sim.philos[i].last_eat > data->param.ttd)
		{
			print_msg(data, i, MSG_DIE, TRUE);
			data->sim.state = STATE_DIE;
			break ;
		}
		i++;
	}
	if (sated)
		data->sim.state = STATE_DIE;
	pthread_mutex_unlock(&(data->sim.mutex_check));
}

void	state_eat(t_data *data, t_ulong i)
{
	pthread_mutex_lock(&(data->sim.mutex_check));
	data->sim.philos[i].last_eat = time_get(data);
	data->sim.philos[i].times_eat += 1;
	pthread_mutex_unlock(&(data->sim.mutex_check));
}
