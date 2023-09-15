/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 14:44:10 by andeviei          #+#    #+#             */
/*   Updated: 2023/09/15 14:44:10 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	free_split(char **split, ssize_t direc_n)
{
	ssize_t	i;

	if (split != NULL)
	{
		i = 0;
		while (i < direc_n + 1)
		{
			if (split[i] != NULL)
				free(split[i]);
			i++;
		}
		free(split);
	}
}

char	parse_split(char **split, char *str, ssize_t *pos)
{
	ssize_t	split_l;

	str += *pos;
	split_l = pf_strfind(str, DIREC_START);
	if (split_l == -1)
	{
		*split = pf_strsub(str, 0, pf_strlen(str));
		if (*split == NULL)
			return (-1);
		return (0);
	}
	*split = pf_strsub(str, 0, split_l);
	if (*split == NULL)
		return (-1);
	*pos += split_l;
	return (1);
}
