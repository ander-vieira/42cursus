/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 20:28:35 by andeviei          #+#    #+#             */
/*   Updated: 2023/12/05 20:38:44 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

static void	test_printf1(void)
{
	char	buf[20];
	t_fd	fd[2];

	pipe(fd);
	print_test("1", ft_printf(fd[1], "HELL%c WO%c%s!", 'O', 'R', "LD") == 12, FALSE);
	close(fd[1]);
	print_test("2", read(fd[0], buf, 20) == 12, FALSE);
	close(fd[0]);
	print_test("3", !memcmp(buf, "HELLO WORLD!", 12), FALSE);
}

static void	test_printf2(void)
{
	char	buf[50];
	t_fd	fd[2];

	pipe(fd);
	print_test("4", ft_printf(fd[1], "abs(%d) is %u, not %u, or in hex 0x%x", -4242, 4242, 0, 4242) == 43, FALSE);
	close(fd[1]);
	print_test("5", read(fd[0], buf, 50) == 43, FALSE);
	close(fd[0]);
	print_test("6", !memcmp(buf, "abs(-4242) is 4242, not 0, or in hex 0x1092", 43), FALSE);
}

static void	test_printf3(void)
{
	char	buf[50];
	t_fd	fd[2];

	pipe(fd);
	print_test("7", ft_printf(fd[1], "%i + 0X%X + %d = %u (0x%x)", -33, 30, 33, 30, 30) == 27, FALSE);
	close(fd[1]);
	print_test("8", read(fd[0], buf, 50) == 27, FALSE);
	close(fd[0]);
	print_test("9", !memcmp(buf, "-33 + 0X1E + 33 = 30 (0x1e)", 27), TRUE);
}

void	test_printf(void)
{
	print_title("PRINTF");
	test_printf1();
	test_printf2();
	test_printf3();
}