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

int	main(void)
{
	g_failed = 0;
	test_is();
	test_to();
	test_mem();
	test_str();
	test_split();
	test_atoi();
	test_fd();
	test_bonus();
	if (g_failed != 0)
		printf("ALL TESTS OK\n");
	return (0);
}
