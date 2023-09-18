/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_fd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 09:08:56 by andeviei          #+#    #+#             */
/*   Updated: 2023/09/18 09:08:56 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	test_fd(void)
{
	int		fd;
	char	buf[15];

	fd = open(TMP_FD, O_WRONLY | O_CREAT | O_TRUNC);
	if (fd == -1)
		return ;
	ft_putchar_fd('D', fd);
	ft_putstr_fd("EEZ ", fd);
	ft_putendl_fd("NUTS", fd);
	ft_putnbr_fd(42, fd);
	ft_putnbr_fd(-69, fd);
	close(fd);
	fd = open(TMP_FD, O_RDONLY);
	if (fd == -1)
		return ;
	read(fd, &c, sizeof(char) * 15);
	close(fd);
	remove(TMP_FD);
	print_test("ft_putchar_fd", buf[0] == 'D');
	print_test("ft_putendl_fd", !memcmp(buf + 5, "NUTS\n", sizeof(char) * 5));
	print_test("ft_putnbr_fd 1", !memcmp(buf + 10, "42", sizeof(char) * 2));
	print_test("ft_putnbr_fd 2", !memcmp(buf + 12, "-69", sizeof(char) * 3));
	print_test("ft_putstr_fd", !memcmp(buf + 1, "EEZ ", sizeof(char) * 4));
}
