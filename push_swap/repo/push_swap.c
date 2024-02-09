/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:56:06 by andeviei          #+#    #+#             */
/*   Updated: 2024/02/09 19:32:10 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*read_stack(int argc, char **argv)
{
	t_stack	*list;
	int		i;

	(void)argv;
	list = NULL;
	i = 1;
	while (i < argc)
	{
		stack_insert(&list, ft_parsenum(argv[i], BASE_DEC));
		i++;
	}
	return (list);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;

	stack_a = read_stack(argc, argv);
	stack_print(stack_a);
	stack_free(stack_a);
	return (EXIT_SUCCESS);
}
