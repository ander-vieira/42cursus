/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_to.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 23:33:52 by andeviei          #+#    #+#             */
/*   Updated: 2023/09/18 17:46:55 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	test_to(void)
{
	print_test("ft_tolower", ft_tolower('C') == 'c'
		&& ft_tolower('c') == 'c' && ft_tolower('4') == '4'
		&& ft_tolower(';') == ';' && ft_tolower(' ') == ' '
		&& ft_tolower('\t') == '\t');
	print_test("ft_toupper", ft_toupper('C') == 'C'
		&& ft_toupper('c') == 'C' && ft_toupper('4') == '4'
		&& ft_toupper(';') == ';' && ft_toupper(' ') == ' '
		&& ft_toupper('\t') == '\t');
}
