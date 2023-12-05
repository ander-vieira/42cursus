/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 20:02:23 by andeviei          #+#    #+#             */
/*   Updated: 2023/12/05 21:38:59 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

static void	test_printchar(void)
{
	char	buf[5];
	t_fd	fd[2];

	print_title("PRINTCHAR");
	pipe(fd);
	print_test("1", ft_printchar(fd[1], 'c') == 1, FALSE);
	print_test("2", ft_printchar(fd[1], '5') == 1, FALSE);
	print_test("3", ft_printchar(fd[1], ' ') == 1, FALSE);
	print_test("4", ft_printchar(fd[1], '\n') == 1, FALSE);
	close(fd[1]);
	print_test("5", read(fd[0], buf, 5) == 4, FALSE);
	close(fd[0]);
	print_test("6", buf[0] == 'c', FALSE);
	print_test("7", buf[1] == '5', FALSE);
	print_test("8", buf[2] == ' ', FALSE);
	print_test("9", buf[3] == '\n', TRUE);
}

static void	test_printnbrs(void)
{
	char	buf[5];
	t_fd	fd[2];

	print_title("PRINTNBRS");
	pipe(fd);
	print_test("1", ft_printnbrs(fd[1], 500, BASE_DEC) == 3, FALSE);
	print_test("2", ft_printnbrs(fd[1], -500, BASE_DEC) == 4, FALSE);
	print_test("3", ft_printnbrs(fd[1], 0, BASE_DEC) == 1, FALSE);
	print_test("3", ft_printnbrs(fd[1], 0, ",.") == 1, FALSE);
	print_test("4", ft_printnbrs(fd[1], -106, BASE_HXL) == 3, FALSE);
	close(fd[1]);
	read(fd[0], buf, 3);
	print_test("5", !memcmp(buf, "500", 3), FALSE);
	read(fd[0], buf, 4);
	print_test("6", !memcmp(buf, "-500", 1), FALSE);
	read(fd[0], buf, 1);
	print_test("7", !memcmp(buf, "0", 1), FALSE);
	read(fd[0], buf, 1);
	print_test("8", !memcmp(buf, ",", 1), FALSE);
	print_test("9", read(fd[0], buf, 5) == 3, FALSE);
	print_test("10", !memcmp(buf, "-6a", 3), TRUE);
	close(fd[0]);
}

static void	test_printnbru(void)
{
	char	buf[4];
	t_fd	fd[2];

	print_title("PRINTNBRU");
	pipe(fd);
	print_test("1", ft_printnbru(fd[1], 500, BASE_DEC) == 3, FALSE);
	print_test("2", ft_printnbru(fd[1], 0, BASE_DEC) == 1, FALSE);
	print_test("3", ft_printnbru(fd[1], 101, BASE_HXL) == 2, FALSE);
	print_test("4", ft_printnbru(fd[1], 2730, BASE_HXL) == 3, FALSE);
	print_test("5", ft_printnbru(fd[1], 2730, BASE_HXU) == 3, FALSE);
	close(fd[1]);
	read(fd[0], buf, 3);
	print_test("6", !memcmp(buf, "500", 3), FALSE);
	read(fd[0], buf, 1);
	print_test("7", !memcmp(buf, "0", 1), FALSE);
	read(fd[0], buf, 2);
	print_test("8", !memcmp(buf, "65", 2), FALSE);
	read(fd[0], buf, 3);
	print_test("9", !memcmp(buf, "aaa", 3), FALSE);
	print_test("10", read(fd[0], buf, 4) == 3, FALSE);
	print_test("11", !memcmp(buf, "AAA", 3), TRUE);
	close(fd[0]);
}

static void	test_printstr(void)
{
	char	buf[15];
	t_fd	fd[2];

	print_title("PRINTSTR");
	pipe(fd);
	print_test("1", ft_printstr(fd[1], "HELLO ") == 6, FALSE);
	print_test("2", ft_printstr(fd[1], "WORLD") == 5, FALSE);
	print_test("3", ft_printstr(fd[1], "") == 0, FALSE);
	close(fd[1]);
	print_test("4", read(fd[0], buf, 15) == 11, FALSE);
	close(fd[0]);
	print_test("5", !memcmp(buf, "HELLO WORLD", 11), TRUE);
}

void	test_print(void)
{
	test_printchar();
	test_printnbrs();
	test_printnbru();
	test_printstr();
}
