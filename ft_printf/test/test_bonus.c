/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 12:46:15 by andeviei          #+#    #+#             */
/*   Updated: 2023/10/19 15:31:57 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../repo/ft_printf.h"

void	test_alter(void)
{
	int	n;

	ft_printf("----- ALTER\n");
	n = ft_printf("%#x\n", 0x5A);
	ft_printf("%d\n", n);
	n = ft_printf("%#X\n", 0x5A);
	ft_printf("%d\n", n);
	n = ft_printf("%#x\n", 0);
	ft_printf("%d\n", n);
}

void	test_sign(void)
{
	int	n;

	ft_printf("----- SIGN\n");
	n = ft_printf("%+d\n", 15);
	ft_printf("%d\n", n);
	n = ft_printf("% d\n", 15);
	ft_printf("%d\n", n);
	n = ft_printf("%+d\n", -15);
	ft_printf("%d\n", n);
	n = ft_printf("% d\n", -15);
	ft_printf("%d\n", n);
	n = ft_printf("% s\n", "");
	ft_printf("%d\n", n);
	n = ft_printf("% s\n", "a");
	ft_printf("%d\n", n);
}

void	test_pad(void)
{
	int	n;

	ft_printf("----- PAD\n");
	n = ft_printf("%5dk\n", 15);
	ft_printf("%d\n", n);
	n = ft_printf("%-5sk\n", "PP");
	ft_printf("%d\n", n);
	n = ft_printf("%05xk\n", 0x4F);
	ft_printf("%d\n", n);
	n = ft_printf("%-05dk\n", -50);
	ft_printf("%d\n", n);
}

void	test_prec(void)
{
	int	n;

	ft_printf("----- PREC\n");
	n = ft_printf("%.5d\n", 15);
	ft_printf("%d\n", n);
	n = ft_printf("%.5s\n", "HELLO WORLD");
	ft_printf("%d\n", n);
}

int	main(void)
{
	test_alter();
	test_sign();
	//test_pad();
	//test_prec();
	return (0);
}
