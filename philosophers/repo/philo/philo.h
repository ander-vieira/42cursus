/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 22:34:08 by andeviei          #+#    #+#             */
/*   Updated: 2024/03/12 20:30:05 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef unsigned long	t_ulong;
typedef char			*t_str;

typedef enum e_bool
{
	FALSE,
	TRUE
}						t_bool;

typedef pthread_t		t_th;
typedef pthread_mutex_t	t_mx;
typedef struct timeval	t_tval;

typedef enum e_msg
{
	MSG_FORK,
	MSG_EAT,
	MSG_SLEEP,
	MSG_THINK,
	MSG_DIE
}						t_msg;

typedef struct s_guy
{
	t_mx	mx;
	t_th	th;
	t_ulong	le;
}						t_guy;

typedef struct s_data
{
	t_ulong	n;
	t_ulong	d;
	t_ulong	e;
	t_ulong	s;
	t_bool	h;
	t_ulong	l;
}						t_data;

typedef struct s_sim
{
	t_mx	*fk;
	t_guy	*g;
	t_mx	mx_p;
	t_tval	st;
}						t_sim;

typedef struct s_philo
{
	t_data	d;
	t_sim	s;
}						t_philo;

void	error_exit(void);

t_bool	parsenum(char *str, t_ulong *n);

void	print_msg(t_philo *p, t_ulong i, t_msg msg);

void	sim_fork_lock(t_philo *p, t_ulong i);
void	sim_fork_unlock(t_philo *p, t_ulong i);
void	sim_free(t_philo *p);
t_bool	sim_init(t_philo *p);

t_ulong	time_get(t_philo *p);
t_bool	time_init(t_philo *p);

#endif