/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 15:04:46 by andeviei          #+#    #+#             */
/*   Updated: 2023/09/18 17:46:55 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static void	free_split(char **split)
{
	size_t	i;

	if (split != NULL)
	{
		i = 0;
		while (split[i] != NULL)
		{
			free(split[i]);
			i++;
		}
		free(split);
	}
}

void	test_split(void)
{
	char	**split;

	split = ft_split("", ' ');
	print_test("ft_split 1", split != NULL && split[0] == NULL);
	free_split(split);
	split = ft_split("     ", ' ');
	print_test("ft_split 2", split != NULL && split[0] == NULL);
	free_split(split);
	split = ft_split("c     g", ' ');
	print_test("ft_split 3", split != NULL
		&& split[0] != NULL && !strcmp(split[0], "c")
		&& split[1] != NULL && !strcmp(split[1], "g")
		&& split[2] == NULL);
	free_split(split);
	split = ft_split(" SPLIT DEEZ NUTS ", ' ');
	print_test("ft_split 4", split != NULL
		&& split[0] != NULL && !strcmp(split[0], "SPLIT")
		&& split[1] != NULL && !strcmp(split[1], "DEEZ")
		&& split[2] != NULL && !strcmp(split[2], "NUTS")
		&& split[3] == NULL);
	free_split(split);
}
