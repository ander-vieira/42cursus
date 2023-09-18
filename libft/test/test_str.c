/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 09:07:14 by andeviei          #+#    #+#             */
/*   Updated: 2023/09/18 09:07:14 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	caesar(unsigned int i, char *c)
{
	i++;
	(*c)++;
}

char	mapcaesar(unsigned int i, char c)
{
	i++;
	return (c + 1);
}

static void	test_str_2(void)
{
	char	str[6];

	strcpy(str, "HELLO");
	print_test("ft_strchr", ft_strchr(str, 'H') == str
		&& ft_strchr(str, 'L') == str + 2 && ft_strchr(str, 'F') == NULL);
	print_test("ft_strrchr", ft_strrchr(str, 'H') == str
		&& ft_strrchr(str, 'L') == str + 3 && ft_strrchr(str, 'F') == NULL);
	print_test("ft_strnstr 1", ft_strnstr(str, "H", 5) == str
		&& ft_strnstr(str, "L", 5) == str + 2 && ft_strnstr(str, "L", 2) == NULL
		&& ft_strnstr(str, "F", 5) == NULL && ft_strnstr(str, "", 5) == str);
	print_test("ft_strnstr 2", ft_strnstr(str, "LO", 5) == str + 3
		&& ft_strnstr(str, "LLL", 5) == NULL);
	print_test("ft_strnstr 3", ft_strnstr(NULL, NULL, 0) == NULL
		&& ft_strnstr(NULL, "", 5) == NULL
		&& ft_strnstr("HELLO", "H", 0) == NULL);
	ft_striteri(str, &caesar);
	print_test("ft_striteri", !strcmp(str, "JFMMP"));
}

static void	test_str_3(void)
{
	char	str[10];

	print_result("ft_strlcpy 1", ft_strlcpy(str, "HELLO", 10) == 5
		&& !strcmp(str, "HELLO"));
	print_result("ft_strlcpy 2", ft_strlcpy(str, "HELLO WORLD", 10) == 11
		&& !strcmp(str, "HELLO WOR"));
	strcpy(buf, "HELLO");
	print_result("ft_strlcat 1", ft_strlcat(str, " W", 10) == 7
		&& !strcmp(str, "HELLO W"));
	strcpy(buf, "HELLO");
	print_result("ft_strlcat 2", ft_strlcat(str, " WORLD", 10) == 11
		&& !strcmp(str, "HELLO WOR"));
	strcpy(buf, "HELLO");
	print_result("ft_strlcat 3", ft_strlcat(str, " WORLD HELLO", 10) == 17
		&& !strcmp(str, "HELLO WOR"));
}

void	test_str(void)
{
	char	*str;

	str = ft_strdup("HELLO");
	print_test("ft_strdup", str != NULL && !strcmp(str, "HELLO"));
	free(str);
	str = ft_strjoin("HELLO", "WORLD");
	print_test("ft_strjoin", !strcmp(str, "HELLOWORLD"));
	free(str);
	print_test("ft_strlen", ft_strlen("") == 0
		&& ft_strlen("HELLOWORLD\n") == 11);
	str = ft_strmapi("HELLO", &mapcaesar);
	print_test("ft_strmapi", str != NULL && !strcmp(str, "JFMMP"));
	free(str);
	print_test("ft_strncmp", ft_strncmp("HELLO", "HEY", 5)
		&& !ft_strncmp("HELLO", "HEY", 2) && ft_strncmp("HELLO", "WORLD")
		&& ft_strncmp("HELLO", ""));
	str = ft_strtrim("   HELLO WORLD  ");
	print_test("ft_strtrim", str != NULL && !strcmp(str, "HELLO WORLD"));
	free(str);
	str = ft_substr("HELLOWORLD", 3, 4);
	print_test("ft_substr", str != NULL && !strcmp(str, "LOWO"));
	free(str);
	test_str_2();
	test_str_3();
}
