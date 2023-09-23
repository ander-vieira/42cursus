/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 12:26:18 by andeviei          #+#    #+#             */
/*   Updated: 2023/09/23 18:24:43 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(void)
{
	int	n;

	n = printf("%c\n", ';');
	printf("%d\n", n);
	n = printf("%s\n", "HELLO WORLD");
	printf("%d\n", n);
	n = printf("%i\n", 2147483647);
	printf("%d\n", n);
	n = printf("%d\n", (int)-2147483648);
	printf("%d\n", n);
	n = printf("%u\n", (unsigned int)4294967295);
	printf("%d\n", n);
	n = printf("%x\n", -0xA8);
	printf("%d\n", n);
	n = printf("%X\n", 0x5F);
	printf("%d\n", n);
	n = printf("%p\n", NULL);
	printf("%d\n", n);
	n = printf("%p\n", (void *)0x7ffd764d44b4);
	printf("%d\n", n);
	return (0);
}
