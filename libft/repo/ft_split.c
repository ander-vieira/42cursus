/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 09:47:29 by andeviei          #+#    #+#             */
/*   Updated: 2023/09/16 20:45:15 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_splits(const char *str, char c)
{
	size_t	i;
	size_t	result;

	i = 0;
	result = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c && (i == 0 || str[i - 1] == c))
			result++;
		i++;
	}
	return (result);
}

static size_t	get_split(char **dest, const char *str, size_t start, char c)
{
	size_t	split_len;
	size_t	delim_len;

	split_len = 0;
	while (str[start + split_len] != '\0' && str[start + split_len] != c)
		split_len++;
	*dest = (char *)malloc(sizeof(char) * (split_len + 1));
	if (*dest != NULL)
	{
		ft_memcpy(*dest, str + start, split_len);
		(*dest)[split_len] = '\0';
	}
	delim_len = 0;
	while (str[start + split_len + delim_len] == c)
		delim_len++;
	return (split_len + delim_len);
}

char	**ft_split(const char *str, char c)
{
	char		**result;
	size_t		split_num;
	size_t		str_len;
	size_t		str_index;
	size_t		split_index;

	if (str == NULL)
		return (NULL);
	split_num = count_splits(str, c);
	str_len = ft_strlen(str);
	result = (char **)malloc(sizeof(char *) * (split_num + 1));
	if (result != NULL)
	{
		str_index = 0;
		split_index = 0;
		while (str[str_index] == c)
			str_index++;
		while (str_index < str_len && split_index < split_num)
		{
			str_index += get_split(result + split_index, str, str_index, c);
			split_index++;
		}
		result[split_num] = NULL;
	}
	return (result);
}
