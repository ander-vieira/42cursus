/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 19:38:24 by andeviei          #+#    #+#             */
/*   Updated: 2023/09/19 19:47:46 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	main(void)
{
	int		fd1;
	int		fd2;
	char	*str[7];

	fd1 = open(TESTFILE_DIR"multiline1.txt", O_RDONLY);
	fd2 = open(TESTFILE_DIR"multiline2.txt", O_RDONLY);
	str[0] = get_next_line(fd1);
	str[1] = get_next_line(fd2);
	str[2] = get_next_line(fd1);
	str[3] = get_next_line(fd2);
	str[4] = get_next_line(fd1);
	str[5] = get_next_line(fd2);
	str[6] = get_next_line(fd2);
	print_test("get_next_line bonus 1", str[4] == NULL
		&& str[0] != NULL && !strcmp(str[0], "HELLO\n")
		&& str[2] != NULL && !strcmp(str[2], "WORLD"));
	print_test("get_next_line bonus 2", str[6] == NULL
		&& str[1] != NULL && !strcmp(str[1], "HOLA\n")
		&& str[3] != NULL && !strcmp(str[3], "SOY\n")
		&& str[5] != NULL && !strcmp(str[5], "ANDER"));
	close(fd1);
	close(fd2);
	print_all_tests();
	return (0);
}
