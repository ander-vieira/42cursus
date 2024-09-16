/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:21:34 by andeviei          #+#    #+#             */
/*   Updated: 2024/09/16 14:10:49 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_ulong	time_get(t_data *data)
{
	t_tval	now;
	t_ulong	time;

	gettimeofday(&now, NULL);
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
	int	ret;

	pthread_mutex_lock(&(data->sim.mutex_check));
	ret = gettimeofday(&(data->sim.start), NULL);
	pthread_mutex_unlock(&(data->sim.mutex_check));
	return (ret != -1);
}

// void	time_wait(t_ulong usec)
// {
// 	t_tval	now;
// 	t_tval	start;
// 	t_ulong	passed;

// 	gettimeofday(&start, NULL);
// 	while (TRUE)
// 	{
// 		gettimeofday(&now, NULL);
// 		if (now.tv_usec < start.tv_usec)
// 		{
// 			now.tv_usec += 1000000;
// 			now.tv_sec -= 1;
// 		}
// 		passed = (now.tv_sec - start.tv_sec) * 1000000;
// 		passed += now.tv_usec - start.tv_usec;
// 		if (passed >= usec)
// 			break ;
// 	}
// }

void	time_wait(t_ulong usec)
{
	usleep(usec);
}
