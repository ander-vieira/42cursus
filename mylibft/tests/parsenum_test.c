/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsenum_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:27:47 by andeviei          #+#    #+#             */
/*   Updated: 2023/11/25 17:41:41 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "../libft/libft.h"

int	main(int argc, char **argv)
{
	int		i;
	int		result;
	t_error error;

	i = 2;
	while (i < argc)
	{
		result = ft_parsenum(argv[i], argv[1], &error);
		printf("%d: %d, %d\n", i, result, error);
		i++;
	}
}