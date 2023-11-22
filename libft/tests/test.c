/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 14:24:09 by andeviei          #+#    #+#             */
/*   Updated: 2023/09/19 16:57:28 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	main(void)
{
	test_is();
	test_to();
	test_mem();
	test_str();
	test_striter();
	test_split();
	test_atoi();
	test_fd();
	test_lst();
	test_lstiter();
	print_all_tests();
	return (0);
}
