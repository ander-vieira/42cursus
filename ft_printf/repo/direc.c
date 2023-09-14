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

ssize_t	count_direc(char *str)
{
	size_t	i;
	size_t	str_l;
	ssize_t	result;
	ssize_t	found;

	str_l = pf_strlen(str);
	i = 0;
	result = 0;
	while (i < str_l)
	{
		found = pf_strfind(str + i, DIREC_START);
		if (found == -1)
			break ;
		i += found + 1;
		found = pf_strfind(str + i, DIREC_END);
		if (found == -1)
			return (-1);
		result++;
	}
	return (result);
}

