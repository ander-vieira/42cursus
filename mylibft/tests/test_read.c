/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:53:52 by andeviei          #+#    #+#             */
/*   Updated: 2024/02/06 16:00:15 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

void	test_readline1(void)
{
	t_fd	fd[2];
	char	*line;

	print_title("READLINE");
	pipe(fd);
	write(fd[1], "HOLA\nSOY ANDER\nY TU?", 20);
	close(fd[1]);
	line = ft_readline(fd[0]);
	print_test("1",
		!strcmp(line, "HOLA\n") && ft_geterror() == FTERR_OK, FALSE);
	free(line);
	line = ft_readline(fd[0]);
	print_test("2",
		!strcmp(line, "SOY ANDER\n") && ft_geterror() == FTERR_OK, FALSE);
	free(line);
	line = ft_readline(fd[0]);
	print_test("3", !strcmp(line, "Y TU?") && ft_geterror() == FTERR_OK, FALSE);
	free(line);
	line = ft_readline(fd[0]);
	print_test("4", line == NULL && ft_geterror() == FTERR_OK, FALSE);
	close(fd[0]);
	line = ft_readline(fd[0]);
	print_test("5", line == NULL && ft_geterror() == FTERR_READ, FALSE);
	line = ft_readline(-1);
	print_test("6", line == NULL && ft_geterror() == FTERR_BADFD, TRUE);
}

void	test_readfull(void)
{
	t_fd	fd[2];
	char	*full;

	print_title("READFULL");
	pipe(fd);
	write(fd[1], "HOLA\nSOY ANDER\nY TU?", 20);
	close(fd[1]);
	full = ft_readfull(fd[0]);
	print_test("1", !strcmp(full, "HOLA\nSOY ANDER\nY TU?")
		&& ft_geterror() == FTERR_OK, FALSE);
	free(full);
	full = ft_readfull(fd[0]);
	print_test("2", !strcmp(full, "") && ft_geterror() == FTERR_OK, FALSE);
	free(full);
	close(fd[0]);
	full = ft_readfull(fd[0]);
	print_test("3", full == NULL && ft_geterror() == FTERR_READ, FALSE);
	full = ft_readfull(-1);
	print_test("4", full == NULL && ft_geterror() == FTERR_BADFD, TRUE);
}

void	test_read(void)
{
	test_readline1();
	test_readfull();
}
