/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:35:41 by andeviei          #+#    #+#             */
/*   Updated: 2023/11/07 19:03:15 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	int		i;
	int		fd;
	char	c;

	while (read(STDIN_FILENO, &c, 1) > 0)
		write(STDOUT_FILENO, &c, 1);
	i = 0;
	while (i < argc)
	{
		printf("%s", argv[i]);
		i++;
	}
	return (0);
}