/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parseuint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:44:37 by andeviei          #+#    #+#             */
/*   Updated: 2024/03/01 01:37:26 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "../libft_int.h"

static size_t	ft_parseuint_validbase(char *base)
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

static void	ft_parseuint_spaces(char *str, size_t *i)
{
	*i = 0;
	while (ft_isspace(str[*i]))
		*i += 1;
}

static t_uint	ft_parseuint_getnum(char *str, char *base, size_t i)
{
	t_uint	result;
	t_uint	base_len;
	int		pos;
	t_bool	empty;

	base_len = (int)ft_parseuint_validbase(base);
	if (base_len < 2)
		return (ft_seterror(FTERR_PARSENUM_BADBASE), 0);
	empty = TRUE;
	result = 0;
	while (str[i] != '\0')
	{
		pos = ft_strchr(base, str[i]);
		if (pos == -1)
			return (ft_seterror(FTERR_PARSENUM_BADCHAR), result);
		if (result > (FT_INT_UINTMAX - pos) / base_len)
			return (ft_seterror(FTERR_PARSENUM_OVERFLOW), 0);
		result = result * base_len + pos;
		empty = FALSE;
		i++;
	}
	if (empty)
		return (ft_seterror(FTERR_PARSENUM_EMPTY), 0);
	return (ft_seterror(FTERR_OK), result);
}

t_uint	ft_parseuint(char *str, char *base)
{
	size_t	i;

	ft_parseuint_spaces(str, &i);
	return (ft_parseuint_getnum(str, base, i));
}
