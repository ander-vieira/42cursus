/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsenum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:44:37 by andeviei          #+#    #+#             */
/*   Updated: 2023/11/24 23:07:22 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_parsenum_validbase(char *base)
{
	size_t	base_len;
	size_t	i;

	base_len = ft_strlen(base);
	i = 0;
	while (i < base_len)
	{
		if (ft_strchr(base + i + 1, base[i]) != -1)
			return (0);
		i++;
	}
	return (base_len);
}

static t_bool	ft_parsenum_getsign(char *str, size_t *i)
{
	*i = 0;
	while (ft_isspace(str[*i]))
		*i += 1;
	if (str[*i] == '-')
		return (*i += 1, TRUE);
	else if (str[*i] == '+')
		return (*i += 1, FALSE);
	else
		return (FALSE);
}

static t_bool	ft_parsenum_overflow(int result,
	int pos, int base_len, t_bool sign)
{
	if (sign)
		return (result > ((int)FT_INT_MIN - pos) / base_len);
	else
		return (result > ((int)FT_INT_MAX - pos) / base_len);
}

int	ft_parsenum(char *str, char *base, t_error *error)
{
	int		result;
	int		base_len;
	int		pos;
	size_t	i;
	t_bool	sign;

	base_len = (int)ft_parsenum_validbase(base);
	if (base_len < 2)
		return (ft_seterror(error, ERR_PARSENUM_BADBASE), 0);
	result = 0;
	sign = ft_parsenum_getsign(str, &i);
	while (str[i] != '\0')
	{
		pos = ft_strchr(base, str[i]);
		if (pos == -1)
			return (ft_seterror(error, ERR_PARSENUM_BADCHAR), result);
		if (ft_parsenum_overflow(result, pos, base_len, sign))
			return (ft_seterror(error, ERR_PARSENUM_OVERFLOW), 0);
		result = result * base_len + pos;
		i++;
	}
	if (sign)
		result *= -1;
	return (ft_seterror(error, ERR_PARSENUM_OK), result);
}
