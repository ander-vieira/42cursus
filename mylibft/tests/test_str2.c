/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_str2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:31:37 by andeviei          #+#    #+#             */
/*   Updated: 2023/12/05 16:43:26 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

static void	test_strjoin(void)
{
	char	*str;

	print_title("STRJOIN");
	str = ft_strjoin(1, "AAA");
	print_test("1", !strcmp(str, "AAA"), FALSE);
	free(str);
	str = ft_strjoin(2, "AAA", " ");
	print_test("2", !strcmp(str, "AAA "), FALSE);
	free(str);
	str = ft_strjoin(3, "PEPITO", " Y ", " JOSE\n");
	print_test("3", !strcmp(str, "PEPITO Y  JOSE\n"), TRUE);
	free(str);
}

static void	test_strlen(void)
{
	print_title("STRLEN");
	print_test("1", ft_strlen("") == 0, FALSE);
	print_test("2", ft_strlen("HOLA MUNDO") == 10, FALSE);
	print_test("3", ft_strlen(NULL) == 0, FALSE);
	print_test("4", ft_strlen("PEPITO\nXD") == 9, TRUE);
}

static void	test_strnbrs(void)
{
	char	*str;

	print_title("STRNBRS");
	str = ft_strnbrs(5, BASE_DEC);
	print_test("1", !strcmp(str, "5"), FALSE);
	free(str);
	str = ft_strnbrs(-5, BASE_DEC);
	print_test("2", !strcmp(str, "-5"), FALSE);
	free(str);
	str = ft_strnbrs(100, BASE_HXL);
	print_test("3", !strcmp(str, "64"), FALSE);
	free(str);
	str = ft_strnbrs(-239, BASE_HXL);
	print_test("4", !strcmp(str, "-ef"), FALSE);
	free(str);
	str = ft_strnbrs(0, BASE_DEC);
	print_test("5", !strcmp(str, "0"), FALSE);
	free(str);
	str = ft_strnbrs(0, BASE_HXU);
	print_test("6", !strcmp(str, "0"), FALSE);
	free(str);
	str = ft_strnbrs(0, ",.");
	print_test("7", !strcmp(str, ","), TRUE);
	free(str);
}

static void	test_strnbru(void)
{
	char	*str;

	print_title("STRNBRU");
	str = ft_strnbru(5, BASE_DEC);
	print_test("1", !strcmp(str, "5"), FALSE);
	free(str);
	str = ft_strnbru(100, BASE_HXL);
	print_test("2", !strcmp(str, "64"), FALSE);
	free(str);
	str = ft_strnbru(239, BASE_HXL);
	print_test("3", !strcmp(str, "ef"), FALSE);
	free(str);
	str = ft_strnbru(168, BASE_HXU);
	print_test("4", !strcmp(str, "A8"), TRUE);
	free(str);
}

void	test_str2(void)
{
	test_strjoin();
	test_strlen();
	test_strnbrs();
	test_strnbru();
}
