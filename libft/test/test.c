/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ander <ander@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 14:24:09 by ander             #+#    #+#             */
/*   Updated: 2023/09/18 00:25:54 by ander            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	main(void)
{
	test_is();
	test_to();
	test_mem();
	test_str();
	test_split();
	test_atoi();
	test_fd();
	test_bonus();
	print_all_tests();
	return (0);
}
