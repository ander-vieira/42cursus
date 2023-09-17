/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ander <ander@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 14:24:09 by ander             #+#    #+#             */
/*   Updated: 2023/09/18 00:25:54 by ander            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static unsigned int	g_testcount;
static unsigned int	g_totaltests;

void	print_test(char *test_id, char result)
{
	g_totaltests++;
	printf("%s ", test_id);
	if (result)
	{
		printf("OK\n");
		g_testcount++;
	}
	else
		printf("KO\n");
}

int	main(void)
{
	g_testcount = 0;
	g_totaltests = 0;
	test_is();
	test_to();
	test_mem();
	test_split();
	if (g_testcount == g_totaltests)
		printf("ALL TESTS OK\n");
	return (0);
}
