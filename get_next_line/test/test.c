/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:06:06 by andeviei          #+#    #+#             */
/*   Updated: 2023/09/19 19:49:09 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static char	**get_lines(const char *file)
{
	char	**strs;
	int		fd;
	size_t	len;
	size_t	i;

	fd = open(file, O_RDONLY);
	len = 0;
	while (get_next_line(fd) != NULL)
		len++;
	close(fd);
	strs = (char **)malloc(sizeof(char *) * (len + 1));
	if (strs == NULL)
		return (NULL);
	fd = open(file, O_RDONLY);
	i = 0;
	while (i < len)
	{
		strs[i] = get_next_line(fd);
		i++;
	}
	close(fd);
	strs[len] = NULL;
	return (strs);
}

void	free_lines(char **strs)
{
	size_t	i;

	if (strs != NULL)
	{
		i = 0;
		while (strs[i] != NULL)
		{
			free(strs[i]);
			i++;
		}
		free(strs);
	}
}

static void	test(void)
{
	char	**strs;

	strs = get_lines(TESTFILE_DIR"empty.txt");
	print_test("get_next_line 1", strs != NULL && strs[0] == NULL);
	free_lines(strs);
	strs = get_lines(TESTFILE_DIR"onechar.txt");
	print_test("get_next_line 2", strs != NULL && strs[0] != NULL
		&& !strcmp(strs[0], "p") && strs[1] == NULL);
	free_lines(strs);
	strs = get_lines(TESTFILE_DIR"oneline.txt");
	print_test("get_next_line 3", strs != NULL && strs[1] == NULL
		&& strs[0] != NULL && !strcmp(strs[0], "HELLO WORLD"));
	free_lines(strs);
	strs = get_lines(TESTFILE_DIR"multiline1.txt");
	print_test("get_next_line 4", strs != NULL && strs[2] == NULL
		&& strs[0] != NULL && !strcmp(strs[0], "HELLO\n")
		&& strs[1] != NULL && !strcmp(strs[1], "WORLD"));
	free_lines(strs);
	strs = get_lines(TESTFILE_DIR"multiline2.txt");
	print_test("get_next_line 5", strs != NULL && strs[3] == NULL
		&& strs[0] != NULL && !strcmp(strs[0], "HOLA\n")
		&& strs[1] != NULL && !strcmp(strs[1], "SOY\n")
		&& strs[2] != NULL && !strcmp(strs[2], "ANDER"));
	free_lines(strs);
}

int	main(void)
{
	test();
	print_all_tests();
	return (0);
}
