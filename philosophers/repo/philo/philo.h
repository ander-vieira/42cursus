/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 22:34:08 by andeviei          #+#    #+#             */
/*   Updated: 2024/09/16 14:31:42 by andeviei         ###   ########.fr       */
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

typedef enum e_state
{
	STATE_WAIT,
	STATE_GO,
	STATE_DIE
}						t_state;

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

typedef struct s_param
{
	t_ulong	num;
	t_ulong	ttd;
	t_ulong	tte;
	t_ulong	tts;
	t_ulong	ttt;
	t_bool	limited;
	t_ulong	limit;
}						t_param;

typedef struct s_philo
{
	t_mutex	fork;
	t_thrd	thrd;
	t_ulong	last_eat;
	t_ulong	times_eat;
}						t_philo;

typedef struct s_sim
{
	t_philo	*philos;
	t_mutex	mutex_print;
	t_mutex	mutex_check;
	t_tval	start;
	t_state	state;
}						t_sim;

typedef struct s_data
{
	t_param	param;
	t_sim	sim;
}						t_data;

typedef struct s_child
{
	t_data	*data;
	t_ulong	i;
}						t_child;

void	error_exit(void);

t_bool	parsenum(char *str, t_ulong *n);

void	print_msg(t_data *data, t_ulong i, t_msg msg, t_bool force);

void	sim_free(t_data *data);
t_bool	sim_init(t_data *data);

t_bool	start_philo(t_data *data, t_ulong i);

t_state	state_get(t_data *data);
void	state_set(t_data *data, t_state state);
void	state_update(t_data *data);
void	state_eat(t_data *data, t_ulong i);

t_ulong	time_get(t_data *data);
t_bool	time_init(t_data *data);
void	time_wait(t_ulong usec);

#endif