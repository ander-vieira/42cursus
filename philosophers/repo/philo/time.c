/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:21:34 by andeviei          #+#    #+#             */
/*   Updated: 2024/03/12 20:27:35 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_ulong	time_get(t_philo *p)
{
	struct timeval	now;
	t_ulong			time;

	if (gettimeofday(&now, NULL) == -1)
		return (0);
	if (now.tv_usec < p->s.st.tv_usec)
	{
		now.tv_usec += 1000000;
		now.tv_sec -= 1;
	}
	time = (now.tv_sec - p->s.st.tv_sec) * 1000;
	time += (now.tv_usec - p->s.st.tv_usec) / 1000;
	return (time);
}

t_bool	time_init(t_philo *p)
{
	return (gettimeofday(&(p->s.st), NULL) != -1);
}
