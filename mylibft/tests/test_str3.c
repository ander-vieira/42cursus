/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_str3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:43:50 by andeviei          #+#    #+#             */
/*   Updated: 2023/12/05 17:00:59 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

static void	test_strprefix(void)
{
	print_title("STRPREFIX");
	print_test("1", ft_strprefix("/bin/bash", "/bin"), FALSE);
	print_test("2", !ft_strprefix("/bin/bash", "bin"), FALSE);
	print_test("3", !ft_strprefix("/bin", "/bin/bash"), FALSE);
	print_test("4", ft_strprefix("/bin/bash", ""), TRUE);
}

static void	test_strrchr(void)
{
	print_title("STRRCHR");
	print_test("1", ft_strrchr("ABCDE", 'A') == 0, FALSE);
	print_test("2", ft_strrchr("AB DE", 'J') == -1, FALSE);
	print_test("3", ft_strrchr("AB DE", ' ') == 2, FALSE);
	print_test("4", ft_strrchr("A B C", ' ') == 3, FALSE);
	print_test("5", ft_strrchr("A B C", '\0') == -1, TRUE);
}

static void	test_strsub(void)
{
	char	*str;

	print_title("STRSUB");
	str = ft_strsub("HOLA SOY ANDER", 4);
	print_test("1", !strcmp(str, "HOLA"), FALSE);
	free(str);
	str = ft_strsub("HOLA SOY ANDER", 9);
	print_test("2", !strcmp(str, "HOLA SOY "), FALSE);
	free(str);
	str = ft_strsub("HOLA", 15);
	print_test("2", !strcmp(str, "HOLA"), FALSE);
	free(str);
	str = ft_strsub("HOLA", 0);
	print_test("2", !strcmp(str, ""), TRUE);
	free(str);
}

static void	test_strsuffix(void)
{
	print_title("STRSUFFIX");
	print_test("1", ft_strsuffix("maps.ber", ".ber"), FALSE);
	print_test("2", !ft_strsuffix("maps.ber", ".bbr"), FALSE);
	print_test("3", !ft_strsuffix(".ber", "maps.ber"), FALSE);
	print_test("4", ft_strsuffix("maps", ""), TRUE);
}

void	test_str3(void)
{
	test_strprefix();
	test_strrchr();
	test_strsub();
	test_strsuffix();
}
