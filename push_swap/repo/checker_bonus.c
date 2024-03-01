/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 13:10:23 by andeviei          #+#    #+#             */
/*   Updated: 2024/03/01 14:22:23 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	exit_error(t_algo *algo)
{
	stack_free(&(algo->a));
	stack_free(&(algo->b));
	ft_printf(STDERR_FILENO, "Error\n");
	exit(EXIT_FAILURE);
}

static void	read_ops(t_algo *algo)
{
	char	*line;
	t_op	op;

	while (1)
	{
		line = ft_readline(STDIN_FILENO);
		if (ft_geterror() != FTERR_OK)
			exit_error(algo);
		if (line == NULL)
			break ;
		op = op_parse(line);
		if (op == OP_BAD)
			exit_error(algo);
		op_do(op, algo);
	}
}

int	main(int argc, char **argv)
{
	t_algo	algo;

	algo.a = read_args(argc, argv);
	algo.b = stack_init(algo.a.s);
	read_ops(&algo);
	if (stack_ordered(algo.a) && algo.b.l == 0)
		ft_printf(STDOUT_FILENO, "OK\n");
	else
		ft_printf(STDOUT_FILENO, "KO\n");
	return (EXIT_SUCCESS);
}
