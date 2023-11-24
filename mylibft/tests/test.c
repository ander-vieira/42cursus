/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:27:47 by andeviei          #+#    #+#             */
/*   Updated: 2023/11/24 19:16:48 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "test.h"

int	main(int argc, char **argv)
{
	int	i;
	t_error error;

	i = 2;
	while (i < argc)
	{
		printf("%d: %d, %d\n", i, ft_parsenum(argv[i], argv[1], &error), error);
		i++;
	}
}