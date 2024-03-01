/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 22:30:08 by andeviei          #+#    #+#             */
/*   Updated: 2024/03/01 23:30:41 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	exit_error(void)
{
	write(STDERR_FILENO, "Error\n", 6);
	exit(EXIT_FAILURE);
}

static t_philo	read_args(int argc, char **argv)
{
	t_philo	philo;

	if (argc != 5 && argc != 6)
		exit_error();
	if (!parsenum(argv[1], &(philo.n)))
		exit_error();
	if (!parsenum(argv[2], &(philo.ttd)))
		exit_error();
	if (!parsenum(argv[3], &(philo.tte)))
		exit_error();
	if (!parsenum(argv[4], &(philo.tts)))
		exit_error();
	philo.hl = (argc == 6);
	if (philo.hl && !parsenum(argv[5], &(philo.el)))
		exit_error();
	return (philo);
}

int	main(int argc, char **argv)
{
	t_philo	philo;

	philo = read_args(argc, argv);
	if (!mutex_init(philo.n))
		exit_error();
	printf("%lu %lu %lu %lu\n", philo.n, philo.ttd, philo.tte, philo.tts);
	mutex_free();
	return (EXIT_SUCCESS);
}
