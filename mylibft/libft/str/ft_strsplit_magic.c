/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_magic.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:21:19 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/10 18:36:14 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static size_t	ft_strsplit_count(char *s, t_f_char fun, void *ctx)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (!fun(s[i], ctx) && (i == 0 || fun(s[i - 1], ctx)))
			count++;
		i++;
	}
	return (count);
}

static char	*ft_strsplit_get(char *s, size_t *i, t_f_char fun, void *ctx)
{
	char	*word;
	size_t	len;

	len = 0;
	while (s[*i + len] != '\0' && !fun(s[*i + len], ctx))
		len++;
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (word == NULL)
		return (NULL);
	ft_memcpy(word, s + *i, len);
	word[len] = '\0';
	*i += len;
	return (word);
}

char	**ft_strsplit_magic(char *str, t_f_char fun, void *ctx)
{
	char	**split;
	size_t	count;
	size_t	i;
	size_t	j;

	count = ft_strsplit_count(str, fun, ctx);
	split = (char **)malloc(sizeof(char *) * (count + 1));
	if (split == NULL)
		return (NULL);
	j = 0;
	i = 0;
	while (str[i] != '\0' && fun(str[i], ctx))
		i++;
	while (str[i] != '\0')
	{
		split[j] = ft_strsplit_get(str, &i, fun, ctx);
		if (split[j] == NULL)
			return (ft_strsplit_free(split), NULL);
		j++;
		while (str[i] != '\0' && fun(str[i], ctx))
			i++;
	}
	split[count] = NULL;
	return (split);
}
