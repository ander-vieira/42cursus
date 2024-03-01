/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 23:11:02 by andeviei          #+#    #+#             */
/*   Updated: 2024/03/01 23:29:55 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_ulong	*g_n(void)
{
	static t_ulong	n;

	return (&n);
}

static t_mutex	**g_mx(void)
{
	static t_mutex	*mx;

	return (&mx);
}

t_bool	mutex_init(t_ulong n)
{
	size_t	i;

	*g_n() = n;
	*g_mx() = (t_mutex *)malloc(sizeof(t_mutex) * *g_n());
	if (*g_mx() == NULL)
		return (FALSE);
	i = 0;
	while (i < *g_n())
	{
		if (pthread_mutex_init(*g_mx() + i, NULL) != 0)
			return (*g_n() = i, mutex_free(), FALSE);
		i++;
	}
	return (TRUE);
}

void	mutex_free(void)
{
	size_t	i;
	
	i = 0;
	while (i < *g_n())
	{
		pthread_mutex_destroy(*g_mx() + i);
		i++;
	}
	free(*g_mx());
}

t_mutex	mutex_get(t_ulong i)
{
	return ((*g_mx())[i % *g_n()]);
}
