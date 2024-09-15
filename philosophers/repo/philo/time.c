/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:21:34 by andeviei          #+#    #+#             */
/*   Updated: 2024/09/15 20:59:19 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_ulong	time_get(t_data *data)
{
	struct timeval	now;
	t_ulong			time;

	if (gettimeofday(&now, NULL) == -1)
		return (0);
	if (now.tv_usec < data->sim.start.tv_usec)
	{
		now.tv_usec += 1000000;
		now.tv_sec -= 1;
	}
	time = (now.tv_sec - data->sim.start.tv_sec) * 1000;
	time += (now.tv_usec - data->sim.start.tv_usec) / 1000;
	return (time);
}

t_bool	time_init(t_data *data)
{
	return (gettimeofday(&(data->sim.start), NULL) != -1);
}
