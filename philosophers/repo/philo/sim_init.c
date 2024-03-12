/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sim_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:55:54 by andeviei          #+#    #+#             */
/*   Updated: 2024/03/12 20:30:55 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	sim_initforks_free(t_philo *p, size_t i)
{
	size_t	j;

	j = 0;
	while (j < i)
	{
		pthread_mutex_destroy(p->s.fk + j);
		j++;
	}
	free(p->s.fk);
	p->s.fk = NULL;
}

static t_bool	sim_initforks(t_philo *p)
{
	size_t	i;

	p->s.fk = (t_mx *)malloc(sizeof(t_mx) * p->d.n);
	if (p->s.fk == NULL)
		return (free(p->s.g), FALSE);
	i = 0;
	while (i < p->d.n)
	{
		if (pthread_mutex_init(p->s.fk + i, NULL) != 0)
			return (sim_initforks_free(p, i), FALSE);
		i++;
	}
	return (TRUE);
}

static t_bool	sim_initguys(t_philo *p)
{
	p->s.g = (t_guy *)malloc(sizeof(t_guy) * p->d.n);
	if (p->s.g == NULL)
		return (FALSE);
	return (TRUE);
}

static t_bool	sim_initprint(t_philo *p)
{
	return (pthread_mutex_init(&(p->s.mx_p), NULL) == 0);
}

t_bool	sim_init(t_philo *p)
{
	if (!sim_initforks(p))
		return (FALSE);
	if (!sim_initguys(p))
		return (sim_initforks_free(p, p->d.n), FALSE);
	if (!sim_initprint(p))
		return (sim_initforks_free(p, p->d.n), free(p->s.g), FALSE);
	return (TRUE);
}
