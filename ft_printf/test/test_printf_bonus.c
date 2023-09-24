/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_printf_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 12:46:15 by andeviei          #+#    #+#             */
/*   Updated: 2023/09/24 15:46:53 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	test_alter(void)
{
	int	n;
	
	n = printf("%#x\n", 0x5A);
	printf("%d\n", n);
	n = printf("%#X\n", 0x5A);
	printf("%d\n", n);
	n = printf("%#x\n", 0);
	printf("%d\n", n);
}

void	test_sign(void)
{
	int	n;

	n = printf("%+d\n", 15);
	printf("%d\n", n);
	n = printf("% d\n", 15);
	printf("%d\n", n);
	n = printf("%+d\n", -15);
	printf("%d\n", n);
	n = printf("% d\n", -15);
	printf("%d\n", n);
}

int	main(void)
{
	test_alter();
	test_sign();
	return (0);
}