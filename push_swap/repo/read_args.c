/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:15:41 by andeviei          #+#    #+#             */
/*   Updated: 2024/03/06 16:11:34 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_bool	read_nums(t_stack *a, char **strs)
{
	int		num;
	size_t	len;
	size_t	i;

	len = 0;
	while (strs[len] != NULL)
		len++;
	if (len == 0)
		return (FALSE);
	*a = stack_init(len);
	i = 0;
	while (i < len)
	{
		num = ft_parseint(strs[len - 1 - i], BASE_DEC);
		if (ft_geterror() != FTERR_OK || stack_has(*a, num))
			return (FALSE);
		stack_push(a, num);
		i++;
	}
	return (TRUE);
}

t_stack	read_args(int argc, char **argv)
{
	char	**strs;
	t_stack	a;
	t_bool	ok;

	if (argc == 1)
		exit(EXIT_SUCCESS);
	if (argc == 2)
		strs = ft_strsplit_space(argv[1]);
	else
		strs = argv + 1;
	ok = read_nums(&a, strs);
	if (argc == 2)
		ft_strsplit_free(strs);
	if (!ok)
	{
		stack_free(&a);
		ft_printf(STDERR_FILENO, "Error\n");
		exit(EXIT_FAILURE);
	}
	return (a);
}
