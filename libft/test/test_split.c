/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ander <ander@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 15:04:46 by ander             #+#    #+#             */
/*   Updated: 2023/09/17 17:13:34 by ander            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

size_t	test_split(void)
{
	char	**split;
	size_t	result;

	split = ft_split(" SPLIT DEEZ NUTS ", ' ');
	result = (split != NULL
			&& split[0] != NULL && !strcmp(split[0], "SPLIT")
			&& split[1] != NULL && !strcmp(split[1], "DEEZ")
			&& split[2] != NULL && !strcmp(split[2], "NUTS")
			&& split[3] == NULL);
	print_test("ft_split", result);
	if (result)
		return (1);
	return (0);
}
