/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:53:52 by andeviei          #+#    #+#             */
/*   Updated: 2023/12/05 17:00:56 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

void	test_gnl1(void)
{
	t_fd	fd[2];
	char	*str;
	char	*line;
	t_error	error;

	str = "HOLA\nSOY ANDER\nY TU?";
	pipe(fd);
	write(fd[1], str, strlen(str));
	close(fd[1]);
	line = ft_gnl(fd[0], &error);
	print_test("1", !strcmp(line, "HOLA\n") && error == ERR_OK, FALSE);
	free(line);
	line = ft_gnl(fd[0], &error);
	print_test("2", !strcmp(line, "SOY ANDER\n") && error == ERR_OK, FALSE);
	free(line);
	line = ft_gnl(fd[0], &error);
	print_test("3", !strcmp(line, "Y TU?") && error == ERR_OK, FALSE);
	free(line);
	line = ft_gnl(fd[0], &error);
	print_test("4", line == NULL && error == ERR_OK, FALSE);
	close(fd[0]);
	line = ft_gnl(-1, &error);
	print_test("5", line == NULL && error == ERR_GNL_BADFD, TRUE);
}

void	test_gnl(void)
{
	print_title("GNL");
	test_gnl1();
}
