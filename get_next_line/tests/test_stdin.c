/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stdin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 20:28:46 by andeviei          #+#    #+#             */
/*   Updated: 2023/11/22 21:22:41 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	main(void)
{
	char	*str;

	str = get_next_line(STDIN_FILENO);
	print_test("get_next_line stdin", str != NULL && !strcmp(str, "TEST STDIN\n"));
	free(str);
	print_all_tests();
}