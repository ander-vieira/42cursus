/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_is.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 23:33:52 by andeviei          #+#    #+#             */
/*   Updated: 2023/09/18 17:46:55 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	test_is(void)
{
	print_test("ft_isalnum", ft_isalnum('C') && ft_isalnum('c')
		&& ft_isalnum('z') && ft_isalnum('4') && !ft_isalnum(';')
		&& !ft_isalnum(' ') && !ft_isalnum(2048 + 'c') && !ft_isalnum(2048));
	print_test("ft_isalpha", ft_isalpha('C') && ft_isalpha('c')
		&& ft_isalpha('z') && !ft_isalpha('4') && !ft_isalpha(';')
		&& !ft_isalpha(' ') && !ft_isalpha(2048 + 'c') && !ft_isalpha(2048));
	print_test("ft_isascii", ft_isascii('C') && ft_isascii('c')
		&& ft_isascii('z') && ft_isascii('4') && ft_isascii(';')
		&& ft_isascii(' ') && !ft_isascii(2048 + 'c') && !ft_isascii(2048));
	print_test("ft_isdigit", !ft_isdigit('C') && !ft_isdigit('c')
		&& !ft_isdigit('z') && ft_isdigit('4') && !ft_isdigit(';')
		&& !ft_isdigit(' ') && !ft_isdigit(2048 + '4') && !ft_isdigit(2048));
	print_test("ft_isprint", ft_isprint('C') && ft_isprint('c')
		&& ft_isprint('4') && !ft_isprint('\t') && ft_isprint(';')
		&& ft_isprint(' ') && !ft_isprint(2048 + 'c') && !ft_isprint(2048)
		&& !ft_isprint('\0'));
}
