/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:09:54 by andeviei          #+#    #+#             */
/*   Updated: 2023/12/05 21:41:59 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

int	main(void)
{
	test_misc();
	test_str1();
	test_str2();
	test_str3();
	test_gnl();
	test_print();
	test_printf();
	test_path();
	return (print_all_tests());
}
