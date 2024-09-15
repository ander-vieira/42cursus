/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sim_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:55:54 by andeviei          #+#    #+#             */
/*   Updated: 2024/09/15 21:04:06 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	sim_initforks_free(t_data *data, size_t i)
{
	size_t	j;

	j = 0;
	while (j < i)
	{
		pthread_mutex_destroy(data->sim.forks + j);
		j++;
	}
	free(data->sim.forks);
	data->sim.forks = NULL;
}

static t_bool	sim_initforks(t_data *data)
{
	size_t	i;

	data->sim.forks = (t_mutex *)malloc(sizeof(t_mutex) * data->param.num);
	if (data->sim.forks == NULL)
		return (FALSE);
	i = 0;
	while (i < data->param.num)
	{
		if (pthread_mutex_init(data->sim.forks + i, NULL) != 0)
			return (sim_initforks_free(data, i), FALSE);
		i++;
	}
	return (TRUE);
}

static t_bool	sim_initprint(t_data *data)
{
	return (pthread_mutex_init(&(data->sim.mutex_print), NULL) == 0);
}

t_bool	sim_init(t_data *data)
{
	if (!sim_initforks(data))
		return (FALSE);
	if (!sim_initprint(data))
		return (sim_initforks_free(data, data->param.num), FALSE);
	return (TRUE);
}
