/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:15:40 by andeviei          #+#    #+#             */
/*   Updated: 2024/03/12 20:30:08 by andeviei         ###   ########.fr       */
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
	write(1, &("0123456789"[n % 10]), 1);
}

void	print_msg(t_philo *p, t_ulong i, t_msg msg)
{
	pthread_mutex_lock(&(p->s.mx_p));
	ft_putnbr(time_get(p));
	ft_putstr(" ");
	ft_putnbr(i % p->d.n);
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
	pthread_mutex_unlock((&p->s.mx_p));
}
