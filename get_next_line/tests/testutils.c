/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testutils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:43:10 by andeviei          #+#    #+#             */
/*   Updated: 2023/11/22 21:22:05 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testutils.h"

static unsigned int	g_failed;

void	print_test(char *test_id, char result)
{
	printf("%s: ", test_id);
	if (result)
		printf(COLOR_G"OK\n"COLOR_NO);
	else
	{
		g_failed++;
		printf(COLOR_R"KO\n"COLOR_NO);
	}
}

void	print_all_tests(void)
{
	if (g_failed == 0)
		printf(COLOR_G"ALL TESTS OK\n"COLOR_NO);
}
