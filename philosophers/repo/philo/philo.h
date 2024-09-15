/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 22:34:08 by andeviei          #+#    #+#             */
/*   Updated: 2024/09/15 21:02:22 by andeviei         ###   ########.fr       */
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

typedef pthread_t		t_thrd;
typedef pthread_mutex_t	t_mutex;
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
	t_mutex	mutex;
	t_thrd	thrd;
	t_ulong	le;
}						t_guy;

typedef struct s_param
{
	t_ulong	num;
	t_ulong	ttd;
	t_ulong	tte;
	t_ulong	tts;
	t_bool	limited;
	t_ulong	limit;
}						t_param;

typedef struct s_sim
{
	t_mutex	*forks;
	t_mutex	mutex_print;
	t_tval	start;
}						t_sim;

typedef struct s_data
{
	t_param	param;
	t_sim	sim;
}						t_data;

void	error_exit(void);

t_bool	parsenum(char *str, t_ulong *n);

void	print_msg(t_data *data, t_ulong i, t_msg msg);

void	sim_fork_lock(t_data *data, t_ulong i);
void	sim_fork_unlock(t_data *data, t_ulong i);
void	sim_free(t_data *data);
t_bool	sim_init(t_data *data);

t_ulong	time_get(t_data *data);
t_bool	time_init(t_data *data);

#endif