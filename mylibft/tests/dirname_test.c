/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dirname_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:31:13 by andeviei          #+#    #+#             */
/*   Updated: 2023/11/26 17:23:11 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "../libft/libft.h"

int main(int argc, char **argv)
{
	int		i;
	char	*dirname;

	i = 1;
	while (i < argc)
	{
		dirname = ft_dirname(argv[i]);
		printf("%d: %s has dirname %s\n", i, argv[i], dirname);
		free(dirname);
		i++;
	}
}