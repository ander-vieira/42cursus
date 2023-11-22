/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_fd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 09:08:56 by andeviei          #+#    #+#             */
/*   Updated: 2023/11/22 20:14:10 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	test_fd(void)
{
	int		fd[2];
	char	buf[4];

	pipe(fd);
	ft_putchar_fd('D', fd[1]);
	ft_putendl_fd("EEZ", fd[1]);
	ft_putnbr_fd(42, fd[1]);
	ft_putnbr_fd(-69, fd[1]);
	ft_putstr_fd("NUTS", fd[1]);
	close(fd[1]);
	read(fd[0], buf, 1);
	print_test("ft_putchar_fd", !memcmp(buf, "D", 1));
	read(fd[0], buf, 4);
	print_test("ft_putendl_fd", !memcmp(buf, "EEZ\n", 4));
	read(fd[0], buf, 2);
	print_test("ft_putnbr_fd 1", !memcmp(buf, "42", 2));
	read(fd[0], buf, 3);
	print_test("ft_putnbr_fd 2", !memcmp(buf, "-69", 3));
	read(fd[0], buf, 4);
	print_test("ft_putstr_fd", !memcmp(buf, "NUTS", 4));
	close(fd[0]);
}
