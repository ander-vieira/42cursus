/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 01:15:02 by andeviei          #+#    #+#             */
/*   Updated: 2024/03/01 01:48:10 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "generator.h"

static t_gen	gen_init(size_t n)
{
	t_gen	gen;

	gen.n = n;
	gen.a = (int *)malloc(sizeof(int) * n);
	gen.i = 0;
	gen.m = -RANGE_MULT * n;
	gen.r = 2 * RANGE_MULT * n;
	return (gen);
}

static void	get_unique_number(t_gen gen)
{
	t_bool	ok;
	size_t	i;

	ok = FALSE;
	while (!ok)
	{
		gen.a[gen.i] = gen.m + rand() % gen.r;
		ok = TRUE;
		i = 0;
		while (i < gen.i)
		{
			if (gen.a[gen.i] == gen.a[i])
				ok = FALSE;
			i++;
		}
	}
}

static void	print_numbers(t_gen gen)
{
	srand(time(NULL));
	gen.i = 0;
	while (gen.i < gen.n)
	{
		get_unique_number(gen);
		ft_printf(STDOUT_FILENO, "%d", gen.a[gen.i]);
		if (gen.i == gen.n - 1)
			ft_printf(STDOUT_FILENO, "\n");
		else
			ft_printf(STDOUT_FILENO, " ");
		gen.i++;
	}
}

int	main(int argc, char **argv)
{
	t_gen	gen;
	size_t	n;

	if (argc != 2)
		return (ft_printf(STDERR_FILENO, "ERROR\n"), EXIT_FAILURE);
	n = ft_parseuint(argv[1], BASE_DEC);
	if (n == 0 || ft_geterror() != FTERR_OK)
		return (ft_printf(STDERR_FILENO, "ERROR\n"), EXIT_FAILURE);
	gen = gen_init(n);
	print_numbers(gen);
	free(gen.a);
}