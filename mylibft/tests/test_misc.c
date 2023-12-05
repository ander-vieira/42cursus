/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_misc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:53:02 by andeviei          #+#    #+#             */
/*   Updated: 2023/12/05 16:27:14 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

static void	test_abs(void)
{
	print_title("ABS");
	print_test("1", ft_abs(500) == 500, FALSE);
	print_test("2", ft_abs(-500) == 500, FALSE);
	print_test("3", ft_abs(0) == 0, FALSE);
	print_test("4", ft_abs(FT_INT_MAX) == FT_INT_MAX, TRUE);
}

static void	test_isspace(void)
{
	print_title("ISSPACE");
	print_test("1", ft_isspace(' '), FALSE);
	print_test("2", ft_isspace('\t'), FALSE);
	print_test("3", ft_isspace('\n'), FALSE);
	print_test("4", !ft_isspace('\0'), FALSE);
	print_test("5", !ft_isspace('5'), FALSE);
	print_test("6", !ft_isspace('F'), TRUE);
}

static void	test_memcpy(void)
{
	char	dst[10];
	char	src[10];
	int		i1;
	int		i2;

	print_title("MEMCPY");
	strcpy(src, "HOLA");
	ft_memcpy(dst, src, 10);
	print_test("1", !strcmp(dst, src), FALSE);
	i1 = 42;
	ft_memcpy(&i2, &i1, sizeof(int));
	print_test("2", i1 == i2, TRUE);
}

static void	test_parsenum(void)
{
	int		num;
	t_error	error;

	print_title("PARSENUM");
	num = ft_parsenum("500", BASE_DEC, &error);
	print_test("1", num == 500 && error == ERR_OK, FALSE);
	num = ft_parsenum("-88", BASE_DEC, &error);
	print_test("2", num == -88 && error == ERR_OK, FALSE);
	num = ft_parsenum("5f", BASE_HXL, &error);
	print_test("3", num == 95 && error == ERR_OK, FALSE);
	num = ft_parsenum("1A8", BASE_HXU, &error);
	print_test("4", num == 424 && error == ERR_OK, FALSE);
	num = ft_parsenum("555", "0", &error);
	print_test("5", num == 0 && error == ERR_PARSENUM_BADBASE, FALSE);
	num = ft_parsenum("A0", BASE_DEC, &error);
	print_test("5", num == 0 && error == ERR_PARSENUM_BADCHAR, FALSE);
	num = ft_parsenum("1.8", BASE_DEC, &error);
	print_test("6", num == 1 && error == ERR_PARSENUM_BADCHAR, FALSE);
	num = ft_parsenum("200000000000", BASE_DEC, &error);
	print_test("7", num == 0 && error == ERR_PARSENUM_OVERFLOW, TRUE);
}

void	test_misc(void)
{
	test_abs();
	test_isspace();
	test_memcpy();
	test_parsenum();
}
