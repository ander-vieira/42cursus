/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basename_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:31:13 by andeviei          #+#    #+#             */
/*   Updated: 2023/11/26 14:43:44 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "../libft/libft.h"

int main(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		printf("%d: %s has basename %s\n", i, argv[i], ft_basename(argv[i]));
		i++;
	}
}