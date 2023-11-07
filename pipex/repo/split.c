/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:34:47 by andeviei          #+#    #+#             */
/*   Updated: 2023/11/07 20:14:30 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	px_split_isspace(char c, int space)
{
	if (space != -1)
		return (c == (char)space);
	return (c == ' ' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v');
}

static size_t	px_split_count(char *str, int space)
{
	size_t	i;
	size_t	result;

	i = 0;
	result = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && px_split_isspace(str[i], space))
			i++;
		if (str[i] != '\0')
			result += 1;
		while (str[i] != '\0' && !px_split_isspace(str[i], space))
			i++;
	}
	return (result);
}

static char	*px_split_get(char **str, int space)
{
	char	*result;
	size_t	len;
	size_t	i;

	while (**str != '\0' && px_split_isspace(**str, space))
		*str += 1;
	len = 0;
	while ((*str)[len] != '\0' && !px_split_isspace((*str)[len], space))
		len++;
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		result[i] = (*str)[i];
		i++;
	}
	result[len] = '\0';
	*str += len;
	return (result);
}

char	**px_split(char *str, int space)
{
	char	**split;
	size_t	split_len;
	size_t	i;

	split_len = px_split_count(str, space);
	split = (char **)malloc(sizeof(char *) * (split_len + 1));
	if (split == NULL)
		return (NULL);
	i = 0;
	while (i < split_len)
	{
		split[i] = px_split_get(&str, space);
		if (split[i] == NULL)
			return (px_split_free(split), NULL);
		i++;
	}
	split[split_len] = NULL;
	return (split);
}

void	px_split_free(char **split)
{
	size_t	i;

	if (split != NULL)
	{
		i = 0;
		while (split[i] != NULL)
		{
			free(split[i]);
			i++;
		}
		free(split);
	}
}
