/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_printf_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 12:46:15 by andeviei          #+#    #+#             */
/*   Updated: 2023/10/19 20:10:59 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	test_alter(void)
{
	int	n;

	printf("----- ALTER\n");
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

	printf("----- SIGN\n");
	n = printf("%+d\n", 15);
	printf("%d\n", n);
	n = printf("% d\n", 15);
	printf("%d\n", n);
	n = printf("%+d\n", -15);
	printf("%d\n", n);
	n = printf("% d\n", -15);
	printf("%d\n", n);
}

void	test_pad(void)
{
	int	n;

	printf("----- PAD\n");
	n = printf("%5dk\n", 15);
	printf("%d\n", n);
	n = printf("%05dk\n", -15);
	printf("%d\n", n);
	n = printf("%-5sk\n", "PP");
	printf("%d\n", n);
	n = printf("%05xk\n", 0x4F);
	printf("%d\n", n);
	n = printf("%-05dk\n", -50);
	printf("%d\n", n);
}

void	test_prec(void)
{
	int	n;

	printf("----- PREC\n");
	n = printf("%.5d\n", 15);
	printf("%d\n", n);
	n = printf("%.5s\n", "HELLO WORLD");
	printf("%d\n", n);
}

int	main(void)
{
	test_alter();
	test_sign();
	test_pad();
	test_prec();
	return (0);
}
