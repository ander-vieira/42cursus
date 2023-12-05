/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_str1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:06:28 by andeviei          #+#    #+#             */
/*   Updated: 2023/12/05 17:05:04 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

static void	test_strbuild(void)
{
	char	*str;

	print_title("STRBUILD");
	str = ft_strbuild('a', 3);
	print_test("1", !strcmp(str, "aaa"), FALSE);
	free(str);
	str = ft_strbuild(' ', 7);
	print_test("2", !strcmp(str, "       "), FALSE);
	free(str);
	str = ft_strbuild('.', 1);
	print_test("3", !strcmp(str, "."), FALSE);
	free(str);
	str = ft_strbuild('p', 0);
	print_test("4", !strcmp(str, ""), TRUE);
	free(str);
}

static void	test_strchr(void)
{
	print_title("STRCHR");
	print_test("1", ft_strchr("ABCDE", 'A') == 0, FALSE);
	print_test("2", ft_strchr("ABCDE", 'D') == 3, FALSE);
	print_test("3", ft_strchr("ABCDE", 'J') == -1, FALSE);
	print_test("4", ft_strchr("A B C", ' ') == 1, FALSE);
	print_test("5", ft_strchr("A B C", '\0') == -1, TRUE);
}

static void	test_strcmp(void)
{
	print_title("STRCMP");
	print_test("1", ft_strcmp("AAA", "AAA"), FALSE);
	print_test("2", !ft_strcmp("AAA", "AA"), FALSE);
	print_test("3", !ft_strcmp("AAA", "AAAA"), FALSE);
	print_test("4", !ft_strcmp("ABC", "BC"), FALSE);
	print_test("5", !ft_strcmp("HOLA SOY ANDER", "HOLA "), FALSE);
	print_test("6", ft_strcmp("HOLA SOY ANDER", "HOLA SOY ANDER"), FALSE);
	print_test("7", ft_strcmp("", ""), TRUE);
}

static void	test_strformat(void)
{
	char	*str;

	print_title("STRFORMAT");
	str = ft_strformat("HOL%c s%cy PE%s", 'A', 'o', "PITO\n");
	print_test("1", !strcmp(str, "HOLA soy PEPITO\n"), FALSE);
	free(str);
	str = ft_strformat("abs(%d) == %u, or in hex 0X%X", -57, 57, 57);
	print_test("2", !strcmp(str, "abs(-57) == 57, or in hex 0X39"), FALSE);
	free(str);
	str = ft_strformat("HOL%i, TEN %x AMIG%d %%\n", 111, 254, 0);
	print_test("3", !strcmp(str, "HOL111, TEN fe AMIG0 %\n"), FALSE);
	free(str);
	str = ft_strformat("%h OLA");
	print_test("4", !strcmp(str, "%h OLA"), TRUE);
	free(str);
}

void	test_str1(void)
{
	test_strbuild();
	test_strchr();
	test_strcmp();
	test_strformat();
}
