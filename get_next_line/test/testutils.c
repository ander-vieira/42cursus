/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testutils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:43:10 by andeviei          #+#    #+#             */
/*   Updated: 2023/09/18 13:43:10 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testutils.h"

static unsigned int	g_failed;

void	print_test(char *test_id, char result)
{
	printf("%s ", test_id);
	if (result)
		printf("OK\n");
	else
	{
		g_failed++;
		printf("KO\n");
	}
}

void	print_all_tests(void)
{
	if (g_failed == 0)
		printf("ALL TESTS OK\n");
}
