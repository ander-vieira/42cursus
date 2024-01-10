/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_str4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:07:57 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/10 18:37:25 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

static void	test_strsplit1(void)
{
	char	**split;

	print_title("STRSPLIT");
	split = ft_strsplit(" HOLA SOY ANDER  ", ' ');
	print_test("1", split != NULL, FALSE);
	print_test("2", split[0] != NULL && !strcmp(split[0], "HOLA"), FALSE);
	print_test("3", split[1] != NULL && !strcmp(split[1], "SOY"), FALSE);
	print_test("4", split[2] != NULL && !strcmp(split[2], "ANDER"), FALSE);
	print_test("5", split[3] == NULL, FALSE);
	ft_strsplit_free(split);
	split = ft_strsplit(" HOLA SOY ANDER  ", 'A');
	print_test("6", split != NULL, FALSE);
	print_test("7", split[0] != NULL && !strcmp(split[0], " HOL"), FALSE);
	print_test("8", split[1] != NULL && !strcmp(split[1], " SOY "), FALSE);
	print_test("9", split[2] != NULL && !strcmp(split[2], "NDER  "), FALSE);
	print_test("10", split[3] == NULL, FALSE);
	ft_strsplit_free(split);
}

static void	test_strsplit2(void)
{
	char	**split;

	split = ft_strsplit(" HOLA SOY ANDER  ", '\0');
	print_test("11", split != NULL, FALSE);
	print_test("12", split[0] != NULL
			&& !strcmp(split[0], " HOLA SOY ANDER  "), FALSE);
	print_test("13", split[1] == NULL, FALSE);
	ft_strsplit_free(split);
	split = ft_strsplit("     ", ' ');
	print_test("14", split != NULL, FALSE);
	print_test("15", split[0] == NULL, FALSE);
	ft_strsplit_free(split);
	split = ft_strsplit("", '\0');
	print_test("16", split != NULL, FALSE);
	print_test("17", split[0] == NULL, TRUE);
	ft_strsplit_free(split);
}

static t_bool	splitfun(char c, void *ctx)
{
	(void)ctx;
	return (c == ' ' || c == '-' || c == '\n');
}

static void	test_strsplit_magic(void)
{
	char	**split;

	print_title("STRSPLIT_MAGIC");
	split = ft_strsplit_magic(" -- HOLA\n SOY-ANDER -\n", &splitfun, NULL);
	print_test("1", split != NULL, FALSE);
	print_test("2", split[0] != NULL && !strcmp(split[0], "HOLA"), FALSE);
	print_test("3", split[1] != NULL && !strcmp(split[1], "SOY"), FALSE);
	print_test("4", split[2] != NULL && !strcmp(split[2], "ANDER"), FALSE);
	print_test("5", split[3] == NULL, TRUE);
	ft_strsplit_free(split);
}

void	test_str4(void)
{
	test_strsplit1();
	test_strsplit2();
	test_strsplit_magic();
}
