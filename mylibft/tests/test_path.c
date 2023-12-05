/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 20:58:58 by andeviei          #+#    #+#             */
/*   Updated: 2023/12/05 21:37:42 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

static void	test_basename(void)
{
	char	*str;

	print_title("BASENAME");
	str = ft_basename("/bin/");
	print_test("1", !strcmp(str, "bin"), FALSE);
	free(str);
	str = ft_basename("/bin/bash");
	print_test("2", !strcmp(str, "bash"), FALSE);
	free(str);
	str = ft_basename("/etc/users//");
	print_test("3", !strcmp(str, "users"), FALSE);
	free(str);
	str = ft_basename("/");
	print_test("4", !strcmp(str, "/"), FALSE);
	free(str);
	str = ft_basename(".");
	print_test("5", !strcmp(str, "."), FALSE);
	free(str);
	str = ft_basename("");
	print_test("6", !strcmp(str, ""), TRUE);
	free(str);
}

static void	test_dirname(void)
{
	char	*str;

	print_title("DIRNAME");
	str = ft_dirname("/bin/");
	print_test("1", !strcmp(str, "/"), FALSE);
	free(str);
	str = ft_dirname("/bin/bash");
	print_test("2", !strcmp(str, "/bin"), FALSE);
	free(str);
	str = ft_dirname("/etc/users//");
	print_test("3", !strcmp(str, "/etc"), FALSE);
	free(str);
	str = ft_dirname("/");
	print_test("4", !strcmp(str, "/"), FALSE);
	free(str);
	str = ft_dirname(".");
	print_test("5", !strcmp(str, "."), FALSE);
	free(str);
	str = ft_dirname("");
	print_test("6", !strcmp(str, "."), TRUE);
	free(str);
}

static void	test_trimname(void)
{
	char	*str;

	print_title("TRIMNAME");
	str = ft_trimname("/bin/");
	print_test("1", !strcmp(str, "/bin"), FALSE);
	free(str);
	str = ft_trimname("/bin/bash");
	print_test("2", !strcmp(str, "/bin/bash"), FALSE);
	free(str);
	str = ft_trimname("/etc/users//");
	print_test("3", !strcmp(str, "/etc/users"), FALSE);
	free(str);
	str = ft_trimname("/");
	print_test("4", !strcmp(str, "/"), FALSE);
	free(str);
	str = ft_trimname(".");
	print_test("5", !strcmp(str, "."), FALSE);
	free(str);
	str = ft_trimname("");
	print_test("6", !strcmp(str, ""), TRUE);
	free(str);
}

void	test_path(void)
{
	test_basename();
	test_dirname();
	test_trimname();
}
