/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 22:48:15 by andeviei          #+#    #+#             */
/*   Updated: 2024/09/16 14:35:04 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	get_forks(t_data *data, t_ulong i)
{
	if (i % 2 == 0)
	{
		pthread_mutex_lock(&(data->sim.philos[i].fork));
		print_msg(data, i, MSG_FORK, FALSE);
		pthread_mutex_lock(&(data->sim.philos[(i + 1) % data->param.num].fork));
		print_msg(data, i, MSG_FORK, FALSE);
	}
	else
	{
		pthread_mutex_lock(&(data->sim.philos[(i + 1) % data->param.num].fork));
		print_msg(data, i, MSG_FORK, FALSE);
		pthread_mutex_lock(&(data->sim.philos[i].fork));
		print_msg(data, i, MSG_FORK, FALSE);
	}
}

static void	release_forks(t_data *data, t_ulong i)
{
	pthread_mutex_unlock(&(data->sim.philos[i].fork));
	pthread_mutex_unlock(&(data->sim.philos[(i + 1) % data->param.num].fork));
}

static void	*philo_thread(void *ptr)
{
	t_child	*child;

	child = (t_child *)ptr;
	while (state_get(child->data) == STATE_WAIT)
		;
	if (child->i % 2 == 1)
		time_wait(500);
	if (child->data->param.num == 1)
		print_msg(child->data, 0, MSG_FORK, FALSE);
	while (state_get(child->data) != STATE_DIE)
	{
		if (child->data->param.num == 1)
			continue ;
		get_forks(child->data, child->i);
		print_msg(child->data, child->i, MSG_EAT, FALSE);
		time_wait(child->data->param.tte * 1000);
		release_forks(child->data, child->i);
		print_msg(child->data, child->i, MSG_SLEEP, FALSE);
		state_eat(child->data, child->i);
		time_wait(child->data->param.tts * 1000);
		print_msg(child->data, child->i, MSG_THINK, FALSE);
		time_wait(child->data->param.ttt * 1000);
	}
	return (free(child), NULL);
}

t_bool	start_philo(t_data *data, t_ulong i)
{
	t_child	*child;
	int		ret;

	child = (t_child *)malloc(sizeof(t_child));
	if (child == NULL)
		return (FALSE);
	child->data = data;
	child->i = i;
	ret = pthread_create(&(data->sim.philos[i].thrd),
			NULL, &philo_thread, child);
	if (ret != 0)
		return (free(child), FALSE);
	return (TRUE);
}
