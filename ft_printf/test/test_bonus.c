/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 12:46:15 by andeviei          #+#    #+#             */
/*   Updated: 2023/09/24 15:46:34 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../repo/libftprintf.h"

void	test_alter(void)
{
	int	n;
	
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

	n = ft_printf("%+d\n", 15);
	ft_printf("%d\n", n);
	n = ft_printf("% d\n", 15);
	ft_printf("%d\n", n);
	n = ft_printf("%+d\n", -15);
	ft_printf("%d\n", n);
	n = ft_printf("% d\n", -15);
	ft_printf("%d\n", n);
}

int	main(void)
{
	test_alter();
	test_sign();
	return (0);
}