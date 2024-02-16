/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:15:41 by andeviei          #+#    #+#             */
/*   Updated: 2024/02/16 15:26:19 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	exit_error(void)
{
	ft_printf(STDERR_FILENO, "Error\n");
	exit(EXIT_FAILURE);
}

void	read_args(int argc, char **argv)
{
	int	num;

	if (argc == 1)
		exit(EXIT_SUCCESS);
	while (argc > 1)
	{
		argc = argc - 1;
		num = ft_parsenum(argv[argc], BASE_DEC);
		if (ft_geterror() != FTERR_OK || stack_find(*g_a(), NULL, num))
			exit_error();
		stack_push(g_a(), num);
	}
}
