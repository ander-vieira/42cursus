/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_striter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:48:38 by andeviei          #+#    #+#             */
/*   Updated: 2023/09/19 16:57:54 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static void	revcaesar(unsigned int i, char *c)
{
	i++;
	(*c)--;
}

static char	mapcaesar(unsigned int i, char c)
{
	i++;
	return (c + 1);
}

void	test_striter(void)
{
	char	*str;
	
	str = ft_strmapi("HELLO", &mapcaesar);
	print_test("ft_strmapi", str != NULL && !strcmp(str, "IFMMP"));
	ft_striteri(str, &revcaesar);
	print_test("ft_striteri", !strcmp(str, "HELLO"));
	free(str);
}