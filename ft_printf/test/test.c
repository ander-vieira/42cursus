/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 17:09:02 by andeviei          #+#    #+#             */
/*   Updated: 2023/09/18 17:46:55 by andeviei         ###   ########.fr       */
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
