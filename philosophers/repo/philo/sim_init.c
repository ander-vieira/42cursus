/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sim_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:55:54 by andeviei          #+#    #+#             */
/*   Updated: 2024/09/17 13:41:54 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	sim_initmutex_free(t_data *data)
{
	pthread_mutex_destroy(&(data->sim.mutex_print));
	pthread_mutex_destroy(&(data->sim.mutex_check));
}

static t_bool	sim_initmutex(t_data *data)
{
	if (pthread_mutex_init(&(data->sim.mutex_print), NULL) != 0)
		return (FALSE);
	if (pthread_mutex_init(&(data->sim.mutex_check), NULL) != 0)
		return (pthread_mutex_destroy(&(data->sim.mutex_print)), FALSE);
	return (TRUE);
}

static void	sim_initphilos_free(t_data *data, t_ulong f_n, t_ulong t_n)
{
	t_ulong	i;

	state_set(data, STATE_DIE);
	i = 0;
	while (i < t_n)
	{
		pthread_join(data->sim.philos[i].thrd, NULL);
		i++;
	}
	i = 0;
	while (i < f_n)
	{
		pthread_mutex_destroy(&(data->sim.philos[i].fork));
		i++;
	}
	free(data->sim.philos);
	data->sim.philos = NULL;
}

static t_bool	sim_initphilos(t_data *data)
{
	t_ulong	i;

	data->sim.philos = (t_philo *)malloc(sizeof(t_philo) * data->param.num);
	if (data->sim.philos == NULL)
		return (FALSE);
	i = 0;
	while (i < data->param.num)
	{
		if (pthread_mutex_init(&(data->sim.philos[i].fork), NULL) != 0)
			return (sim_initphilos_free(data, i, 0), FALSE);
		data->sim.philos[i].last_eat = 0;
		data->sim.philos[i].times_eat = 0;
		i++;
	}
	i = 0;
	while (i < data->param.num)
	{
		if (!start_philo(data, i))
			return (sim_initphilos_free(data, data->param.num, i), FALSE);
		i++;
	}
	return (TRUE);
}

t_bool	sim_init(t_data *data)
{
	data->param.ttt = 1;
	if (data->param.tte > data->param.tts)
		data->param.ttt += data->param.tte - data->param.tts;
	if (!sim_initmutex(data))
		return (FALSE);
	data->sim.state = STATE_WAIT;
	if (!sim_initphilos(data))
		return (sim_initmutex_free(data), FALSE);
	time_wait(20000);
	if (!time_init(data))
		return (sim_initmutex_free(data),
			sim_initphilos_free(data, data->param.num, data->param.num), FALSE);
	state_set(data, STATE_GO);
	return (TRUE);
}
