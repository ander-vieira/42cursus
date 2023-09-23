/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 17:09:02 by andeviei          #+#    #+#             */
/*   Updated: 2023/09/23 18:33:26 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../repo/libftprintf.h"

int	main(void)
{
	int	n;

	n = ft_printf("%c\n", ';');
	ft_printf("%d\n", n);
	n = ft_printf("%s\n", "HELLO WORLD");
	ft_printf("%d\n", n);
	n = ft_printf("%i\n", 2147483647);
	ft_printf("%d\n", n);
	n = ft_printf("%d\n", (int)-2147483648);
	ft_printf("%d\n", n);
	n = ft_printf("%u\n", (unsigned int)4294967295);
	ft_printf("%d\n", n);
	n = ft_printf("%x\n", -0xA8);
	ft_printf("%d\n", n);
	n = ft_printf("%X\n", 0x5F);
	ft_printf("%d\n", n);
	n = ft_printf("%p\n", NULL);
	ft_printf("%d\n", n);
	n = ft_printf("%p\n", (void *)0x7ffd764d44b4);
	ft_printf("%d\n", n);
	return (0);
}
