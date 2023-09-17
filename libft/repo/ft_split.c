/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ander <ander@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 15:39:38 by ander             #+#    #+#             */
/*   Updated: 2023/09/17 16:01:55 by ander            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**free_splits(char **split, size_t	n)
{
	size_t	i;

	if (split != NULL)
	{
		i = 0;
		while (i < n)
		{
			if (split[i] != NULL)
				free(split[i]);
			i++;
		}
		free(split);
	}
	return (NULL);
}

static size_t	count_splits(const char *str, char c)
{
	size_t	result;
	size_t	i;

	result = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c && (i == 0 || str[i - 1] == c))
			result++;
		i++;
	}
	return (result);
}

static size_t	get_split_len(char *str, char c)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0' && str[len] != c)
		len++;
	return (len);
}

static char	*get_split(const char *str, size_t *pos, char c)
{
	char	*result;
	size_t	result_l;

	while (str[*pos] == c)
		(*pos)++;
	result_l = get_split_len((char *)str + *pos, c);
	result = (char *)malloc(sizeof(char) * (result_l + 1));
	if (result == NULL)
		return (NULL);
	ft_memcpy(result, (char *)str + *pos, result_l);
	result[result_l] = '\0';
	*pos += result_l;
	return (result);
}

char	**ft_split(const char *str, char c)
{
	char	**split;
	size_t	split_n;
	size_t	i;
	size_t	pos;

	split_n = count_splits(str, c);
	split = (char **)malloc(sizeof(char *) * (split_n + 1));
	if (split == NULL)
		return (NULL);
	i = 0;
	pos = 0;
	while (i < split_n)
	{
		split[i] = get_split(str, &pos, c);
		if (split[i] == NULL)
			return (free_splits(split, i));
		i++;
	}
	split[split_n] = NULL;
	return (split);
}
