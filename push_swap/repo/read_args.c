/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:15:41 by andeviei          #+#    #+#             */
/*   Updated: 2024/02/29 20:34:49 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	exit_error(void)
{
	ft_printf(STDERR_FILENO, "Error\n");
	exit(EXIT_FAILURE);
}

static void	read_nums(t_stack *a, char **strs)
{
	int		num;
	size_t	len;
	size_t	i;

	len = 0;
	while (strs[len] != NULL)
		len++;
	*a = stack_init(len);
	i = 0;
	while (i < len)
	{
		num = ft_parsenum(strs[len - 1 - i], BASE_DEC);
		if (ft_geterror() != FTERR_OK || stack_has(*a, num))
			exit_error();
		stack_push(a, num);
		i++;
	}
}

t_stack	read_args(int argc, char **argv)
{
	char	**strs;
	t_stack	a;

	if (argc == 1)
		exit(EXIT_SUCCESS);
	if (argc == 2)
		strs = ft_strsplit_space(argv[1]);
	else
		strs = argv + 1;
	read_nums(&a, strs);
	if (argc == 2)
		ft_strsplit_free(strs);
	return (a);
}
