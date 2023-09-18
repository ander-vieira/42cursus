/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 08:55:33 by andeviei          #+#    #+#             */
/*   Updated: 2023/09/18 08:55:33 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	test_atoi(void)
{
	char	*str;

	print_test("ft_atoi 1", ft_atoi("5") == 5 && ft_atoi("-5") == -5
		&& ft_atoi("0") == 0 && ft_atoi("") == 0 && ft_atoi("-") == 0
		&& ft_atoi(".") == 0 && ft_atoi("aa1") == 0);
	print_test("ft_atoi 2", ft_atoi("+1") == 1 && ft_atoi("++1") == 0
		&& ft_atoi("+-1") == 0 && ft_atoi("--1") == 0);
	print_test("ft_atoi 3", ft_atoi("100") == 100 && ft_atoi("-100") == -100
		&& ft_atoi("5171") == 5171 && ft_atoi("2147483647") == 2147483647
		&& ft_atoi("-2147483648") == -2147483648);
	str = ft_itoa(5);
	print_test("ft_itoa 1", str != NULL && !strcmp(str, "5"));
	free(str);
	str = ft_itoa(2147483647);
	print_test("ft_itoa 2", str != NULL && !strcmp(str, "2147483647"));
	free(str);
	str = ft_itoa(0);
	print_test("ft_itoa 3", str != NULL && !strcmp(str, "0"));
	free(str);
	str = ft_itoa(-2147483648);
	print_test("ft_itoa 4", str != NULL && !strcmp(str, "-2147483648"));
	free(str);
}
