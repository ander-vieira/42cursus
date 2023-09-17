/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ander <ander@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 00:17:06 by ander             #+#    #+#             */
/*   Updated: 2023/09/18 00:48:21 by ander            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

#define BUF_SIZE 4

static char	mem_ischar(char *mem, char c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		if (mem[i] != c)
			return (0);
		i++;
	}
	return (1);
}

static void	test_calloc(void)
{
	char	*ptr;

	ptr = (char *)ft_calloc(3, 2);
	print_test("ft_calloc", ptr != NULL);
	free(ptr);
}

void	test_mem(void)
{
	char	buf[BUF_SIZE];

	ft_bzero(buf, BUF_SIZE);
	print_test("ft_bzero", mem_ischar(buf, '\0', BUF_SIZE));
	strcpy(buf, "HEY");
	print_test("ft_memchr", ft_memchr(buf, 'H', 3) == buf
		&& ft_memchr(buf, 'Y', 3) == buf + 2 && ft_memchr(buf, 'Y', 1) == NULL);
	print_test("ft_memcmp", !ft_memcmp(buf, "HEY", 4)
		&& ft_memcmp(buf, "HELLO", 4) && !ft_memcmp(buf, "HELLO", 2));
	print_test("ft_memcpy", ft_memcpy(buf, "ASD", 4) == buf
		&& !memcmp(buf, "ASD", 4));
	print_test("ft_memmove", ft_memmove(buf + 1, buf, 2) == buf + 1
		&& !memcmp(buf, "AAS", 4));
	print_test("ft_memset", ft_memset(buf, 'k', BUF_SIZE) == buf
		&& mem_ischar(buf, 'k', BUF_SIZE));
	test_calloc();
}
