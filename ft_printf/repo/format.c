/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 13:45:28 by andeviei          #+#    #+#             */
/*   Updated: 2023/09/15 13:45:28 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static ssize_t	count_direc(char *str)
{
	size_t	i;
	ssize_t	result;
	ssize_t	found;

	i = 0;
	result = 0;
	while (1)
	{
		found = pf_strfind(str + i, DIREC_START);
		if (found == -1)
			break ;
		i += found + 1;
		found = pf_strfind(str + i, DIREC_END);
		if (found == -1)
			return (-1);
		i += found + 1;
		result++;
	}
	return (result);
}

static t_format	*init_format(ssize_t direc_n)
{
	t_format	*result;

	result = (t_format *)malloc(sizeof(t_format));
	if (result == NULL || direc_n == -1)
		return (NULL);
	result->n = direc_n;
	result->s = (char **)malloc(sizeof(char *) * (direc_n + 1));
	result->d = NULL;
	if (direc_n > 0)
		result->d = (t_direc *)malloc(sizeof(t_direc) * direc_n);
	if (result->s == NULL || (direc_n > 0 && result->d == NULL))
	{
		free(result);
		return (NULL);
	}
	return (result);
}

void	free_format(t_format *format)
{
	if (format != NULL)
	{
		free_split(format->s, format->n);
		free_direc(format->d, format->n);
		free(format);
	}
}

t_format	*parse_format(char *str)
{
	t_format	*result;
	ssize_t		i;
	ssize_t		pos;
	char		loop;

	result = init_format(count_direc(str));
	if (result == NULL)
		return (NULL);
	i = 0;
	pos = 0;
	loop = 1;
	while (loop == 1)
	{
		loop = parse_split(result->s + i, str, &pos);
		if (loop == 1)
			loop = parse_direc(result->d + i, str, &pos);
		i++;
	}
	if (loop == -1)
	{
		free_format(result);
		return (NULL);
	}
	return (result);
}
