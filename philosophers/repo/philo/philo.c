/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 22:30:08 by andeviei          #+#    #+#             */
/*   Updated: 2024/09/16 12:31:21 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_bool	philo_init(t_data *data, int argc, char **argv)
{
	data->param.limited = (argc == 6);
	return ((argc == 5 || argc == 6)
		&& parsenum(argv[1], &(data->param.num))
		&& parsenum(argv[2], &(data->param.ttd))
		&& parsenum(argv[3], &(data->param.tte))
		&& parsenum(argv[4], &(data->param.tts))
		&& (!data->param.limited || parsenum(argv[5], &(data->param.limit)))
		&& sim_init(data)
		&& time_init(data));
}

static void	philo_free(t_data *data)
{
	sim_free(data);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (!philo_init(&data, argc, argv))
		return (error_exit(), EXIT_FAILURE);
	while (state_get(&data) != STATE_DIE)
		state_update(&data);
	philo_free(&data);
	return (EXIT_SUCCESS);
}
