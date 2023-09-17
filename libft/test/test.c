/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ander <ander@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 14:24:09 by ander             #+#    #+#             */
/*   Updated: 2023/09/17 17:13:22 by ander            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	print_test(char *test_id, char result)
{
	printf("%s ", test_id);
	if (result)
		printf("OK\n");
	else
		printf("KO\n");
}

int	main(void)
{
	size_t	result;

	result = 0;
	result += test_split();
	if (result == TOTAL_TESTS)
		printf("ALL TESTS OK\n");
	return (0);
}
