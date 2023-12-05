/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:46:16 by andeviei          #+#    #+#             */
/*   Updated: 2023/12/05 16:04:43 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

t_uint	g_failed = 0;

void	print_title(char *title)
{
	printf("----   %s   ----\n", title);
}

void	print_test(char *text, t_bool ok, t_bool last)
{
	printf("[%s: ", text);
	if (ok)
		printf(COLOR_GREEN"OK"COLOR_NONE);
	else
	{
		printf(COLOR_RED"KO"COLOR_NONE);
		g_failed++;
	}
	printf("]");
	if (last)
		printf("\n");
	else
		printf(" ");
}

int	print_all_tests(void)
{
	print_title("ALL TESTS");
	if (g_failed == 0)
	{
		printf(COLOR_GREEN"All tests OK!\n"COLOR_NONE);
		return (EXIT_SUCCESS);
	}
	else
	{
		printf(COLOR_RED"Errors detected, please review.\n"COLOR_NONE);
		return (EXIT_FAILURE);
	}
}
