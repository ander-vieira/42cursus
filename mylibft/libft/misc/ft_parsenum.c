/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsenum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:44:37 by andeviei          #+#    #+#             */
/*   Updated: 2024/02/13 15:54:43 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "../libft_int.h"

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

static t_bool	ft_parsenum_overflow(long result,
	long pos, long base_len, t_bool sign)
{
	if (sign)
		return (result > ((long)FT_INT_INTMAX + 1 - pos) / base_len);
	else
		return (result > ((long)FT_INT_INTMAX - pos) / base_len);
}

static int	ft_parsenum_getnum(char *str, char *base, size_t i, t_bool sign)
{
	int		result;
	int		base_len;
	int		pos;
	t_bool	empty;

	base_len = (int)ft_parsenum_validbase(base);
	if (base_len < 2)
		return (ft_seterror(FTERR_PARSENUM_BADBASE), 0);
	empty = TRUE;
	result = 0;
	while (str[i] != '\0')
	{
		pos = ft_strchr(base, str[i]);
		if (pos == -1)
			return (ft_seterror(FTERR_PARSENUM_BADCHAR), result);
		if (ft_parsenum_overflow(result, pos, base_len, sign))
			return (ft_seterror(FTERR_PARSENUM_OVERFLOW), 0);
		result = result * base_len + pos;
		empty = FALSE;
		i++;
	}
	if (empty)
		return (ft_seterror(FTERR_PARSENUM_EMPTY), 0);
	return (ft_seterror(FTERR_OK), result);
}

int	ft_parsenum(char *str, char *base)
{
	int		result;
	t_bool	sign;
	size_t	i;

	sign = ft_parsenum_getsign(str, &i);
	result = ft_parsenum_getnum(str, base, i, sign);
	if (sign)
		return (-result);
	return (result);
}
