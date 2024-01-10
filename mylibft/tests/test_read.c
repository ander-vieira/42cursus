/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:53:52 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/10 17:02:30 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

void	test_readline1(void)
{
	t_fd	fd[2];
	char	*line;
	t_error	error;

	print_title("READLINE");
	pipe(fd);
	write(fd[1], "HOLA\nSOY ANDER\nY TU?", 20);
	close(fd[1]);
	line = ft_readline(fd[0], &error);
	print_test("1", !strcmp(line, "HOLA\n") && error == ERR_OK, FALSE);
	free(line);
	line = ft_readline(fd[0], &error);
	print_test("2", !strcmp(line, "SOY ANDER\n") && error == ERR_OK, FALSE);
	free(line);
	line = ft_readline(fd[0], &error);
	print_test("3", !strcmp(line, "Y TU?") && error == ERR_OK, FALSE);
	free(line);
	line = ft_readline(fd[0], &error);
	print_test("4", line == NULL && error == ERR_OK, FALSE);
	close(fd[0]);
	line = ft_readline(fd[0], &error);
	print_test("5", line == NULL && error == ERR_READ, FALSE);
	line = ft_readline(-1, &error);
	print_test("6", line == NULL && error == ERR_READ_BADFD, TRUE);
}

void	test_readfull(void)
{
	t_fd	fd[2];
	char	*full;
	t_error	error;

	print_title("READFULL");
	pipe(fd);
	write(fd[1], "HOLA\nSOY ANDER\nY TU?", 20);
	close(fd[1]);
	full = ft_readfull(fd[0], &error);
	print_test("1", !strcmp(full, "HOLA\nSOY ANDER\nY TU?") && error == ERR_OK, FALSE);
	free(full);
	full = ft_readfull(fd[0], &error);
	print_test("2", !strcmp(full, "") && error == ERR_OK, FALSE);
	close(fd[0]);
	full = ft_readfull(fd[0], &error);
	print_test("3", full == NULL && error == ERR_READ, FALSE);
	full = ft_readfull(-1, &error);
	print_test("4", full == NULL && error == ERR_READ_BADFD, TRUE);
}

void	test_read(void)
{
	test_readline1();
	test_readfull();
}
