/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 23:19:52 by andeviei          #+#    #+#             */
/*   Updated: 2024/02/06 16:01:41 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "../libft_int.h"

static char	**ft_strjoin_strs(size_t n, va_list args, size_t *len)
{
	char	**strs;
	size_t	i;

	strs = (char **)malloc(sizeof(char *) * n);
	if (strs == NULL)
		return (NULL);
	*len = 0;
	i = 0;
	while (i < n)
	{
		strs[i] = va_arg(args, char *);
		*len += ft_strlen(strs[i]);
		i++;
	}
	return (strs);
}

static void	ft_strjoin_copy(char *result, size_t n, char **strs)
{
	size_t	len;
	size_t	i;

	i = 0;
	while (i < n)
	{
		len = ft_strlen(strs[i]);
		ft_memcpy(result, strs[i], len);
		result += len;
		i++;
	}
	result[0] = '\0';
}

char	*ft_strjoin(size_t n, ...)
{
	va_list	args;
	char	*result;
	size_t	len;
	char	**strs;

	va_start(args, n);
	strs = ft_strjoin_strs(n, args, &len);
	if (strs == NULL)
		return (NULL);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (free(strs), NULL);
	ft_strjoin_copy(result, n, strs);
	return (free(strs), result);
}
