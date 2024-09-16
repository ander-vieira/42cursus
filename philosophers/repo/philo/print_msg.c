/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:15:40 by andeviei          #+#    #+#             */
/*   Updated: 2024/09/16 15:03:40 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_putstr(char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	write(STDOUT_FILENO, str, len);
}

static void	ft_putnbr(t_ulong n)
{
	if (n >= 10)
		ft_putnbr(n / 10);
	write(STDOUT_FILENO, &("0123456789"[n % 10]), 1);
}

void	print_msg(t_data *data, t_ulong i, t_msg msg, t_bool force)
{
	pthread_mutex_lock(&(data->sim.mutex_print));
	if (force || state_get(data) != STATE_DIE)
	{
		ft_putnbr(time_get(data));
		ft_putstr(" ");
		ft_putnbr(i % data->param.num);
		if (msg == MSG_FORK)
			ft_putstr(" has taken a fork\n");
		if (msg == MSG_EAT)
			ft_putstr(" is eating\n");
		if (msg == MSG_SLEEP)
			ft_putstr(" is sleeping\n");
		if (msg == MSG_THINK)
			ft_putstr(" is thinking\n");
		if (msg == MSG_DIE)
			ft_putstr(" died\n");
	}
	pthread_mutex_unlock((&data->sim.mutex_print));
}
