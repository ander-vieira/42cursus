/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ander <ander@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 01:41:30 by ander             #+#    #+#             */
/*   Updated: 2023/09/15 01:53:31 by ander            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	free_direc(t_direc *direc, ssize_t direc_n)
{
	ssize_t	i;

	if (direc != NULL)
	{
		i = 0;
		while (i < direc_n)
		{
			if (direc[i].flags != NULL)
				free(direc[i].flags);
			i++;
		}
		free(direc);
	}
}

static char	validate_direc_flags(char *flags, ssize_t flags_l)
{
	i = 0;
	while (i < flags_l)
	{
		if (!pf_strcontains(DIREC_FLAG, flags[i]))
			return (0);
		i++;
	}
	return (1);
}

char	parse_direc(t_direc *direc, char *str, ssize_t *pos)
{
	ssize_t	end_l;

	str += *pos;
	end_l = pf_strfind(str + 1, DIREC_END);
	if (!pf_strcontains(DIREC_START, str[0])
		|| end_l == -1 || !validate_direc_flags(str + 1, end_l))
		return (0);
	direc->flags = pf_strsub(str, 1, end_l);
	direc->end = str[end_l + 1];
	*pos += end_l + 1;
	return (1);
}
