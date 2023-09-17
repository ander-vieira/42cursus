/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ander <ander@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 17:09:02 by ander             #+#    #+#             */
/*   Updated: 2023/09/17 17:11:04 by ander            ###   ########.fr       */
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
	int	n;

	n = printf("The character is: %c\n", ';');
	printf("Chars printed: %d\n", n);
	n = ft_printf("The character is: %c\n", ';');
	printf("Chars printed: %d\n", n);
	printf("The number is: %d\n", 15);
	ft_printf("The number is: %d\n", 15);
	printf("The number is: %k\n", 5);
	ft_printf("The number is: %k\n", 5);
	return (0);
}
