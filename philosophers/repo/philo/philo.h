/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 22:34:08 by andeviei          #+#    #+#             */
/*   Updated: 2024/03/01 23:25:46 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>

typedef enum e_bool
{
	FALSE,
	TRUE
}						t_bool;

typedef unsigned long	t_ulong;
typedef char			*t_str;

typedef pthread_mutex_t	t_mutex;

typedef struct s_philo
{
	t_ulong	n;
	t_ulong	ttd;
	t_ulong	tte;
	t_ulong	tts;
	t_bool	hl;
	t_ulong	el;
	t_mutex	*mx;
}						t_philo;

t_bool	mutex_init(t_ulong n);
void	mutex_free(void);
t_mutex	mutex_get(t_ulong i);

t_bool	parsenum(char *str, t_ulong *n);

#endif